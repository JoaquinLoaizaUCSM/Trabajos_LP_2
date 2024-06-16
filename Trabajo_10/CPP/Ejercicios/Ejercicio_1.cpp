#include <iostream>
using namespace std;
#include <vector>

template <typename T>
void ordenamiento_vector(vector<T> &vct) {
    int tamaño = vct.size();
    for (int i = 0; i < tamaño - 1; i++) {
        for (int j = 0; j < tamaño - i - 1; j++) {
            if (vct[j] > vct[j + 1]) {
                T temp = vct[j];
                vct[j] = vct[j + 1];
                vct[j + 1] = temp;
            }
        }
    }
}

int main() {
    vector<int> numeritos = {1, 2, 3, 0, 9, 7, 6};
    ordenamiento_vector(numeritos);

    for (int i = 0; i < numeritos.size(); i++){
        cout << numeritos[i];
    }

    cout << "\n" << endl;

    vector<float> numeritos_flotantes = {6.5, 45.7, 85.5, 2.2, 1.1, 2.5, 4.9};
    ordenamiento_vector(numeritos_flotantes);

    for (int i = 0; i < numeritos_flotantes.size(); i++){
        cout << numeritos_flotantes[i];
    }


    return 0;
};