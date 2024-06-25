#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

class Contact {
public:
    string nombre;
    string phone;
    string email;

    Contact(const string& nombre, const string& phone, const string& email)
        : nombre(nombre), phone(phone), email(email) {}

    // Sobrecarga del operador < para permitir la ordenación alfabética
    bool operator<(const Contact& other) const {
        return nombre < other.nombre;
    }
};

class ContactManager {
private:
    vector<Contact> contacts;

public:
    void addContact(const string& nombre, const string& phone, const string& email) {
        contacts.emplace_back(nombre, phone, email);
    }

    Contact* searchContact(const string& nombre) {
        auto it = find_if(contacts.begin(), contacts.end(), [&](const Contact& c) {
            return c.nombre == nombre;
        });

        if (it != contacts.end()) {
            return &(*it);
        } else {
            return nullptr;
        }
    }

    void updateContact(const string& nombre, const string& newPhone, const string& newEmail) {
        Contact* contact = searchContact(nombre);
        if (contact) {
            contact->phone = newPhone;
            contact->email = newEmail;
        } else {
            cout << "Contacto no encontrado.\n";
        }
    }

    void showContacts() const {
        vector<Contact> sortedContacts = contacts;
        sort(sortedContacts.begin(), sortedContacts.end());

        for (const auto& contact : sortedContacts) {
            cout << "Nombre: " << contact.name << "\n";
            cout << "Teléfono: " << contact.phone << "\n";
            cout << "Correo electrónico: " << contact.email << "\n";
            cout << "-----------------------\n";
        }
    }
};

void showMenu() {
    cout << "1. Agregar contacto\n";
    cout << "2. Buscar contacto\n";
    cout << "3. Actualizar contacto\n";
    cout << "4. Mostrar lista de contactos\n";
    cout << "5. Salir\n";
}

int main() {
    ContactManager manager;
    int option;
    string name, phone, email;

    do {
        showMenu();
        cout << "Seleccione una opción: ";
        cin >> option;
        cin.ignore(); // Ignorar el salto de línea restante en el búfer

        switch (option) {
        case 1:
            cout << "Ingrese nombre: ";
            getline(cin, nombre);
            cout << "Ingrese teléfono: ";
            getline(cin, phone);
            cout << "Ingrese correo electrónico: ";
            getline(cin, email);
            manager.addContact(nombre, phone, email);
            break;
        case 2:
            cout << "Ingrese nombre: ";
            getline(cin, nombre);
            if (Contact* contact = manager.searchContact(nombre)) {
                cout << "Nombre: " << contact->nombre << "\n";
                cout << "Teléfono: " << contact->phone << "\n";
                cout << "Correo electrónico: " << contact->email << "\n";
            } else {
                cout << "Contacto no encontrado.\n";
            }
            break;
        case 3:
            cout << "Ingrese nombre: ";
            getline(cin, nombre);
            cout << "Ingrese nuevo teléfono: ";
            getline(cin, phone);
            cout << "Ingrese nuevo correo electrónico: ";
            getline(cin, email);
            manager.updateContact(nombre, phone, email);
            break;
        case 4:
            manager.showContacts();
            break;
        case 5:
            cout << "Saliendo del programa...\n";
            break;
        default:
            cout << "Opción no válida. Intente nuevamente.\n";
            break;
        }
    } while (option != 5);

    return 0;
}
