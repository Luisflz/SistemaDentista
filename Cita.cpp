//Autor : Luis Gerardo Flores Zapata  Matricula:A01799405

//Código conla implementacion de el contructor y métodos de la clase cita

#include "Cita.h"
#include "Paciente.h"

using namespace std;

//constructor de la calse
Cita::Cita(int numeroCita, const string& tratamiento, const string& fecha, const string& hora, const string& estado, void* persona)
    : numeroCita(numeroCita), tratamiento(tratamiento), fecha(fecha), hora(hora), estado(estado), persona(persona) {}

//cambia el estado de la cita a confirmado
void Cita::confirmarCita() {
    estado = "Confirmada";
    cout << "La cita con número " << numeroCita << " ha sido confirmada." << endl;
}

//cambia el esatdo de la cita a cancelado
void Cita::cancelarCita(int numeroCita) {
    estado = "Cancelada";
    cout << "La cita con número " << numeroCita << " ha sido cancelada." << endl;
}

//muestra los atributos de la cita
void Cita::mostrarCita(int numeroCita) const {
    cout << "Cita #" << numeroCita << endl;
    cout << "Tratamiento: " << tratamiento << endl;
    cout << "Fecha: " << fecha << endl;
    cout << "Hora: " << hora << endl;
    cout << "Estado: " << estado << endl;
    cout << "Nota: " << nota << endl;
}

//camvia el trratamiento, fecha y hora de la cita dada por el usuario
void Cita::cambiarCita(const string& nuevoTratamiento, const string& nuevaFecha, const string& nuevaHora) {
    tratamiento = nuevoTratamiento;
    fecha = nuevaFecha;
    hora = nuevaHora;
}

//setter de tratamiento
void setTratamiento(Cita* cita, const string& tratamiento) {
    cita->tratamiento = tratamiento;
}

//setter de fecha
void setFecha(Cita* cita, const string& fecha) {
    cita->fecha = fecha;
}

//setter de hora
void setHora(Cita* cita, const string& hora) {
    cita->hora = hora;
}

//setter de esatdo
void setEstado(Cita* cita, const string& estado) {
    cita->estado = estado;
}

//setter de nota
void setNota(Cita* cita, const string& nota) {
    cita->nota = nota;
}

//getter del número de cita
int Cita::getNumeroCita() const {
    return numeroCita;
}

//getter del tratamiento
string Cita::getTratamiento() const {
    return tratamiento;
}

//getter de fecha
string Cita::getFecha() const {
    return fecha;
}

//getter de hora
string Cita::getHora() const {
    return hora;
}

//getter de estado
string Cita::getEstado() const {
    return estado;
}

//getter de hora
string Cita::getNota() const {
    return nota;
}