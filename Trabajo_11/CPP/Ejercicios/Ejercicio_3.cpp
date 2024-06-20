#include <cereal/types/string.hpp>
#include <cereal/types/polymorphic.hpp>
#include <cereal/archives/binary.hpp>

#include <fstream>

class Persona {
private:
    std::string nombre;
    int edad;
    std::string direccion;

public:

    template<class Archive>
    void serialize(Archive & ar)
    {
        ar(nombre, edad, direccion);
    }
    // Constructor
    Persona(std::string nombre = "", int edad = 0, std::string direccion = "") : nombre(nombre), edad(edad), direccion(direccion) {}

    // Getters
    std::string getNombre() const { return nombre; }
    int getEdad() const { return edad; }
    std::string getDireccion() const { return direccion; }

    // Setters
    void setNombre(const std::string &nombre) { this->nombre = nombre; }
    void setEdad(int edad) { this->edad = edad; }
    void setDireccion(const std::string &direccion) { this->direccion = direccion; }
};

void serializePersona(const Persona &persona, const std::string &filename) {
    std::ofstream os(filename, std::ios::binary);
    cereal::BinaryOutputArchive archive(os);
    archive(persona);
}

void deserializeAndPrintPersona(const std::string &filename) {
    std::ifstream is(filename, std::ios::binary);
    cereal::BinaryInputArchive archive(is);
    Persona persona;
    archive(persona);

    std::cout << "Nombre: " << persona.getNombre() << std::endl;
    std::cout << "Edad: " << persona.getEdad() << std::endl;
    std::cout << "Direccion: " << persona.getDireccion() << std::endl;
}

int main() {
    Persona persona("John Doe", 30, "123 Main St");
    serializePersona(persona, "persona.bin");
    deserializeAndPrintPersona("persona.bin");
    return 0;
}