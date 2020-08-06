/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   asignatura.h
 * Author: gari
 *
 * Created on August 5, 2020, 7:29 PM
 */

#ifndef ASIGNATURA_H
#define ASIGNATURA_H


#include <string>
#include <cstring>


class asignatura{
	
	public :
		
		asignatura();
		asignatura(std::string,std::string,std::string);
		char* getSemestre();
		char* getCodigo();
		char* getNombre();
	
	private :
		
		char* semestre;
		char* codigo;
		char* nombre;
};


#endif /* ASIGNATURA_H */

