from abc import ABC, abstractmethod

class Empleado(ABC):
    @abstractmethod
    def calcularSalario(self):
        pass
    def despedir(self):
        pass

class EmpleadoCompleto(Empleado):
    def __init__(self, nombre, apellido, codigo, horasTrabajo, horasExtra, salario):
        self.estado = True #Contratado
        self.nombre = nombre
        self.nombre = nombre
        self.apellido = apellido
        self.codigo = codigo
        self.horasTrabajo = horasTrabajo
        self.horasExtra = horasExtra
        self.salario = salario

    def calcularSalario(self):
        print(f"Salario de {self.nombre}: {self.salario*se}")