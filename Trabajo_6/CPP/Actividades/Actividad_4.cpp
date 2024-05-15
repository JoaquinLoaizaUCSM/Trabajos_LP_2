#include <iostream>

using namespace std;

class Vector{
public:
    int x;
    int y;
    Vector(int x=0, int y=0){
        this->x=x;
        this->y=y;
    }

    Vector operator + (Vector otroVector){
        this->x += otroVector.x;
        this->y += otroVector.y;
        return {};
    };

    Vector operator - (Vector otroVector){
        this->x -= otroVector.x;
        this->y -= otroVector.y;
        return {};
    };
};

int main() {
    Vector coordenadas1 = Vector(2,4);
    Vector coordenadas2 = Vector(5,6);

    cout << "Operador -" << endl;
    coordenadas1-coordenadas2;

    cout << "Coordenadas " <<"x: "<< coordenadas1.x <<endl
         << "Coordenadas " <<"y: "<< coordenadas1.y << endl;

    cout << "Operador +" << endl;
    coordenadas1+coordenadas2;

    cout << "Coordenadas " <<"x: "<< coordenadas1.x <<endl
         << "Coordenadas " <<"y: "<< coordenadas1.y << endl;

    return 0;
}
// comentario commit y pushh