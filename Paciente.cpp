//Autor : Luis Gerardo Flores Zapata  Matricula:A01799405

//Código con la declaración de los atributos en de la clase paciente

#include "Paciente.h"
#include <fstream>
#include <iostream>
#include <sstream>

using namespace std;

//constructor de la claase
Paciente::Paciente() {}

//lee las notas de la base de datos
void Paciente::leerDatosDesdeCSV(const string& filename) {
    ifstream file(filename);
    if (!file) {
        cerr << "No se pudo abrir el archivo " << filename << endl;
        return;
    }
    string line;
    while (getline(file, line)) {
        stringstream ss(line);
        string token;

        getline(ss, token, ',');
        int numeroCita;
        try {
            numeroCita = stoi(token);
        } catch (const invalid_argument& e) {
            cerr << "Error de conversión: " << e.what() << endl;
            continue;
        } catch (const out_of_range& e) {
            cerr << "Número fuera de rango: " << e.what() << endl;
            continue;
        }

        string tratamiento, fecha, hora, estado, nota;
        getline(ss, tratamiento, ',');
        getline(ss, fecha, ',');
        getline(ss, hora, ',');
        getline(ss, estado, ',');
        getline(ss, nota, ',');

        Cita nuevaCita(numeroCita, tratamiento, fecha, hora, estado, this);
        listaCitas.push_back(nuevaCita);
    }
    file.close();
}

//guarda las modificaciones dadas por el usuario de los atributos de la cita 
void Paciente::guardarCitasEnCSV(const string& filename) {
    ofstream file(filename);
    if (!file.is_open()) {
        cerr << "Error al abrir el archivo: " << filename << endl;
        return;
    }

    for (const auto& cita : listaCitas) {
        file << cita.getNumeroCita() << ','
             << cita.getTratamiento() << ','
             << cita.getFecha() << ','
             << cita.getHora() << ','
             << cita.getEstado() << ','
             << cita.getNota() << ','
             << "P" << '\n';
    }

    file.close();
}

//agrega la nueva cita con los atributos dados por usuaario a la lista de citas
void Paciente::agendarCita(const Cita& cita) {
    listaCitas.push_back(cita);
}

//muestra todas las citas dentro de la lista de citas
void Paciente::mostrarCitas() const {
    for (const auto& cita : listaCitas) {
        cout << "Número de Cita: " << cita.getNumeroCita() << endl;
        cout << "Tratamiento: " << cita.getTratamiento() << endl;
        cout << "Fecha: " << cita.getFecha() << endl;
        cout << "Hora: " << cita.getHora() << endl;
        cout << "Estado: " << cita.getEstado() << endl;
        cout << "Nota: " << cita.getNota() << endl;
        cout << endl;
    }
}

//modifica el tratamiento, fecha y hora dada por el usuario 
void Paciente::cambiarCita(int numeroCita, const string& tratamiento, const string& nuevaFecha, const string& nuevaHora) {
    for (auto& cita : listaCitas) {
        if (cita.getNumeroCita() == numeroCita) {
            cita.cambiarCita(tratamiento, nuevaFecha, nuevaHora);
            guardarCitasEnCSV("notas.csv");
            cout << "Cita con número " << numeroCita << " cambiada correctamente." << endl;
            return;
        }
    }
    cout << "La cita con número " << numeroCita << " no se encontró." << endl;
}
