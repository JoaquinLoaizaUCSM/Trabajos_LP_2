class Persona:
    def __init__(self, nombre, salario, correo_electronico):
        self.nombre = nombre
        self.salario = salario
        self.correo_electronico = correo_electronico

    def set_correo_electronico(self, correo):
        self.correo_electronico = correo

    def get_correo_electronico(self):
        return self.correo_electronico



class Empleado(Persona):
    def __init__(self, nombre, salario, correo_electronico, departamento):
        Persona.__init__(self, nombre, salario, correo_electronico)
        self.departamento = departamento

    def __str__(self):
        return (f"Nombre: {self.nombre}\n"
                f"Salario: {self.salario}\n"
                f"Correo electronico: {self.correo_electronico}\n"
                f"Departamento: {self.departamento}\n")
    def __del__(self):
        print("Objeto Empleado Destruido")

class Cliente(Persona):
    def __init__(self, nombre, salario, correo_electronico, cuentaBancaria):
        Persona.__init__(self, nombre, salario, correo_electronico)
        self.cuentaBancaria = cuentaBancaria

    def __str__(self):
        return (f"Nombre: {self.nombre}\n"
                f"Salario: {self.salario}\n"
                f"Correo electronico: {self.correo_electronico}\n"
                f"Cuenta Bancaria: {self.cuentaBancaria}\n")

    def __del__(self):
        print("Objeto Cliente Destruido")

empleado = Empleado("Yhosfer", 5000, "yhosfer@gmail.com","123")
print("Acceso a correo electronico del empleado")
print(empleado.get_correo_electronico()+"\n")

print(empleado)

cliente = Cliente("Anderson", 10000, "anderson@gmail.com", "54322")
print("Acceso a correo electronico del Cliente")
print(cliente.get_correo_electronico()+"\n")
print(cliente)