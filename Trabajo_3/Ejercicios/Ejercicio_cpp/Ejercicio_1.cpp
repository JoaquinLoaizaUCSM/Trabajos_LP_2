#include <iostream>
#include <vector>
using namespace std;

//Se declara la clase libro para evitar error por conexion con clase autor
class Libro;


//01
class Autor {
private:
    string nombre;
    string nacionalidad;
    vector<Libro*> librosEscritos;

public:
    //Constructor
    Autor(string name = "Grossman", string nacionality = "Peruano"){
        this -> nombre = name;
        this -> nacionalidad = nacionality;
    }

    //Getter, Setters
    string get_nombre() {
        return nombre;
    }

    string get_nacionalidad() {
        return nacionalidad;
    }

    void agregar_libro(Libro* libro) {
        librosEscritos.push_back(libro);
    }

    //Tanto esta como la de la clase usuarios nos servira para retornar los vectores y poder imprimirlos en el main.
    vector<Libro*> get_lista(){
        return librosEscritos;
    }
};

//02
class Usuario {
private:
    string nombre;
    string direccion;
    string telefono;
    vector<Libro*> librosPrestados;

public:
    Usuario(string name = "Joaquin", string direction = "Cayma", string cell = "123"){
        this -> nombre = name;
        this -> direccion = direction;
        this -> telefono = cell;
    }

    string get_nombre() {
        return nombre;
    }

    string get_direccion() {
        return direccion;
    }

    string get_telefono() {
        return telefono;
    }

    //Sirve para tener un vector de libros prestados por usuario
    void agregarLibroPrestado(Libro* libro) {
        librosPrestados.push_back(libro);
    }

    vector<Libro*> get_lista(){
        return librosPrestados;
    }

};

class Prestamo {
private:
    Usuario usuario;
    Libro* libro;
    string F_Prestamo;
    string F_Devolucion;

public:
    Prestamo(Usuario user, Libro* book, string Prestamo_F = "29/12/2005", string Devolucion_F = "13/04/2024"){
        this -> usuario = user;
        this -> libro = book;
        this -> F_Prestamo = Prestamo_F;
        this -> F_Devolucion = Devolucion_F;
    }
};


class Libro {
private:
    string ISBN;
    string titulo;
    string fecha_publi;
    int stock;
    Autor* autor;

public:
    Libro(string IS = "01", string title = "Hola", string date = "29/12/2005", int cant = 0, Autor* author = nullptr) {
        this -> ISBN = IS;
        this -> titulo = title;
        this -> fecha_publi = date;
        this -> stock = cant;
        this -> autor = author;
    }

    string get_ISBN() {
        return ISBN;
    }

    string get_titulo() {
        return titulo;
    }

    string get_AñoPublicacion() {
        return fecha_publi;
    }

    int get_Cantidad() {
        return stock;
    }

    Autor* get_Autor() {
        return autor;
    }
};

int main() {
    // Creamos autores:
    Autor Cervantes("Miguel de Cervantes", "Español");
    Autor Angel("Angel Zorrilla", "Haitiano");

    // Creamos libritos:
    Libro Pinocho("1234567890", "Pinocho", "-154", 18, &Cervantes);
    Libro Caperucita("0987654321", "Caperucita roja", "1232", 58, &Angel);

    // Agregar libros a los autores:
    Cervantes.agregar_libro(&Pinocho);
    Angel.agregar_libro(&Caperucita);

    // Creamos usuarios:
    Usuario Gras("Grossman", "Wa", "1234567890");
    Usuario Pedro("Pedro Pedro Pedro Pedro pe", "URSS", "0987654321");

    // Agregamos libros a los usuarios:
    Gras.agregarLibroPrestado(&Pinocho);
    Pedro.agregarLibroPrestado(&Caperucita);

    // Creamos prestamos:
    Prestamo prestamo_1(Gras, &Pinocho, "28/10/2000", "29/12/2020");
    Prestamo prestamo_2(Pedro, &Caperucita,"25/11/1995","14/05/1111");

    // Asignamos a un vector los libros de los autores para posteriormente imprimirlos:
    vector<Libro*> librosCervantes = Cervantes.get_lista();
    vector<Libro*> librosAngel = Angel.get_lista();

    cout << "Libros escritos por " << Cervantes.get_nombre() << ":" << endl;
    for (Libro* libro : librosCervantes) {
        cout << "-" << libro->get_titulo() << endl;
    }

    cout << "Libros escritos por " << Angel.get_nombre() << ":" << endl;
    for (Libro* libro : librosAngel) {
        cout << "-" << libro->get_titulo() << endl;
    }

    // Asignamos a un vector los libros prestados por cada usuario para imprimirlos:
    vector<Libro*> librosGras = Gras.get_lista();
    vector<Libro*> librosPedro = Pedro.get_lista();

    cout << "Libros prestados a " << Gras.get_nombre() << ":" << endl;
    for (Libro* libro : librosGras) {
        cout << "- " << libro->get_titulo() << endl;
    }

    cout << "Libros prestados a " << Pedro.get_nombre() << ":" << endl;
    for (Libro* libro : librosPedro) {
        cout << "- " << libro->get_titulo() << endl;
    }
    
    return 0;
}

//pedro pedro pedro pedro pe