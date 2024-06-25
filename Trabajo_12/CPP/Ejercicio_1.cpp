#include <iostream>
#include <list>
#include <algorithm>
#include <cctype>

using namespace std;


string to_upper(const string &str) {
    string result = str;
    transform(result.begin(), result.end(), result.begin(), ::toupper);
    return result;
}

int main() {
    list<string> palabras;
    string palabra;
    char continuar;

        cout << "Ingrese palabras (presione 'n' para terminar):" << endl;
    while (true) {
        cout << "Palabra: ";
        cin >> palabra;
        if (palabra == "n") break;
        palabras.push_back(palabra);
    }

    palabras.sort();


    cout << "Lista ordenada:" << endl;
    for (const auto &p : palabras) {
        cout << p << " ";
    }
    cout << endl;

    string palabra_a_contar;
    cout << "Ingrese la palabra a contar: ";
    cin >> palabra_a_contar;
    int count_palabra = count(palabras.begin(), palabras.end(), palabra_a_contar);
    cout << "La palabra '" << palabra_a_contar << "' aparece " << count_palabra << " veces en la lista." << endl;


    transform(palabras.begin(), palabras.end(), palabras.begin(), to_upper);


    cout << "Lista resultante en mayúsculas:" << endl;
    for (const auto &p : palabras) {
        cout << p << " ";
    }
    cout << endl;

    return 0;
}
