/*
 *  elemento.h
 *  lista_arreglo
 *
 *  Created by mauro on 121-03-10.
 *  Copyright 2010 mauro. All rights reserved.
 *
 */

#ifndef STRING_H
#include <string.h>
#define STRING_H
#endif

#ifndef STDIO_H
#include <stdio.h>
#define STDIO_H
#endif

#ifndef STDLIB_H
#include <stdlib.h>
#define STDLIB_H
#endif

typedef int Elemento;

//es necesario redefinir estas función cada vez que cambie la definición de elemento
//pero debería ser transparaente para el código que usa elemento

int muestraElemento(Elemento *unElemento){
	printf("%i",*unElemento);
	return(1);
}

int comparaElementos(Elemento *primerElemento, Elemento *segundoElemento){
	int temp = *primerElemento - *segundoElemento;
	//si los elementos son iguales retorna 0
	if (temp == 0) {
		return (0);
	}
	//si primerElemento es menor retorna -1
	if (temp < 0) {
		return(-1);
	}
	//si primerElemento es mayor retorna 1
	//if (temp > 0) {
		return(1);
	//}
}