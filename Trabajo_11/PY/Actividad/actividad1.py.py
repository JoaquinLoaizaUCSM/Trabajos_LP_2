def calculo_distancia(d1, d2, d3, d4):
    dt = (d2 - d1) + (d3 - d2) + (d4 - d3)
    print(f"La distancia total a recorrer es de {dt} km.")
    return dt

def tiempo_entrega(dt, vel):
    tiempo = dt / vel
    print(f"El tiempo de entrega estimado es de {tiempo} horas.")
    return tiempo

def realizar_informe():
    nI = int(input("Indique el número de informe: "))
    d1 = float(input("Ingrese la distancia n1: "))
    d2 = float(input("Ingrese la distancia n2: "))
    d3 = float(input("Ingrese la distancia n3: "))
    d4 = float(input("Ingrese la distancia n4: "))
    
    dt = calculo_distancia(d1, d2, d3, d4)
    
    vel = float(input("Ingrese la velocidad a la que se irá: "))
    tf = tiempo_entrega(dt, vel)
    
    print("Informe de ruta:")
    print(f"Distancia recorrida        -> {dt}")
    print(f"Velocidad del vehículo     -> {vel}")
    print(f"Tiempo estimado de entrega -> {tf}")
    
    return nI

def main():
    print("Ejecución con tipos de datos int:")
    n1 = realizar_informe()
    
    print("\nEjecución con tipos de datos float:")
    n2 = realizar_informe()

    print("\nEjecución con tipos de datos long:")
    n3 = realizar_informe()

if __name__ == "__main__":
    main()
