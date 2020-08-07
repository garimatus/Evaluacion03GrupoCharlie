/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   dependencias.h
 * Author: gari
 *
 * Created on August 4, 2020, 8:20 PM
 */

#ifndef DEPENDENCIAS_H
#define DEPENDENCIAS_H


#include "asignatura.h"
#include "horario.h"
#include <vector>
#include <fstream>


void participantes();
std::vector<asignatura> leer(std::istream&);
horario* greedy(std::vector<asignatura>);
void escribir(horario*);



#endif /* DEPENDENCIAS_H */

