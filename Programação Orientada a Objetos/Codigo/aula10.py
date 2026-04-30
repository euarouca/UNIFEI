from abc import ABC, abstractmethod

from datetime import date


class Conta:
    def __init__(self, nroConta, nome, saldo):
        self._nroConta = nroConta
        self._nome = nome
        self._saldo = saldo
        self._listaTransacoes = []
        
        
    def nroConta(self):
        pass
    
    def nome(self):
        pass
    
    def saldo(self):
        pass
    
    def listaTransacoes(self):
        pass 
    
    def deposito(self):
        pass
    
    def saque(self):
        pass
    
    @abstractmethod
    def imprimirExtrato(self):
        pass
    
    
class Corrente(Conta):
    def __init__(self, nroConta, nome, saldo, taxaMensal):
        super().__init__(nroConta, nome, saldo)
        self._taxaMensal = taxaMensal
        
    def imprimirExtrato(self):
        pass
    
    
class Limite(Conta):
    def __init__(self, nroConta, nome, saldo, valorLimite):
        super().__init__(nroConta, nome, saldo)
        self._valorLimite = valorLimite
        
    
    def saque(self):
        pass
    
    def imprimirExtrato(self):
        pass
    

class Poupanca(Conta):
    def __init__(self, nroConta, nome, saldo, diaAniversario):
        super().__init__(nroConta, nome, saldo)
        self._diaAniversario = diaAniversario
        
    def imprimirExtrato(self):
        pass
    

class Transacoes:
    def __init__(self, data, valor, descricao):
        self._data = data
        self._valor = valor
        self._descricao = descricao
        
    def data(self):
        pass
    
    def valor(self):
        pass
    
    def descricao(self):
        pass
    
    
from abc import ABC, abstractmethod
from datetime import datetime


# ─────────────────────────────────────────────────
#  CLASSE AUXILIAR: Transacao
# ─────────────────────────────────────────────────
class Transacao:
    """
    Representa uma única transação bancária.
    
    Atributos:
        data  (datetime) – instante em que a transação ocorreu (gerado automaticamente)
        valor (float)    – valor da transação; negativo = débito, positivo = crédito
        descricao (str)  – texto livre descrevendo a operação
    """
    def __init__(self, valor: float, descricao: str):
        self.data      = datetime.now()
        self.valor     = valor
        self.descricao = descricao

    def __str__(self) -> str:
        tipo = "Débito" if self.valor < 0 else "Crédito"
        return (
            f"  {self.data.strftime('%d/%m/%Y %H:%M')}"
            f"  {tipo:<7}"
            f"  R$ {abs(self.valor):>9.2f}"
            f"  {self.descricao}"
        )


# ─────────────────────────────────────────────────
#  CLASSE ABSTRATA BASE: Conta
# ─────────────────────────────────────────────────
class Conta(ABC):
    """
    Classe abstrata que define o contrato comum a todos os tipos de conta.

    Conceitos usados:
    • ABC / abstractmethod – impedem que Conta seja instanciada diretamente;
      obrigam as subclasses a implementar impExtrato().
    • Encapsulamento – atributos e lógica de depósito/saque centralizada aqui,
      evitando duplicação de código.
    • Template Method (padrão de projeto implícito) – _cabecalho_extrato() e
      _rodape_extrato() são métodos "auxiliares" chamados pelas subclasses em
      suas implementações de impExtrato(), mantendo a estrutura consistente.
    """

    def __init__(self, nroConta: int, nomeTitular: str, saldo: float):
        self.nroConta    = nroConta
        self.nomeTitular = nomeTitular
        self.saldo       = saldo
        self.transacoes: list[Transacao] = []   # lista de Transacao

    # ── Operações comuns ──────────────────────────

    def deposito(self, valor: float, descricao: str) -> None:
        """
        Realiza um depósito.
        Idêntico para todos os tipos de conta → implementado aqui (sem override).
        """
        self.saldo += valor
        self.transacoes.append(Transacao(valor, descricao))

    def saque(self, valor: float, descricao: str) -> bool:
        """
        Realiza um saque; 'valor' deve ser negativo (ex.: -500).
        Retorna True se o saque foi realizado, False se não há saldo suficiente.

        Regra padrão (ContaCorrente e ContaPoupanca):
            saldo + valor >= 0   →  saldo não pode ficar negativo.

        ContaLimite sobrescreve este método para permitir saldo negativo
        até o limite – ver sobrescrita na subclasse.
        """
        if self.saldo + valor >= 0:
            self.saldo += valor
            self.transacoes.append(Transacao(valor, descricao))
            return True
        return False

    # ── Helpers de extrato ────────────────────────

    def _cabecalho_extrato(self) -> None:
        """Imprime número da conta, nome e lista de transações."""
        linha = "=" * 58
        print(linha)
        print(f"  Conta nº : {self.nroConta}")
        print(f"  Titular  : {self.nomeTitular}")
        print("-" * 58)
        if self.transacoes:
            for t in self.transacoes:
                print(t)
        else:
            print("  (sem transações)")
        print("-" * 58)

    def _rodape_extrato(self) -> None:
        """Imprime o saldo final."""
        print(f"  Saldo atual : R$ {self.saldo:.2f}")
        print("=" * 58)

    # ── Método abstrato ───────────────────────────

    @abstractmethod
    def impExtrato(self) -> None:
        """
        Cada subclasse DEVE implementar este método.
        É aqui que entra o polimorfismo: ao chamar conta.impExtrato()
        na lista do main, Python executa a versão correta automaticamente.
        """
        pass


# ─────────────────────────────────────────────────
#  SUBCLASSE 1: ContaCorrente
# ─────────────────────────────────────────────────
class ContaCorrente(Conta):
    """
    Conta corrente comum.
    • Herda deposito() e saque() de Conta sem alterações.
    • Armazena a mensalidade cobrada pelo banco.
    • Implementa impExtrato() exibindo também a mensalidade.
    
    Parâmetros do construtor:
        nroConta    – número da conta
        nomeTitular – nome do correntista
        saldo       – saldo inicial
        mensalidade – taxa mensal de manutenção
    """

    def __init__(self, nroConta: int, nomeTitular: str,
                 saldo: float, mensalidade: float):
        super().__init__(nroConta, nomeTitular, saldo)  # chama __init__ de Conta
        self.mensalidade = mensalidade

    def impExtrato(self) -> None:
        self._cabecalho_extrato()
        print(f"  Mensalidade : R$ {self.mensalidade:.2f}")
        self._rodape_extrato()


# ─────────────────────────────────────────────────
#  SUBCLASSE 2: ContaLimite
# ─────────────────────────────────────────────────
class ContaLimite(Conta):
    """
    Conta corrente com limite de crédito.
    • Sobrescreve saque() para permitir saldo negativo até -limite.
    • Implementa impExtrato() exibindo também o limite disponível.

    Parâmetros do construtor:
        nroConta    – número da conta
        nomeTitular – nome do correntista
        saldo       – saldo inicial
        limite      – valor máximo que o saldo pode ficar negativo
    """

    def __init__(self, nroConta: int, nomeTitular: str,
                 saldo: float, limite: float):
        super().__init__(nroConta, nomeTitular, saldo)
        self.limite = limite

    # ── Sobrescrita (override) de saque ───────────
    def saque(self, valor: float, descricao: str) -> bool:
        """
        SOBRESCRITA do método saque() de Conta.
        
        Regra especial: o saldo pode ficar negativo, porém não pode ultrapassar
        o limite (ou seja, saldo + valor >= -limite).

        Exemplo:
            saldo = 100, limite = 500, valor = -400
            100 + (-400) = -300  →  -300 >= -500  ✓  saque permitido
            saldo passa a ser -300

        Polimorfismo em ação: quando chamamos cl.saque(...) onde cl é
        ContaLimite, Python executa ESTA versão, não a de Conta.
        """
        if self.saldo + valor >= -self.limite:
            self.saldo += valor
            self.transacoes.append(Transacao(valor, descricao))
            return True
        return False

    def impExtrato(self) -> None:
        self._cabecalho_extrato()
        print(f"  Limite      : R$ {self.limite:.2f}")
        self._rodape_extrato()


# ─────────────────────────────────────────────────
#  SUBCLASSE 3: ContaPoupanca
# ─────────────────────────────────────────────────
class ContaPoupanca(Conta):
    """
    Conta poupança.
    • Herda deposito() e saque() de Conta sem alterações
      (saldo não pode ficar negativo, sem mensalidade).
    • Armazena o dia do aniversário da conta (quando os juros são creditados).
    • Implementa impExtrato() exibindo também o dia do aniversário.

    Parâmetros do construtor:
        nroConta       – número da conta
        nomeTitular    – nome do correntista
        saldo          – saldo inicial
        diaAniversario – dia do mês em que os juros são creditados
    """

    def __init__(self, nroConta: int, nomeTitular: str,
                 saldo: float, diaAniversario: int):
        super().__init__(nroConta, nomeTitular, saldo)
        self.diaAniversario = diaAniversario

    def impExtrato(self) -> None:
        self._cabecalho_extrato()
        print(f"  Aniversário : dia {self.diaAniversario} de cada mês")
        self._rodape_extrato()


# ─────────────────────────────────────────────────
#  CÓDIGO DE TESTE (fornecido pelo enunciado)
# ─────────────────────────────────────────────────
if __name__ == "__main__":
    contas = []

    # ── ContaCorrente ─────────────────────────────
    cc = ContaCorrente(1111, 'João Silva', 0, 30)
    cc.deposito(1000, 'Crédito salário')
    if cc.saque(-500, 'Pagto energia'):
        print('Saque de R$500,00 na conta {}'.format(cc.nroConta))
    else:
        print('Falha ao realizar saque de R$500,00 na conta {}'.format(cc.nroConta))
    if cc.saque(-700, 'PIX'):
        print('Saque de R$700,00 na conta {}'.format(cc.nroConta))
    else:
        print('Falha ao realizar saque de R$700,00 na conta {}'.format(cc.nroConta))
    contas.append(cc)

    print()

    # ── ContaLimite ───────────────────────────────
    cl = ContaLimite(2222, 'Ana Souza', 0, 1000)
    cl.deposito(1500, 'Crédito salário')
    if cl.saque(-1200, 'Pagto boleto'):
        print('Saque de R$1200,00 na conta {}'.format(cl.nroConta))
    else:
        print('Falha ao realizar saque de R$1200,00 na conta {}'.format(cl.nroConta))
    if cl.saque(-500, 'PIX'):
        print('Saque de R$500,00 na conta {}'.format(cl.nroConta))
    else:
        print('Falha ao realizar saque de R$500,00 na conta {}'.format(cl.nroConta))
    contas.append(cl)

    print()

    # ── ContaPoupanca ─────────────────────────────
    cp = ContaPoupanca(3333, 'João Silva', 0, 10)
    cp.deposito(1200, 'Econominas')
    if cp.saque(-400, 'Resgate 1'):
        print('Saque de R$400,00 na conta {}'.format(cp.nroConta))
    else:
        print('Falha ao realizar saque de R$500,00 na conta {}'.format(cp.nroConta))
    if cp.saque(-300, 'Resgate 2'):
        print('Saque de R$300,00 na conta {}'.format(cp.nroConta))
    else:
        print('Falha ao realizar saque de R$700,00 na conta {}'.format(cp.nroConta))
    contas.append(cp)

    print()

    # ── Polimorfismo na lista ─────────────────────
    # Cada conta.impExtrato() executa a versão da sua própria subclasse,
    # mesmo que a variável 'conta' seja tipada como Conta (classe base).
    for conta in contas:
        conta.impExtrato()
        print()