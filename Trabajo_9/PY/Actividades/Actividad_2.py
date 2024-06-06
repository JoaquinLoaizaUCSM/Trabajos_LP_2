class Calculadora:
    def suma(self,a,b,c):
        print(f"El resultado es :{a+b+c}\n")

    def sumar(self, *args):
        if len(args) >= 2:
            if len(args) == 2:
                print(f"El resultado es :{args[0]+args[1]}\n")
            elif len(args) == 3:
                print(f"El resultado es :{args[0]+args[1]+args[2]}\n")

if __name__ == "__main__":
    calculadora = Calculadora()
    calculadora.suma(2,3,4)
    # En python no existe la sobrecarga de métodos
    #calculadora.suma(5,4)

    calculadora.sumar(2.4,3.4,4.5)
    calculadora.sumar("Buenas"," noches")
