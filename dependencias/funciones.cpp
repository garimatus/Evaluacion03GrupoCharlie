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
		
		item = item.substr(1,item.length()-2);
		
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
		if (linea.substr(1,8) != "semestre")
		{
			asignaturas.push_back(getAsignatura(linea));
		}
	}
	
	return asignaturas;
}


void criterio(asignatura prueba, horario* programacion)
{
	bool mechon = false, tarde, mechonAM, mechonPM, paralela = false;
	
	int ventana = -1, sala, dia, bloque, contadorMechon;
	
	if (std::string(prueba.getSemestre()) == "1" || std::string(prueba.getSemestre()) == "2")
		mechon = true;
	
	/* criterio greedy */
	
	for (int i = 0; i < 5; i++)
	{/* Una nueva sala */
		for (int j = 0; j < 5; j++)
		{/* Un nuevo día */
			tarde = false;
			
			mechonAM = false;
			
			mechonPM = false;
			
			contadorMechon = 0;
			
			ventana = 0;
			
			for (int k = 0; k < 8; k++)
			{/* Un nuevo periodo */
				if (k >= 3)
					tarde = true;
				
				if (std::string(prueba.getNombre()) == std::string(programacion[i].bloques[k][j].getNombre()))
				{
					paralela = true;
					
					bloque = k;
					
					dia = j;
					
					break;
				}
				
				if (std::string(programacion[i].bloques[k][j].getSemestre()) == "1" ||
					std::string(programacion[i].bloques[k][j].getSemestre()) == "2")
				{
					if (tarde)
						mechonPM = true;
					else
						mechonAM = true;
					
					contadorMechon++;
				}
				ventana++;
			}
			
			if (mechon)
			{
				if (contadorMechon < 2)
				{
					for (int k = 0; k < 8; k++)
					{
						if (std::string(programacion[i].bloques[k][j].getNombre()) == "sin asignar")
						{
							sala = i;
							dia = j;
							bloque = k;
							
							break;
						}
					}
				}
			}

			else
			{
				for (int k = 0; k < 8; k++)
				{
					if (std::string(programacion[i].bloques[k][j].getNombre()) == "sin asignar")
					{
						sala = i;
						dia = j;
						bloque = k;
					
						break;
					}
				}	
			}
		}
	}
	
	if (paralela == false)
	{
		programacion[sala].bloques[bloque][dia] = prueba;
	}
	
	else
	{
		for (int sala = 0; sala < 5; sala++)
		{
			if (std::string(programacion[sala].bloques[bloque][dia].getNombre()) == "sin asignar")
			{
				programacion[sala].bloques[bloque][dia] = prueba;
				
				break;
			}
		}
	}
}


horario* greedy(std::vector<asignatura> pruebas)
{
	horario* progra = new horario[5];
	
	progra[0].sala = "M2-201";
	progra[1].sala = "M2-202";
	progra[2].sala = "M2-203";
	progra[3].sala = "M2-204";
	progra[4].sala = "M2-205";

	int n = 0;

	for (std::vector<asignatura>::iterator it = pruebas.begin(); it != pruebas.end(); it++, n++)
	{
		criterio(pruebas.at(n), progra);
	}

	return progra;
}


void escribir(horario* programacion)
{
	std::ofstream escritura;
	
	for (int i = 0; i < 5; i++)
	{
		escritura.open(std::string(programacion[i].sala)+".txt");
		
		escritura << "Período;Lunes;Martes;Miércoles;Jueves;Viernes;\n";
		
		for (int j = 0; j < 8; j++)
		{
			escritura << std::to_string(j+1)+" ";
					
			for (int k = 0; k < 5; k++)
			{
				escritura << std::string(programacion[i].bloques[j][k].getCodigo())+" - "+std::string(programacion[i].bloques[j][k].getNombre())+';';
			}
			
			escritura << std::endl;
		}
		
		escritura.close();
	}
	
	std::cout << "\nArchivos de texto plano .txt generados en la carpeta del proyecto." << std::endl;
}