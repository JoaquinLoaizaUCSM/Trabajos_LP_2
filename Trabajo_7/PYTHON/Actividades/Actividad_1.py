class Cliente:
    def __init__(self, nombre, telefono, correo, cuentaBancaria, monto):
        self.nombre = nombre
        self.telefono = telefono
        self.correo = correo
        self.cuentaBancaria = cuentaBancaria
        self.monto = monto

    def __str__(self):
        return (f"Cliente"
                f"  Nombre: {self.nombre}"
                f"  Telefono: {self.telefono}"
                f"  Correo: {self.correo}"
                f"  Cuenta Bancaria: {self.cuentaBancaria}"
                f"  Monto:  {self.monto}")


class ClienteSeguro(Cliente):
    def __init__(self, nombre, telefono, correo, cuentaBancaria, monto, clave):
        Cliente.__init__(nombre, telefono, correo, cuentaBancaria, monto)
        self.clave = clave
        self.claveEncriptada = ""

    def clave_encriptada(self):
        self.claveEncriptada = self.clave + "encriptado"



