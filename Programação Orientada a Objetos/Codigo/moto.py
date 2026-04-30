class Motocicleta:
    def __init__(self, marca, cor, motorLigado):
        self._marca = marca
        self._cor = cor
        self._motorLigado = motorLigado
        
    
    def ligaMotor(self):
        if self._motorLigado:
            print('O motor já está ligado')
        else:
            pass