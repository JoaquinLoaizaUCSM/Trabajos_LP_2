def leer_archivo():
    nombre_archivo = input("ingrese el nombre del archivo")
    try:
        with open(nombre_archivo, 'r') as archivo:
            contenido = archivo.read()
            print("Contenido del archivo:")
            print(contenido)
    except FileNotFoundError:
        print("Error: El archivo no existe.")
    except:
        print(f"Ha ocurrido un error")

leer_archivo()
