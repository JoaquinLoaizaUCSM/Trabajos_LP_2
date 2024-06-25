#include <iostream>
#include <map>
#include <set>
#include <string>
#include <vector>

using namespace std;

class EventManager {
private:
    map<string, map<string, set<string>>> events; // Map de fechas a eventos y sus asistentes

public:
    void addEvent(const string& eventName, const string& date) {
        events[date][eventName] = set<string>(); // Inicializa un set vacío para los asistentes
    }

    void addAttendee(const string& eventName, const string& date, const string& attendeeName) {
        if (events.find(date) != events.end() && events[date].find(eventName) != events[date].end()) {
            events[date][eventName].insert(attendeeName);
        } else {
            cout << "Evento no encontrado." << endl;
        }
    }

    void showAttendees(const string& eventName, const string& date) {
        if (events.find(date) != events.end() && events[date].find(eventName) != events[date].end()) {
            cout << "Lista de asistentes para " << eventName << " el " << date << ":\n";
            for (const auto& attendee : events[date][eventName]) {
                cout << attendee << endl;
            }
        } else {
            cout << "Evento no encontrado." << endl;
        }
    }

    void searchEventsByDate(const string& date) {
        if (events.find(date) != events.end()) {
            cout << "Eventos el " << date << ":\n";
            for (const auto& event : events[date]) {
                cout << event.first << endl;
            }
        } else {
            cout << "No hay eventos programados para esta fecha." << endl;
        }
    }
};

int main() {
    EventManager manager;
    int option;
    string eventName, date, attendeeName;

    do {
        cout << "\nOpciones:\n";
        cout << "1. Agregar un nuevo evento\n";
        cout << "2. Agregar asistentes a un evento específico\n";
        cout << "3. Mostrar la lista de asistentes de un evento en orden alfabético\n";
        cout << "4. Buscar eventos por fecha\n";
        cout << "5. Salir\n";
        cout << "Seleccione una opción: ";
        cin >> option;

        switch (option) {
            case 1:
                cout << "Ingrese el nombre del evento: ";
                cin.ignore();
                getline(cin, eventName);
                cout << "Ingrese la fecha del evento (YYYY-MM-DD): ";
                cin >> date;
                manager.addEvent(eventName, date);
                break;
            case 2:
                cout << "Ingrese el nombre del evento: ";
                cin.ignore();
                getline(cin, eventName);
                cout << "Ingrese la fecha del evento (YYYY-MM-DD): ";
                cin >> date;
                cout << "Ingrese el nombre del asistente: ";
                cin.ignore();
                getline(cin, attendeeName);
                manager.addAttendee(eventName, date, attendeeName);
                break;
            case 3:
                cout << "Ingrese el nombre del evento: ";
                cin.ignore();
                getline(cin, eventName);
                cout << "Ingrese la fecha del evento (YYYY-MM-DD): ";
                cin >> date;
                manager.showAttendees(eventName, date);
                break;
            case 4:
                cout << "Ingrese la fecha del evento (YYYY-MM-DD): ";
                cin >> date;
                manager.searchEventsByDate(date);
                break;
            case 5:
                cout << "Saliendo del programa..." << endl;
                break;
            default:
                cout << "Opción no válida. Por favor, intente de nuevo." << endl;
        }
    } while (option != 5);

    return 0;
}