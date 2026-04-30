from abc import ABC, abstractmethod

class Funcionario(ABC):
    def __init__(self, codigo, nome):
        self.__codigo = codigo
        self.__nome = nome
        self.__pontoMensalFunc = []
        
    @property
    def codigo(self):
        return self.__codigo
    
    @property
    def nome(self):
        return self.__nome
    
    @property
    def pontoMensalFunc(self):
        return self.__pontoMensalFunc
    
    def adicionaPonto(self, mes, ano, faltas, atrasos):
        ponto = PontoFunc(mes, ano, faltas, atrasos)
        self.pontoMensalFunc.append(ponto)
    
    def lancaFaltas(self, mes, ano, faltas):
        for ponto in self.pontoMensalFunc:
            if ponto.mes == mes and ponto.ano == ano:
                ponto.lancaFaltas(faltas)
                return
        # If no point found for this month/year, create a new one
        self.adicionaPonto(mes, ano, faltas, 0)
    
    def lancaAtrasos(self, mes, ano, atrasos):
        for ponto in self.pontoMensalFunc:
            if ponto.mes == mes and ponto.ano == ano:
                ponto.lancaAtrasos(atrasos)
                return
        # If no point found for this month/year, create a new one
        self.adicionaPonto(mes, ano, 0, atrasos)
    
    def imprimeFolha(self, mes, ano):
        salario = self.calculaSalario(mes, ano)
        bonus = self.calculaBonus(mes, ano)
        print(f'Código: {self.codigo}')
        print(f'Nome: {self.nome}')
        print(f'Salário Líquido: {salario:.2f}')
        print(f'Bônus: {bonus:.2f}')
    
    def getPonto(self, mes, ano):
        for ponto in self.pontoMensalFunc:
            if ponto.mes == mes and ponto.ano == ano:
                return ponto
        return None

    @abstractmethod
    def calculaSalario(self, mes, ano):
        pass
    
    @abstractmethod
    def calculaBonus(self, mes, ano):
        pass

class PontoFunc:
    def __init__(self, mes, ano, nroFaltas, nroAtrasos):
        self.__mes = mes
        self.__ano = ano
        self.__nroFaltas = nroFaltas
        self.__nroAtrasos = nroAtrasos
        
    @property
    def mes(self):
        return self.__mes
    
    @property
    def ano(self):
        return self.__ano
    
    @property
    def nroFaltas(self):
        return self.__nroFaltas
    
    @property
    def nroAtrasos(self):
        return self.__nroAtrasos
    
    def lancaFaltas(self, nroFaltas):
        self.__nroFaltas += nroFaltas
        
    def lancaAtrasos(self, nroAtrasos):
        self.__nroAtrasos += nroAtrasos

class Professor(Funcionario):
    def __init__(self, codigo, nome, titulacao, salarioHora, nroAulas):
        super().__init__(codigo, nome)
        self.__titulacao = titulacao
        self.__salarioHora = salarioHora
        self.__nroAulas = nroAulas
        
    @property
    def titulacao(self):
        return self.__titulacao
    
    @property
    def salarioHora(self):
        return self.__salarioHora
    
    @property
    def nroAulas(self):
        return self.__nroAulas
    
    def calculaSalario(self, mes, ano):
        ponto = self.getPonto(mes, ano)
        if ponto is None:
            return 0
        salarioProf = (self.salarioHora * self.nroAulas) - (self.salarioHora * ponto.nroFaltas)
        return salarioProf
    
    def calculaBonus(self, mes, ano):
        ponto = self.getPonto(mes, ano)
        if ponto is None:
            return 0
        if ponto.nroAtrasos < 10:
            bonusTec = self.calculaSalario(mes, ano) * (10 - ponto.nroAtrasos) / 100
        else:
            bonusTec = 0
        return bonusTec

class TecAdmin(Funcionario):
    def __init__(self, codigo, nome, funcao, salarioMensal):
        super().__init__(codigo, nome)
        self.__funcao = funcao
        self.__salarioMensal = salarioMensal
        
    @property
    def funcao(self):
        return self.__funcao    
        
    @property
    def salarioMensal(self):
        return self.__salarioMensal
    
    def calculaSalario(self, mes, ano):
        ponto = self.getPonto(mes, ano)
        if ponto is None:
            return 0
        salarioTec = self.salarioMensal - ((self.salarioMensal/30) * ponto.nroFaltas)
        return salarioTec
    
    def calculaBonus(self, mes, ano):
        ponto = self.getPonto(mes, ano)
        if ponto is None:
            return 0
        if ponto.nroAtrasos < 8:
            bonusTec = self.calculaSalario(mes, ano) * (8 - ponto.nroAtrasos) / 100
        else:
            bonusTec = 0
        return bonusTec

if __name__ == "__main__":
    funcionarios = []
    prof = Professor(1, "Joao", "Doutor", 45.35, 32)
    prof.adicionaPonto(4, 2021, 0, 0)
    prof.lancaFaltas(4, 2021, 2)
    prof.lancaAtrasos(4, 2021, 3)
    funcionarios.append(prof)
    tec = TecAdmin(2, "Pedro", "Analista Contabil", 3600)
    tec.adicionaPonto(4, 2021, 0, 0)
    tec.lancaFaltas(4, 2021, 3)
    tec.lancaAtrasos(4, 2021, 4)
    funcionarios.append(tec)
    for func in funcionarios:
        func.imprimeFolha(4, 2021)
        print()