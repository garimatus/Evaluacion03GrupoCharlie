/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: gari
 *
 * Created on August 4, 2020, 1:17 PM
 */

#include <cstdlib>
#include <iostream>
#include <fstream>

#include "dependencias/dependencias.h"


using namespace std;

/*
 * 
 */
int main(int argc, char** argv) {

	if (argc == 2)
	{
		std::string ruta(argv[1]);
		
		if (ruta.length() >= 9)
		{
			std::string nombre = ruta.substr(ruta.length()-9,9);
			
			if (nombre == "ramos.csv")
			{
				std::ifstream lectura;
				
				lectura.open(ruta, std::ios_base::in);
				
				if (lectura)
				{
					
					vector<asignatura> ramos = leer(lectura);
					
					horario* programacion = greedy(ramos);
					
					escribir(programacion);
				
				}
			
				lectura.close();
			}
			
			else
			{
				std::cout << "\nEl archivo no se reconoce con el nombre o extensión de 'ramos.csv'." << std::endl;
				
				return EXIT_FAILURE;
			}
		}
		
		else
		{
			std::cout << "\nEl archivo es inválido o no existe en la ruta especificada." << std::endl;
			
			return EXIT_FAILURE;
		}
	}
	
	else
	{
		if (argc > 2)
		{
			std::cout << "\nExisten demasiados argumentos para la ejecución." << std::endl;
			
			return EXIT_FAILURE;
		}
		
		std::cout << "\nNo se ha especificado una ruta." << std::endl;
		
		return EXIT_FAILURE;
	}
	
	return EXIT_SUCCESS;
}

