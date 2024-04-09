from datetime import date


class Tarea:
    def __init__(self, titulo="", descripcion="", fecha_limite=date(2024,1,1)):
        self.titulo = titulo
        self.descripcion = descripcion
        self.fecha_limite = fecha_limite
        self.completada = False

    def completar_tarea(self):
        self.completada = True

    def mostrar_tiempo_restante(self):
        hoy = date.today()
        tiempo_restante = self.fecha_limite - hoy
        print(f"Tiempo restante: {tiempo_restante.days} dias")


class GestorTareas:
    def __init__(self):
        self.tareas = []

    def anexar_tarea(self, tarea):
        self.tareas.append(tarea)

    def mostrar_tareas_pendientes(self):
        print("Lista de tareas pendientes: ")
        for tarea in self.tareas:
            if not tarea.completada:
                print(f"- Titulo: {tarea.titulo}\n"
                      f"- Descripcion: {tarea.descripcion}\n"
                      f"- Fecha Limite: {tarea.fecha_limite}\n")

    def mostrar_tareas(self):
        print("Lista de tareas completados: ")
        for tarea in self.tareas:
            print(f"- Titulo: {tarea.titulo}\n"
                  f"- Descripcion: {tarea.descripcion}\n"
                  f"- Fecha Limite: {tarea.fecha_limite}\n"
                  f"- Completada: {tarea.completada}\n")

    def completar_tareas(self, tarea):
        tarea.completar_tarea()

    def eliminar_tareas(self, tarea):
        self.tareas.remove(tarea)

if __name__ == '__main__':
    tarea1 = Tarea("Viaje","viaje anual de vacaciones", date(2024,12,15))
    tarea2 = Tarea("Compras","Ir por la tarde a la tienda", date(2024,4,15))

    gestor = GestorTareas()
    gestor.anexar_tarea(tarea1)
    gestor.anexar_tarea(tarea2)

    # Mostrar tareas pendientes
    gestor.mostrar_tareas_pendientes()
    # Completar tarea1
    gestor.completar_tareas(tarea2)
    gestor.mostrar_tareas_pendientes()

    tarea1.mostrar_tiempo_restante()
