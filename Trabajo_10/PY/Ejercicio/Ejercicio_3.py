class Ruta:
    def __init__(self, id_ruta, conductor, vel_vehiculo, num_dis=0):
        self.id_ruta = id_ruta
        self.conductor = conductor
        self.num_dis = num_dis
        self.distancias = []
        self.dis_total = 0
        self.t_estimado = 0
        self.vel_vehiculo = vel_vehiculo
        self.vehiculo = None

    def get_id(self):
        return self.id_ruta

    def vehiculo_asignado(self, vehicle):
        self.vehiculo = vehicle
        print(f"El vehículo de {self.conductor} eS: {vehicle}")

    def ingreso_rutas(self):
        for i in range(1, self.num_dis + 1):
            dis = float(input(f"Ingrese la distancia N°{i} a recorrer: "))
            self.distancias.append(dis)
            print("Ingresado correctamente.")

    def calculo_distancia(self):
        self.dis_total = sum(self.distancias)
        print(f"La distancia total a recorrer es de {self.dis_total} km.")

    def tiempo_entrega(self):
        self.t_estimado = self.dis_total / self.vel_vehiculo
        print(f"El tiempo de entrega estimado es de {self.t_estimado} horas.")

    def __str__(self):
        return (f"Datos ruta ID {self.id_ruta}:\n"
                f"Conductor       -> {self.conductor}\n"
                f"Vehículo        -> {self.vehiculo}\n"
                f"Velocidad       -> {self.vel_vehiculo}\n"
                f"Distancia       -> {self.dis_total}\n"
                f"Tiempo estimado -> {self.t_estimado}\n")


class GestionRutas:
    def __init__(self):
        self.rutas = []

    def agregar_ruta(self, ruta):
        self.rutas.append(ruta)

    def eliminar_ruta(self, id_ruta):
        for i in range(len(self.rutas)):
            if self.rutas[i].get_id() == id_ruta:
                del self.rutas[i]
                break

    def buscar_ruta(self, id_ruta):
        for ruta in self.rutas:
            if ruta.get_id() == id_ruta:
                print(ruta)

    def mostrar_rutas(self):
        for ruta in self.rutas:
            print(ruta)


if __name__ == "__main__":
    print("Esta actividad ya cumplía con lo solicitado al contar con un almacén de objetos de otra clase :)")

    # Creación de Rutas
    ruta1 = Ruta("001", "layconza", 120, 3)
    ruta1.vehiculo_asignado(1234)
    ruta1.ingreso_rutas()
    ruta1.calculo_distancia()
    ruta1.tiempo_entrega()

    ruta2 = Ruta("002", "Yhosfer", 5, 2)
    ruta2.vehiculo_asignado(5678)
    ruta2.ingreso_rutas()
    ruta2.calculo_distancia()
    ruta2.tiempo_entrega()

    # Ingreso de rutas
    gestion = GestionRutas()
    gestion.agregar_ruta(ruta1)
    gestion.agregar_ruta(ruta2)

    print("Rutas:")
    gestion.mostrar_rutas()

    # Eliminación de ruta
    gestion.eliminar_ruta("001")

    print("Rutas parte 2:")
    gestion.mostrar_rutas()
