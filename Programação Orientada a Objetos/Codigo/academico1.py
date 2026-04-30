from abc import ABC, abstractmethod

class Disciplina:
    def __init__(self, nomeDisc, cargaHoraria):
        self._nomeDisc = nomeDisc
        self._cargaHoraria = cargaHoraria
        
    @property
    def nomeDisc(self):
        return self._nomeDisc
    
    @property 
    def cargaHoraria(self):
        return self._cargaHoraria
               

class Pessoa(ABC):
    def __init__(self, nome, endereco, idade):
        self.__nome = nome
        self.__endereco = endereco
        self.__idade = idade 
        self._listaDisc = []

    @property
    def nome(self):
        return self.__nome

    @property
    def endereco(self):
        return self.__endereco

    @property
    def idade(self):
        return self.__idade
    
    @property
    def listaDisc(self):
        return self._listaDisc

    def insereDisc(self, discip):
        self._listaDisc.append(discip)

    @abstractmethod
    def printDescricao(self):
        pass

class Professor(Pessoa):
    def __init__(self, nome, endereco, idade, titulacao, listaDisc):
        super().__init__(nome, endereco, idade, listaDisc)
        self.__titulacao = titulacao

    @property
    def titulacao(self):
        return self.__titulacao

    def printDescricao(self):
        print('Nome: {}'.format(self.nome))
        print('Endereço: {}'.format(self.endereco))
        print('Idade: {}'.format(self.idade))
        print('Titulação: {}'.format(self.titulacao))  
        print('Disciplinas ministradas:')
        for disc in self.listaDisc:
            print(f'    - {disc.nomeDisc} - Carga Horária: {disc.cargaHoraria}')    

class Aluno(Pessoa):
    def __init__(self, nome, endereco, idade, curso, listaDisc):
        super().__init__(nome, endereco, idade, listaDisc)
        self.__curso = curso

    @property
    def curso(self):
        return self.__curso

    def printDescricao(self):
        print('Nome: {}'.format(self.nome))
        print('Endereço: {}'.format(self.endereco))
        print('Idade: {}'.format(self.idade))
        print('Curso: {}'.format(self.curso)) 
        print('Disciplinas cursadas:')  
        for disc in self.listaDisc:
            print(f'    - {disc.nomeDisc} - Carga Horária: {disc.cargaHoraria}')
        
        

if __name__ == "__main__":
    disc1 = Disciplina('Algoritmos em Grafos', 64)
    disc2 = Disciplina('Estruturas de Dados', 64)
    disc3 = Disciplina('Banco de Dados', 64)
    disc4 = Disciplina('Projeto Integrado', 32)
    
    
    prof = Professor('Joao','Av. BPS, 1303', 44, 'doutorado')
    prof.insereDisc(disc1)
    prof.insereDisc(disc2)
    prof.printDescricao()
    print()
    aluno = Aluno('Pedro','Av. Cesario Alvim, 205', 20, 'SIN')
    aluno.insereDisc(disc2)
    aluno.insereDisc(disc3)
    aluno.insereDisc(disc4)
    aluno.printDescricao()