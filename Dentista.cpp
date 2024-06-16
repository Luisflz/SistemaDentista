//Autor : Luis Gerardo Flores Zapata  Matricula:A01799405

//Código conla implementacion de el contructor y métodos de la clase dentista

#include "Dentista.h"
#include <fstream>
#include <sstream>

using namespace std;

//constructor de la clase
Dentista::Dentista() {}

//función para leer las citas del archivo csv (base de datos)
void Dentista::leerCitasDesdeCSV(const string& filename) {
    ifstream file(filename);
    if (!file.is_open()) {
        cerr << "Error al abrir el archivo: " << filename << endl;
        return;
    }

    string line;
    while (getline(file, line)) {
        istringstream iss(line);
        string numeroCitaStr, tratamiento, fecha, hora, estado, nota, tipoUsuario;
        
        if (getline(iss, numeroCitaStr, ',') &&
            getline(iss, tratamiento, ',') &&
            getline(iss, fecha, ',') &&
            getline(iss, hora, ',') &&
            getline(iss, estado, ',') &&
            getline(iss, nota, ',') &&
            getline(iss, tipoUsuario, ',')) {
            
            int numeroCita = stoi(numeroCitaStr);
            Cita cita(numeroCita, tratamiento, fecha, hora, estado, this);
            setNota(&cita, nota); 
            listaCitas.push_back(cita);
        }
    }

    file.close();
}

//muestra los atributos de la cita 
void Dentista::mostrarCitas() const {
    for (const auto& cita : listaCitas) {
        cout << "Cita #" << cita.getNumeroCita() << std::endl;
        cout << "Tratamiento: " << cita.getTratamiento() << std::endl;
        std::cout << "Fecha: " << cita.getFecha() << std::endl;
        std::cout << "Hora: " << cita.getHora() << std::endl;
        std::cout << "Estado: " << cita.getEstado() << std::endl;
        std::cout << "Nota: " << cita.getNota() << std::endl;
        std::cout << std::endl;
    }
}

//guarda los datos modificados de la cita
void Dentista::guardarCitasEnCSV(const std::string &filename)
{
    std::ofstream file("notas.csv");
    if (!file.is_open()) {
        std::cerr << "Error al abrir el archivo: " << filename << std::endl;
        return;
    }

    for (const auto& cita : listaCitas) {
        file << cita.getNumeroCita() << ","
             << cita.getTratamiento() << ","
             << cita.getFecha() << ","
             << cita.getHora() << ","
             << cita.getEstado() << ","
             << cita.getNota() << ","
             << "D" << "\n";
    }

    file.close();
}

//cambia el estado de la cita
void Dentista::cambiarEstadoCita(int numeroCita, const std::string& nuevoEstado) {
    for (auto& cita : listaCitas) {
        if (cita.getNumeroCita() == numeroCita) {
            setEstado(&cita, nuevoEstado);
            return;
        }
    }
    std::cerr << "Cita no encontrada con número: " << numeroCita << std::endl;
}

//agrega la nueva nota, con los datos dados por el ussuario, a la lisat de citas
void Dentista::agregarNota(int numeroCita, const std::string& nota) {
    for (auto& cita : listaCitas) {
        if (cita.getNumeroCita() == numeroCita) {
            setNota(&cita, nota);
            return;
        }
    }
    std::cerr << "Cita no encontrada con número: " << numeroCita << std::endl;
}
