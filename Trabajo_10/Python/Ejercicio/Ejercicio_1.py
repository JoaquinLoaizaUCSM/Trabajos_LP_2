def ordenamiento_vector(vct):
    tamaño = len(vct)
    for i in range(tamaño - 1):
        for j in range(tamaño - i - 1):
            if vct[j] > vct[j + 1]:
                vct[j], vct[j + 1] = vct[j + 1], vct[j]


numeros = [1, 2, 3, 0, 9, 7, 6]
ordenamiento_vector(numeros)

print("lIstan del numeros enteros ordenada:")
print(numeros)
for numero in numeros:
    print("- ",numero)

numeritos_flotantes = [6.5, 45.7, 85.5, 2.2, 1.1, 2.5, 4.9]
ordenamiento_vector(numeritos_flotantes)
print("\n")

print("Lista de numeros flotantes ordenada:")
print(numeritos_flotantes)
for numero in numeritos_flotantes:
    print("- ",numero)
