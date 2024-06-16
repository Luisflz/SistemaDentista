//Autor : Luis Gerardo Flores Zapata  Matricula:A01799405

//Código con la función main que pruba la implenatción de todas las clases

#include <iostream>
#include "Paciente.h"
#include "Dentista.h"

using namespace std;

//menu correspomdinte al paciente
void mostrarMenuPaciente(Paciente& paciente) {
    int opcion;
    do {
        cout << "\n=== Menú del Paciente ===" << endl;
        cout << "1. Mostrar citas" << endl;
        cout << "2. Agendar cita" << endl;
        cout << "3. Cambiar cita" << endl;
        cout << "4. Salir" << endl;
        cout << "Seleccione una opción: ";
        cin >> opcion;

        switch (opcion) {
            case 1:
                paciente.leerDatosDesdeCSV("notas.csv"); // Cargar citas desde archivo CSV
                paciente.mostrarCitas();
                break;
            case 2: {
                int numeroCita;
                string tratamiento, fecha, hora;
                cout << "Ingrese el número de cita: ";
                cin >> numeroCita;
                cout << "Ingrese el tratamiento: ";
                cin >> tratamiento;
                cout << "Ingrese la fecha (AAAA-MM-DD): ";
                cin >> fecha;
                cout << "Ingrese la hora: ";
                cin >> hora;
                Cita nuevaCita(numeroCita, tratamiento, fecha, hora, "Pendiente", &paciente);
                paciente.agendarCita(nuevaCita);
                paciente.guardarCitasEnCSV("notas.csv"); // Guardar cambios en el archivo
                break;
            }
            case 3: {
                int numeroCita;
                string tratamiento, fecha, hora;
                cout << "Ingrese el número de cita a cambiar: ";
                cin >> numeroCita;
                cout << "Ingrese el nuevo tratamiento: ";
                cin >> tratamiento;
                cout << "Ingrese la nueva fecha (AAAA-MM-DD): ";
                cin >> fecha;
                cout << "Ingrese la nueva hora: ";
                cin >> hora;
                paciente.cambiarCita(numeroCita, tratamiento, fecha, hora);
                paciente.guardarCitasEnCSV("notas.csv"); 
                break;
            }
            case 4:
                cout << "Saliendo..." << endl;
                break;
            default:
                cout << "Opción inválida. Inténtelo de nuevo." << endl;
                break;
        }
    } while (opcion != 4);
}

//menu del dentista
void mostrarMenuDentista(Dentista& dentista, Paciente& paciente) {
    int opcion;
    do {
        cout << "\n=== Menú del Dentista ===" << endl;
        cout << "1. Mostrar citas" << endl;
        cout << "2. Cambiar estado de cita" << endl;
        cout << "3. Agregar nota a cita" << endl;
        cout << "4. Salir" << endl;
        cout << "Seleccione una opción: ";
        cin >> opcion;

        switch (opcion) {
            case 1:
                dentista.mostrarCitas();
                break;
            case 2: {
                int numeroCita;
                string nuevoEstado;
                cout << "Ingrese el número de cita: ";
                cin >> numeroCita;
                cout << "Ingrese el nuevo estado (Confirmada, Cancelada, Pendiente): ";
                cin >> nuevoEstado;
                dentista.cambiarEstadoCita(numeroCita, nuevoEstado);
                dentista.guardarCitasEnCSV("notas.csv"); // Guardar cambios en el archivo
                break;
            }
            case 3: {
                int numeroCita;
                string nota;
                cout << "Ingrese el número de cita a la que desea agregar nota: ";
                cin >> numeroCita;
                cout << "Ingrese la nota: ";
                cin.ignore(); // Limpiar el buffer del teclado
                getline(cin, nota);
                dentista.agregarNota(numeroCita, nota);
                dentista.guardarCitasEnCSV("notas.csv");
                break;
            }
            case 4:
                cout << "Saliendo..." << endl;
                break;
            default:
                cout << "Opción inválida. Inténtelo de nuevo." << endl;
                break;
        }
    } while (opcion != 4);
}

//main donde se prueban todas las fucniones 
int main(int argc, char const *argv[]) {
    Paciente paciente;
    Dentista dentista;
    dentista.leerCitasDesdeCSV("notas.csv");

    int opcion;
    do {
        cout << "\n=== Menú Principal ===" << endl;
        cout << "1. Menú del Paciente" << endl;
        cout << "2. Menú del Dentista" << endl;
        cout << "3. Salir" << endl;
        cout << "Seleccione una opción: ";
        cin >> opcion;

        switch (opcion) {
            case 1:
                mostrarMenuPaciente(paciente);
                break;
            case 2:
                mostrarMenuDentista(dentista, paciente); // Pasamos paciente como argumento
                break;
            case 3:
                cout << "Saliendo..." << endl;
                break;
            default:
                cout << "Opción inválida. Inténtelo de nuevo." << endl;
                break;
        }
    } while (opcion != 3);

    return 0;
}
