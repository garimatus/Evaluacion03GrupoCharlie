/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include "asignatura.h"


asignatura::asignatura()
{
	semestre = "sin asignar";
	codigo = "sin asignar";
	nombre = "sin asignar";
}

asignatura::asignatura(std::string num, std::string cod, std::string nom)
{
	semestre = new char[num.length()+1];
	std::strcpy(semestre, num.c_str());
	
	codigo = new char[cod.length()+1];
	std::strcpy(codigo, cod.c_str());
	
	nombre = new char[nom.length()+1];
	std::strcpy(nombre, nom.c_str());
}

char* asignatura::getSemestre()
{
	return semestre;
}

char* asignatura::getCodigo()
{
	return codigo;
}

char* asignatura::getNombre()
{
	return nombre;
}