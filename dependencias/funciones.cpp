/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include "dependencias.h"
#include "asignatura.h"
#include <iostream>
#include <vector>
#include <string>
#include <sstream>


using namespace std;


void participantes() {
    std::cout << std::endl << "=== Analisis de Algoritmos: Evaluacion 03 ===" << std::endl;
    std::cout << std::endl << "Profesor : Sebastian Salazar M.\n";
	std::cout << std::endl << "Integrantes : ";
	std::cout << std::endl << "Edgar Matus";
    std::cout << std::endl << "Oscar Penaloza";
    std::cout << std::endl << "Daniela Galleguillos" << std::endl;
}


asignatura getAsignatura(std::string linea)
{
	std::stringstream ss(linea);
    std::string item;
	std::string columnas[3];
	
	int i = 0;
	
	while (getline(ss, item, ';')) {
		
		columnas[i] = item;
		
		i++;
	}

	asignatura ramo(columnas[0],columnas[1],columnas[2]);
	
	return ramo;
}


std::vector<asignatura> leer(std::istream& archivo)
{
	int a = 0;
	
	std::vector<asignatura> asignaturas;
	
	for (std::string linea; getline(archivo, linea); a++)
	{
		asignaturas.push_back(getAsignatura(linea));
	}
	
	return asignaturas;
}