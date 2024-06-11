from abc import ABC, abstractmethod

class Empleado(ABC):
    @abstractmethod
    def calcularSalario(self):
        pass
    def agregarBono(self):
        pass

class Asalariados(Empleado):
    def __init__(self, nombre, apellido, codigo):
        self.nombre = nombre
        self.apellido = apellido
        self.codigo = codigo
        self.bono = 0
        self.salario = 1000

    def calcularSalario(self):
        print ("El salario del empleado es: ", self.salario+self.bono)

    def agregarBono(self):
        menuBono()
        op = 0
        while True:
            op = int(input("Ingrese una Opcion 1-4: "))
            if (op >0 and op <= 4):
                break
            else:
                print("Opcion invalida")
        if op == 1:
            self.bono = 0
        elif op == 2:
            self.bono = 50
        elif op == 3:
            self.bono = 100
        elif op == 4:
            self.bono = 200

    def __str__(self):
        return (f"Empleado {self.nombre} {self.apellido}\n"
                f"  Codigo {self.codigo}\n"
                f"  Salario s/{self.salario}\n"
                f"  Bono {self.bono}")

class PorHora(Empleado):
    def __init__(self, nombre, apellido, codigo, horas):
        self.nombre = nombre
        self.apellido = apellido
        self.codigo = codigo
        self.horas = horas
        self.bono = 0


    def calcularSalario(self):
        print(f"Salario: {self.horas*50}")

    def agregarBono(self):
        self.bono = self.horas*8

    def __str__(self):
        return (f"Empleado {self.nombre} {self.apellido}\n"
                f"  Codigo: {self.codigo}\n"
                f"  Salario: {self.horas*50}\n"
                f"  Bono: {self.bono}")

class Comisionista(Empleado):
    def __init__(self, nombre, apellido, codigo, nVentas):
        self.nombre = nombre
        self.apellido = apellido
        self.codigo = codigo
        self.nVentas = nVentas
        self.bono = 0

    def calcularSalario(self):
        return self.nVentas*50

    def agregarBono(self):
        self.bono = self.nVentas*8

    def __str__(self):
        print(f"Comisionista {self.nombre} {self.apellido}\n"
              f"  Codigo: {self.codigo}\n"
              f"  Ventas: {self.nVentas}\n"
              f"  Bono: {self.bono}\n"
              f"  Salario: {self.calcularSalario()}")


def menuBono():
    print("BONOS \n"
          " 1 -> s/0 \n"
          " 2 -> s/50 \n"
          " 3 -> s/100 \n"
          " 4 -> s/200 ")

def menuEmpleados():
    print("Empleados \n"
          "1 ->Asalariado\n"
          "2 -> PorHora\n"
          "3 -> Comisionista\n"
          "4 -> Salir")

if __name__ == "__main__":
    while True:
        menuEmpleados()
        op = int(input("Ingrese una opcion 1-4: "))
        if (op <=0 or op > 4):
            print("Opcion invalida")
            continue
        elif (op == 1):
            asalar = Asalariados("Juan","Martinez",341)
            asalar.agregarBono()
            print(asalar)
        elif (op == 2):
            por_hora = PorHora("Juan","Martinez",211,10)
            por_hora.agregarBono()
            print(por_hora)
        elif (op == 3):
            comisio = Comisionista("Juan","Martinez",341,200)
            comisio.agregarBono()
            print(comisio)
        else:
            print("Saliendo de Programa")
            break
