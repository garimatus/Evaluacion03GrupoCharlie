/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include "dependencias.h"
#include "asignatura.h"
#include "horario.h"
#include <iostream>
#include <vector>
#include <string>
#include <sstream>


using namespace std;


void participantes() {
    std::cout << std::endl << "=== Análisis de Algoritmos: Evaluación 03 ===" << std::endl;
    std::cout << std::endl << "Profesor : Sebastián Salazar M.\n";
	std::cout << std::endl << "Integrantes : ";
	std::cout << std::endl << "Edgar Matus";
    std::cout << std::endl << "Oscar Peñaloza";
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


bool criterio(asignatura prueba, horario* programacion)
{
	if (true)
	{
		return true;
	}
	
	else
	{
		return false;
	}
}


horario* greedy(std::vector<asignatura> pruebas)
{
	horario* progra = new horario[5];
	
	int n = 0;
	
	for (std::vector<asignatura>iterator it = pruebas.begin(); it != pruebas.end(); it++, n++)
	{
		asignatura mejor = pruebas.begin();
		
		std::string nombre(pruebas.at(n).getNombre());
		
		int index = 0;
		
		for (int i = 0; i < 5; i++)
		{
			for (int j = 0; j < 8; j++)
			{
				for (int k = 0; k < 5; k++)
				{
					if (criterio(pruebas.at(n), progra))
					{
						mejor = pruebas.at(n);
					
						index = n;
					}
				}
			}
		}
		
		pruebas.erase(index); /* implementar multi-asignación */
	}
	
	return progra;
}


void escribir(horario* programacion)
{
	std::ofstream escritura;
	
	for (int i = 0; i < 5; i++)
	{
		escritura.open(std::string(programacion[i].sala)+".txt");
		
		for (int j = 0; j < 8; j++)
		{
			escritura << std::to_string(j+1);
					
			for (int k = 0; k < 5; k++)
			{
				if (programacion[i].bloques[j][k].getNombre() != '\0')
				{
				
					escritura << std::string(programacion[i].bloques[j][k].getCodigo())+" - "+std::string(programacion[i].bloques[j][k].getNombre())+";";
				}

				else
				{
					escritura << ";";
				}
			}
			
			escritura << std::endl;
		}
		
		escritura.close();
	}
}