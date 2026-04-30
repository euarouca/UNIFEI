class Animal:
    def __init__(self, nome, raca):
        self._nome = nome
        self._raca = raca
    
    @property
    def nome(self):
        return self._nome
    
    @property
    def raca(self):
        return self._raca
    
    def fazerCarinho(self):
        print(f'{self._nome} está recebendo carinho')
    
    
    
class Gato(Animal):
    def __init__(self, nome, raca):
        # super é usado para acessar a superclasse
        super().__init__(nome, raca)  
    
    def miar(self):
        print('Meow Meow')
        
class Cachorro(Animal):
    def __init__(self, nome, raca):
        # super é usado para acessar a superclasse
        super().__init__(nome, raca)
    
    def latir(self):
        print('Au AU')

if __name__ == "__main__":
    gato = Gato('Pietro', 'Siames')
    print(gato.nome)
    print(gato.raca)
    gato.miar()
    gato.fazerCarinho()
    print()
    cao = Cachorro('Cleitin', 'Viralata')
    print(cao.nome)
    print(cao.raca)
    cao.latir()
    cao.fazerCarinho()