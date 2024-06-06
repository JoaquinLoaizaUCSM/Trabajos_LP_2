#include <iostream>
using namespace std;

//Interfaz
class Reproductor{
    //En este caso todos van a manipular el objeto, por lo que ninguno tiene el const
    virtual void reproducir() = 0;
    virtual void pausar() = 0;
    virtual void detener() = 0;
    virtual void iniciar() = 0;
};


//Clase Derivada
class ReproductorMP3 : public Reproductor{
private:
    bool estado = 0;
    bool modo = 0;

public:
    void reproducir() override{
        if (estado == 1){
            cout << "La musica ya se encuentra en reproduccion..." << endl;
        } else{
            this -> estado = 1;
            cout << "Reproduciendo..." << endl;
        }
    }

    void pausar() override{
        if (estado == 0){
            cout << "La música ya esta pausada..." << endl;
        } else{
            this -> estado = 0;
            cout << "Pausando..." << endl;
        }
    }

    void iniciar() override{
        this -> modo = 1;
        cout << "Bienvenido..." << endl;
    }

    void detener() override{
        this -> modo = 0;
        cout << "Hasta pronto..." << endl;
    }

    friend ostream& operator <<(ostream& os, ReproductorMP3 R_01){
        if (R_01.estado == 0){
            os << "Estado del reproductor --> Pausado..." << endl;
            return os;
        } else {
            os << "Estado del reproductor --> Reproduciendo..." << endl;
            return os;
        }
    }

    bool &getmodo(){
        return modo;
    }
};

void menu_acciones_on_off(){
    cout << "1 - Encender Reproductor" << endl;
    cout << "0 - Terminar Programa" << endl;
}

void menu_acciones_rep(){
    cout << "1 - Reproducir" << endl;
    cout << "2 - Pausar" << endl;
    cout << "3 - Mostrar Estado" << endl;
    cout << "0 - Detener" << endl;
}


int verificar(int end){
    while (true){
        int num;
        cout << "-->";
        cin >> num;
        for (int i = 0; i < end; i++){
            if (i == num){
                return num;
            }
        }
    }
}



int main(){
    ReproductorMP3 Rep_01;
    bool ejecutor = true;

    while(ejecutor){

        int eleccion;
        menu_acciones_on_off();
        eleccion = verificar(2);
        if (eleccion == 1){
            Rep_01.iniciar();
        }else{
            return 0;
        }

        while (Rep_01.getmodo())
        {
            int election;
            menu_acciones_rep();
            election = verificar(4);
            if (election == 1){
                Rep_01.reproducir();
            } else if (election == 2){
                Rep_01.pausar();
            } else if (election == 3){
                cout << Rep_01;
            } else{
                Rep_01.detener();
            }
        }
    }
}
