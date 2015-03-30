/*
 *  main.c
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

#ifndef LISTA_H
#include "lista.h"
#define LISTA_H
#endif

#ifndef ELEMENTO_H
#include "elemento.h"
#define ELEMENTO_H
#endif

int main (int argc, const char * argv[]) {

	Lista *numeros=iniciaLista(5);
	muestraLista(numeros);
	
	Elemento *unNumero;
	
	//secuencia de insercion
	unNumero = (Elemento *)malloc(sizeof(Elemento));
	*unNumero=5;
	if (!insertaElementoLista(numeros, unNumero, 0)) {
		printf("Error al insertar\n");
	}
	muestraLista(numeros);
	
	unNumero = (Elemento *)malloc(sizeof(Elemento));
	*unNumero=3;
	if (!insertaElementoLista(numeros, unNumero, 0)) {
		printf("Error al insertar\n");
	}
	muestraLista(numeros);

	unNumero = (Elemento *)malloc(sizeof(Elemento));
	*unNumero=1;
	if (!insertaElementoLista(numeros, unNumero, 0)) {
		printf("Error al insertar\n");
	}
	muestraLista(numeros);

	unNumero = (Elemento *)malloc(sizeof(Elemento));
	*unNumero=7;
	if (!insertaElementoLista(numeros, unNumero, 1)) {
		printf("Error al insertar\n");
	}
	muestraLista(numeros);
	
	unNumero = (Elemento *)malloc(sizeof(Elemento));
	*unNumero=10;
	if (!insertaElementoLista(numeros, unNumero, 5)) {
		printf("Error al insertar\n");
	}
	muestraLista(numeros);

	unNumero = (Elemento *)malloc(sizeof(Elemento));
	*unNumero=10;
	if (!insertaElementoLista(numeros, unNumero, -1)) {
		printf("Error al insertar\n");
	}
	muestraLista(numeros);

	unNumero = (Elemento *)malloc(sizeof(Elemento));
	*unNumero=10;
	if (!insertaElementoLista(numeros, unNumero, 3)) {
		printf("Error al insertar\n");
	}
	muestraLista(numeros);

	unNumero = (Elemento *)malloc(sizeof(Elemento));
	*unNumero=11;
	if (!insertaElementoLista(numeros, unNumero, 4)) {
		printf("Error al insertar\n");
	}
	muestraLista(numeros);

	//secuecia de consulta
	unNumero = (Elemento *)malloc(sizeof(Elemento));
	*unNumero= 3;
	printf("La posición del elemento ");
	muestraElemento(unNumero);
	printf(" es %i \n",localizaElemento(numeros, unNumero));
	
	unNumero = (Elemento *)malloc(sizeof(Elemento));
	*unNumero= 17;
	printf("La posición del elemento ");
	muestraElemento(unNumero);
	printf(" es %i \n",localizaElemento(numeros, unNumero));
	
	unNumero = recuperaElemento(numeros, 2);
	if (unNumero!=NULL) {
		printf("El elemento en la posicion %i es ",2);
		muestraElemento(unNumero);
		printf("\n");
	}
	
	unNumero = recuperaElemento(numeros, 10);
	if (unNumero!=NULL) {
		printf("El elemento en la posicion %i es ",2);
		muestraElemento(unNumero);
		printf("\n");
	}
	
	//secuencia de eliminacion
	unNumero = suprimeElementoLista(numeros, 4);
	if (unNumero==NULL) {
		printf("Error al suprimir\n");
	}
	muestraLista(numeros);
	
	unNumero = suprimeElementoLista(numeros, 0);
	if (unNumero==NULL) {
		printf("Error al suprimir\n");
	}
	muestraLista(numeros);
	
	unNumero = suprimeElementoLista(numeros, 0);
	if (unNumero==NULL) {
		printf("Error al suprimir\n");
	}
	muestraLista(numeros);
	
	unNumero = suprimeElementoLista(numeros, 0);
	if (unNumero==NULL) {
		printf("Error al suprimir\n");
	}
	muestraLista(numeros);
	
	unNumero = suprimeElementoLista(numeros, 1);
	if (unNumero==NULL) {
		printf("Error al suprimir\n");
	}
	muestraLista(numeros);
	
	unNumero = suprimeElementoLista(numeros, 0);
	if (unNumero==NULL) {
		printf("Error al suprimir\n");
	}
	muestraLista(numeros);
	
	unNumero = suprimeElementoLista(numeros, 0);
	if (unNumero==NULL) {
		printf("Error al suprimir\n");
	}
	muestraLista(numeros);
	
	liberaLista(numeros);
	
    return 0;
}
