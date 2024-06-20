def divide(a, b):
    if b == 0:
        pass
    return a / b

def procesar_divisiones(valores):
    for a, b in valores:
        try:
            resultado = divide(a, b)
            print(f"{a} dividido por {b} es {resultado}")
        except:
            print(f"Error al dividir {a} por {b}")


valores = [
    (10, 2),
    (10, 0), 
    (5, -1), 
    (0, 5)   
]

procesar_divisiones(valores)
