/*---------------------------------------------------------------------*/
/* 			Universidade Federal de São João del - Rei 
				Algoritmos e Estrutura de Dados III
				Ciência da Computação - 3º período
					
							TP4
						    
					Isabella Vieira Ferreira
					 Mônica Neli de Resende
						Novembro / 2012                                */
/*---------------------------------------------------------------------*/

#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

#include "OpExtra.h"

#ifndef SORT_H
#define SORT_H

/*--------------------------------------------------------------------*/
/* Threads							     		  			      	  */
/*--------------------------------------------------------------------*/

typedef struct {
	int id;									// Indentificador da thread
	int limite0;							// Limite inferior - mais à esq
	int limite1;							// Limite superior - mais à direita
}thread_arg;

thread_arg *argumentos;

/*----------------------------------------------------------------------*/
/* Cabeçalho das funções do arquivo "Sort.c".							*/
/*----------------------------------------------------------------------*/

/*----------------------------------------------------------------------*/
int Empate (celula ponto1, celula ponto2);
/*----------------------------------------------------------------------*/
void particionar(int esq, int dir,int *i, int *j);
/*----------------------------------------------------------------------*/
void *QuickSort_NaoRec (void *arg);
/*----------------------------------------------------------------------*/
void QuickSort_Sec (int n);
/*----------------------------------------------------------------------*/
void Ordenacao (int NUMTHREADS);
/*----------------------------------------------------------------------*/

#endif
