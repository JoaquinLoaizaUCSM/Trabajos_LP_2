#include <iostream>
using namespace std;

template <typename T>
T dividir(T n1, T n2){
    try{
        if (n2 == 0){
            throw runtime_error("No se puede dividir entre 0.");
        }
        return n1/n2;
    } catch(runtime_error& e){
        cerr << "Error al ejecutar. " << e.what() << endl;
    }
}

int main(){
    dividir <int>(10,2);
    dividir <int>(22,0);
    dividir <float> (9.5,2.5);
    dividir <float>(10.50,0.0);
    return 0;
}
