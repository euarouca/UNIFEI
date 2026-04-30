from abc import ABC
from datetime import datetime

class Pessoa(ABC):

    def __init__(self, cpf, nome, fone):
        self.__cpf = cpf
        self.__nome = nome
        self.__fone = fone

    @property
    def cpf(self):
        return self.__cpf

    @property
    def nome(self):
        return self.__nome

    @property
    def fone(self):
        return self.__fone

class Funcionario(Pessoa):

    def __init__(self, cpf, nome, fone, salario, funcao):
        super().__init__(cpf, nome, fone)
        self.__salario = salario
        self.__funcao = funcao

    @property
    def salario(self):
        return self.__salario

    @property
    def funcao(self):
        return self.__funcao

class Cliente(Pessoa):

    def __init__(self, cpf, nome, fone, tipoCliente):
        super().__init__(cpf, nome, fone)
        self.__tipoCliente = tipoCliente

        self.__veiculos = []

    @property
    def tipoCliente(self):
        return self.__tipoCliente

    @property
    def veiculos(self):
        return self.__veiculos

    def addVeiculo(self, veiculo):
        self.__veiculos.append(veiculo)

class Veiculo:

    def __init__(self, placa, marca, modelo):
        self.__placa = placa
        self.__marca = marca
        self.__modelo = modelo

    @property
    def placa(self):
        return self.__placa

    @property
    def marca(self):
        return self.__marca

    @property
    def modelo(self):
        return self.__modelo

class Servico:

    def __init__(self, codigo, descricao, valor):
        self.__codigo = codigo
        self.__descricao = descricao
        self.__valor = valor

    @property
    def codigo(self):
        return self.__codigo

    @property
    def descricao(self):
        return self.__descricao

    @property
    def valor(self):
        return self.__valor

class OrdemServico:

    def __init__(self, cliente, veiculo, funcionario, nroOS, dataOS):
        self.__cliente = cliente
        self.__veiculo = veiculo
        self.__funcionario = funcionario
        self.__nroOS = nroOS
        self.__dataOS = dataOS

        self.__servicos = []

    @property
    def cliente(self):
        return self.__cliente

    @property
    def veiculo(self):
        return self.__veiculo

    @property
    def funcionario(self):
        return self.__funcionario

    @property
    def nroOS(self):
        return self.__nroOS

    @property
    def dataOS(self):
        return self.__dataOS

    @property
    def servicos(self):
        return self.__servicos

    def addServico(self, servico):
        self.__servicos.append(servico)

    def calculaValorOS(self):
        valor = 0
        for serv in self.__servicos:            
            valor += serv.valor
        if self.__cliente.tipoCliente == 'Vip':
            valor *= 0.9
        return valor
            
    def imprimeOS(self):
        print('Número OS: {}'.format(self.__nroOS))
        print('Data: {}'.format(self.__dataOS))
        print('Placa do veículo: {}'.format(self.__veiculo.placa))
        print('Nome proprietário: {}'.format(self.__cliente.nome))
        print('Func responsável: {}'.format(self.__funcionario.nome))
        print('---------------------------------')
        print('Cod. Serviço    Descrição')
        for serv in self.__servicos:
            print('{}\t\t{}'.format(serv.codigo, serv.descricao))            
        print('---------------------------------')
        print('Valor OS: {}'.format(self.calculaValorOS()))
        print('---------------------------------')

if __name__=="__main__": 
    func = Funcionario('999888776', 'Luis Silva', '98877665', 1800, 'Atendente')
    cliente = Cliente('888777655', 'João Souza', '9778855', 'Vip')
    veiculo = Veiculo('PKO1234', 'Chevrolet', 'Onix')
    cliente.addVeiculo(veiculo)
    serv1 = Servico(100, 'Alinhamento direçao', 70)
    serv2 = Servico(101, 'Balanceamento rodas', 80)
    serv3 = Servico(102, 'Troca de óleo', 120)
    os = OrdemServico(cliente, veiculo, func, 1001, datetime.now())
    os.addServico(serv1)
    os.addServico(serv2)
    os.addServico(serv3)
    os.imprimeOS()




