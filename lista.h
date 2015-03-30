/*
 *  lista.h
 *  lista_arreglo
 *
 *  Created by mauro on 21-03-10.
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

#ifndef ELEMENTO_H
#include "elemento.h"
#define ELEMENTO_H
#endif


#define TAMANO_MAX 5 //podría usarse para limitar el tamaño de la lista

typedef struct t_lista{
	//inicio siempre es igual a 0
	//si la lista no esta vacia: rango con elementos va desde 0 a largo - 1 
	//largo = primera posición vacía, cuando largo < TAMANO
	unsigned int largo;
	//tamano = capacidad de la lista, si largo == tamano ->lista llena
	unsigned int tamano;
	//base del arreglo de punteros a los elementos de la lista, declarado así para poder definir el tamaño al inicializarla.
	//y para que la implementación de lista sea independiente del tipo de los elementos
	Elemento **elementos;
	//inicio de la lista siempre es la posición 0 del arreglo
} Lista;


Lista *iniciaLista(unsigned int unTamano){
	//asume que es una cola nueva declarada como puntero a Lista
	Lista *auxLista = (Lista *)malloc(sizeof(Lista));
	auxLista->largo=0;
	auxLista->tamano=unTamano;
	auxLista->elementos = (Elemento **)malloc(sizeof(Elemento *)*auxLista->tamano);
	return auxLista;
}

int estaVaciaLista(Lista *unaLista){
	return(unaLista->largo==0);
}

int estaLlenaLista(Lista *unaLista){
	return(unaLista->largo==unaLista->tamano);
}

unsigned int inicioLista(Lista *unaLista){
	//el inicio de la lista se mantiene en la posición 0
	//incluso si la lista está vacía
	return(0);
}

unsigned int finLista(Lista *unaLista){
	//el largo de la lista corresponde a la pisicion de la primera casilla vacía
	return(unaLista->largo);
}

int insertaElementoLista(Lista *unaLista, Elemento *unElemento, unsigned int posicion){
	//unElemento debe apuntar a una poición reservada e inicializada
	//Si no hay espacio o posición fuera de la lista actual retornar error (0)
	if (estaLlenaLista(unaLista) || (posicion > unaLista->largo) || (posicion < 0)){
		return(0);
	}
	//insertar elemento en la posicion solicitada
	//requiere desplazar los elementos que quedaran a continuación
	for (unsigned int i=unaLista->largo; i>posicion; i--) {
		unaLista->elementos[i]=unaLista->elementos[i-1];
	}
	unaLista->elementos[posicion] = unElemento;
	unaLista->largo++;
	return(1);
}

Elemento *suprimeElementoLista(Lista *unaLista, unsigned int posicion){
	//Si no hay elementos o posición fuera de la lista actual retornar error retornar error (0)
	if (estaVaciaLista(unaLista)  || (posicion > (unaLista->largo -1 )) || (posicion < 0)) {
		//printf("ERROR: No hay palabras en la cola.\n");
		return(NULL);
	}
	Elemento *unElemento = unaLista->elementos[posicion]; //para contener temporalmente la referencia al elemento extraído
	for (unsigned int i = posicion; i < (unaLista->tamano - 1); i++) {
		unaLista->elementos[i] = unaLista->elementos[i+1];
	}
	unaLista->largo--;
	return(unElemento);
}

int muestraLista(Lista *unaLista){
	//Si no hay elementos retornar error (0)
	if (estaVaciaLista(unaLista)) {
		printf("No hay palabras para mostrar (cola vacía).\n");
		return(0);
	}
	printf("Lista:\n");
	for (unsigned int i = 0; i<unaLista->largo; i++) {
		printf("%iº - Elemento: ",i);
		muestraElemento(unaLista->elementos[i]);
		printf("(%p)",unaLista->elementos[i]);
		printf("\n");
	}
	printf("---\n");
	return(1);
}

int liberaLista(Lista *unaLista){
	if (estaVaciaLista(unaLista)) {
		return(1);
	}
	for (unsigned int i = 0; i<unaLista->largo; i++) {
		free(unaLista->elementos[i]);
	}
	free(unaLista->elementos);
	free(unaLista);
	return(1);
}

unsigned int localizaElemento(Lista *unaLista, Elemento *unElemento){
	for (unsigned int i=0; i<unaLista->largo; i++) {
		if (comparaElementos(unElemento, unaLista->elementos[i])==0) {
			return(i); //retorna la posicion del elemento (contenido) que es igual al dado
		}		
	}
	return(-1); //si no se encuentra retorna -1
}

Elemento *recuperaElemento(Lista *unaLista, unsigned int posicion){
	//posicion debe estar dentro del arngo de elementos de la lista
	if ((posicion > (unaLista->largo -1 )) || (posicion < 0)) {
		return(NULL);
	}
	return(unaLista->elementos[posicion]);
}

unsigned int siguienteLista(Lista *unaLista, unsigned int posicion){
	if ((posicion > (unaLista->largo -1 )) || (posicion < 0)) {
		return(-1);
	}
	return(posicion++);
}

unsigned int anteriorLista(Lista *unaLista, unsigned int posicion){
	if ((posicion > (unaLista->largo)) || (posicion < 1)) {
		return(-1);
	}
	return(posicion--);
}