class Ruta:
    def __init__(self, id_ruta, conductor):
        self.id_ruta = id_ruta
        self.conductor = conductor

    def vehiculo_asignado(self, vehicle):
        print(f"El vehiculo de {self.conductor} sera : {vehicle}\n")

    def designar_horario(self):
        try:
            dis_total = float(input("Ingrese distancia total: "))
            if dis_total < 100:
                print("Día de entrega: jueves.")
            elif dis_total > 101.5:
                print("Día de entrega: viernes.")
            else:
                print("Día de entrega: indefinido.")
        except ValueError:
            print("valor inválido.")

    def ordenamiento_propinas(self, vector):
        tamano = len(vector)
        for i in range(tamano - 1):
            for j in range(tamano - i - 1):
                if vector[j] > vector[j + 1]:
                    vector[j], vector[j + 1] = vector[j + 1], vector[j]


ruta1 = Ruta("001", "Yhosfer")
ruta2 = Ruta("002", "Luis")

ruta1.vehiculo_asignado(5487)
ruta2.vehiculo_asignado("Todoterreno")

propinas = [3, 2, 40, 22, 55]
print(f"propinas : {propinas}")
ruta1.ordenamiento_propinas(propinas)
print(f"propinas ordenadas: {propinas}\n")

propinas_flotantes = [5.4, 6.5, 88.4, 7.5, 99.4, 99.2]
print(f"propinas : {propinas_flotantes}")
ruta2.ordenamiento_propinas(propinas_flotantes)
print(f"propinas ordenadas: {propinas_flotantes}\n")


ruta1.designar_horario()
ruta2.designar_horario()
