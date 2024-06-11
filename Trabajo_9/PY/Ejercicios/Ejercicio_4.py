class Personaje:
    def __init__(self, nombre, salud):
        self.nombre = nombre
        self.salud = salud

    def atacar(self, objetivo):
        return 0 
    def defender(self):
        return 0 

    def habilidad_especial(self):
        return 0 

class Guerrero(Personaje):
    def atacar(self, objetivo):
        daño = 15
        objetivo.salud -= daño
        return f"{self.nombre} ataca con su espada a {objetivo.nombre} causando {daño} de daño."

    def defender(self):
        self.salud += 8
        return f"{self.nombre} se cubre y recupera 8 puntos de salud"

    def habilidad_especial(self):
        self.salud += 20
        return f"{self.nombre} utiliza Furia Berserker y recupera 20 puntos de salud"

class Mago(Personaje):
    def atacar(self, objetivo):
        daño = 20
        objetivo.salud -= daño
        return f"{self.nombre} lanza un hechizo a {objetivo.nombre} causando {daño} de daño."

    def defender(self):
        self.salud += 8
        return f"{self.nombre}  se cubre y recupera 8 puntos de salud"

    def habilidad_especial(self):
        daño = 35
        return f"{self.nombre} utiliza bola du fogo y causa {daño} de daño a todos los enemigos"

class Arquero(Personaje):
    def atacar(self, objetivo):
        daño = 10
        objetivo.salud -= daño
        return f"{self.nombre} dispara una flecha a {objetivo.nombre} causando {daño} de daño"

    def defender(self):
        self.salud += 8
        return f"{self.nombre} se cubre y recupera 8 puntos de salud."

    def habilidad_especial(self):
        daño = 25
        return f"{self.nombre} utiliza lluvia de felchas causando {daño} de daño a todos los enemigos"


guerrero = Guerrero("Conan", 100)
mago = Mago("juja", 80)
arquero = Arquero("ojo halcon", 90)

print(guerrero.atacar(mago))
print(mago.defender())
print(arquero.habilidad_especial())
