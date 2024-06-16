//Autor : Luis Gerardo Flores Zapata  Matricula:A01799405

//Código con la declaración de los atributos en de la clase paciente

#include "Cita.h"
#include <vector>
#include <string>

using namespace std;

class Paciente {
private:
    vector<Cita> listaCitas;
    string nombre;

public:
    Paciente();
    void leerDatosDesdeCSV(const string& filename);
    void guardarCitasEnCSV(const string& filename);
    void agendarCita(const Cita& cita);
    void mostrarCitas() const;
    void cambiarCita(int numeroCita, const string& tratamiento, const string& nuevaFecha, const string& nuevaHora);
};
