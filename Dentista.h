//Autor : Luis Gerardo Flores Zapata  Matricula:A01799405

//Código con la declaración de los atributos en de la clase dentista

#ifndef DENTISTA_H
#define DENTISTA_H

#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>
#include "Cita.h"

using namespace std;

class Dentista {
private:
    vector<Cita> listaCitas;

public:
    Dentista();

    void leerCitasDesdeCSV(const string& filename);
    void guardarCitasEnCSV(const string& filename);
    void mostrarCitas() const;
    void cambiarEstadoCita(int numeroCita, const string& nuevoEstado);
    void agregarNota(int numeroCita, const string& nota);
};

#endif 