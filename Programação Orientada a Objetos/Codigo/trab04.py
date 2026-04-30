# Lucas Arouca Baldoni Mello Palhares
# 2024009210

from abc import ABC, abstractmethod

class Vendedor(ABC):
    def __init__(self, codigo, nome):
        self.__codigo = codigo
        self.__nome = nome
        self.__vendas = []

    @property
    def getCodigo(self):
        return self.__codigo
    
    @property
    def getNome(self):
        return self.__nome
    
    @property
    def getVendas(self):
        return self.__vendas
    
    def adicionaVenda(self, pCodImovel, pMes, pAno, pValor):
        venda = Venda(pCodImovel, pMes, pAno, pValor)
        self.__vendas.append(venda)

    @abstractmethod
    def getDados(self): 
        pass

    @abstractmethod
    def calculaRenda(self, pMes, pAno):
        pass

class Venda:
    def __init__(self, codImovel, mesVenda, anoVenda, valorVenda):
        self.__codImovel = codImovel
        self.__mesVenda = mesVenda
        self.__anoVenda = anoVenda
        self.__valorVenda = valorVenda

    @property
    def getCodImovel(self):  
        return self.__codImovel
    
    @property
    def getMesVenda(self):  
        return self.__mesVenda
    
    @property
    def getAnoVenda(self): 
        return self.__anoVenda
    
    @property
    def getValorVenda(self):  
        return self.__valorVenda

class Contratado(Vendedor):
    def __init__(self, codigo, nome, salarioFixo, nroCartTrabalho):
        super().__init__(codigo, nome)
        self.__nroCartTrabalho = nroCartTrabalho
        self.__salarioFixo = salarioFixo

    @property
    def getNroCartTrabalho(self):
        return self.__nroCartTrabalho
    
    @property
    def getSalarioFixo(self):  
        return self.__salarioFixo

    def getDados(self): 
        return f'Nome: {self.getNome} - Nro Carteira: {self.getNroCartTrabalho}'
    
    def calculaRenda(self, pMes, pAno):
        totalMes = 0
        for venda in self.getVendas:
            if venda.getMesVenda == pMes and venda.getAnoVenda == pAno:
                totalMes += venda.getValorVenda * 0.01
        return totalMes + self.getSalarioFixo

class Comissionado(Vendedor):
    def __init__(self, codigo, nome, nroCPF, comissao):
        super().__init__(codigo, nome)
        self.__comissao = comissao
        self.__nroCPF = nroCPF
    
    @property
    def getComissao(self):
        return self.__comissao
    
    @property
    def getNroCPF(self): 
        return self.__nroCPF
    
    def getDados(self):  
        return f'Nome: {self.getNome} - Nro CPF: {self.getNroCPF}'
    
    def calculaRenda(self, pMes, pAno):
        salarioTotal = 0
        for venda in self.getVendas:
            if venda.getMesVenda == pMes and venda.getAnoVenda == pAno:
                salarioTotal += venda.getValorVenda * (self.getComissao/100)
        return salarioTotal

if __name__ == '__main__':
    funcContratado = Contratado(1001, 'João da Silva', 2000, 1234)
    funcContratado.adicionaVenda(100, 3, 2022, 200000)
    funcContratado.adicionaVenda(101, 3, 2022, 300000)
    funcContratado.adicionaVenda(102, 4, 2022, 600000)
    funcComissionado = Comissionado(1002, 'José Santos', 4321, 5)
    funcComissionado.adicionaVenda(200, 3, 2022, 200000)
    funcComissionado.adicionaVenda(201, 3, 2022, 400000)
    funcComissionado.adicionaVenda(202, 4, 2022, 500000)
    listaFunc = [funcContratado, funcComissionado]
    for func in listaFunc:
        print(func.getDados())  
        print('Renda no mês 3 de 2022: ')
        print(func.calculaRenda(3, 2022))