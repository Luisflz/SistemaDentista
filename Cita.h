#ifndef CITA_H
#define CITA_H

#include <string>

using namespace std;

class Cita 
{
private: 
    int numeroCita;
    string nombre;
    string fecha;
    string hora;
    string estado;

public: 
    Cita( int numeroCita, string& tratamiento, string& fecha, string& hora, string& estado);

    void confirmarCita();
    void cancelarCita();
    void mostrarCita();
};

#endif 