//Autor : Luis Gerardo Flores Zapata  Matricula:A01799405

//Código con la declaración de los atributos en de la clase cita

#ifndef CITA_H
#define CITA_H

#include <iostream>
#include <string>

using namespace std;

class Cita {
    friend void setTratamiento(Cita* cita, const string& tratamiento);
    friend void setFecha(Cita* cita, const string& fecha);
    friend void setHora(Cita* cita, const string& hora);
    friend void setEstado(Cita* cita, const string& estado);
    friend void setNota(Cita *cita, const string &nota);

private:
    int numeroCita;
    string tratamiento;
    string fecha;
    string hora;
    string estado;
    string nota;
    void* persona;

public:
    Cita(int numeroCita, const string& tratamiento, const string& fecha, const string& hora, const string& estado, void* persona);

    void confirmarCita(); 
    void cancelarCita(int numeroCita); 
    void mostrarCita(int numeroCita) const; 

    int getNumeroCita() const; 
    string getTratamiento() const; 
    string getFecha() const; 
    string getHora() const; 
    string getEstado() const;
    string getNota() const; 
    void cambiarCita(const string& nuevoTratamiento, const string& nuevaFecha, const string& nuevaHora); 
};

#endif 
