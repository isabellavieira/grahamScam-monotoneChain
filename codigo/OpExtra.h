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

#ifndef OPEXTRA_H
#define OPEXTRA_H

/*--------------------------------------------------------------------*/
/* Estrutura de dados.							     				  */
/*--------------------------------------------------------------------*/

typedef struct celula *Apontador;

typedef struct celula {
	int x, y;
	float angulo;
}celula;


typedef struct vetor{
	Apontador inicio;
	int Tam;	
}vetor;

/*--------------------------------------------------------------------*/
/* Estrutura de dados Pilha.							     		  */
/*--------------------------------------------------------------------*/

typedef struct celula2 *Apontador2;

typedef struct celula2 {
	int esq, dir;
	Apontador2 prox;
}celula2;

typedef struct pilha{
	int Tam;
	Apontador2 Topo, Fundo;	
}pilha;

/*--------------------------------------------------------------------*/
/* Variáveis globais.									     		  */
/*--------------------------------------------------------------------*/
extern int iteste;
extern vetor CascoConvexo;							// Vetor onde ficará armazenado o Hull
extern vetor Pontos;								// Vetor de pontos lidos do arquivo de entrada


/*----------------------------------------------------------------------*/
/* Cabeçalho das funções do arquivo "OpExtra.c".						*/
/*----------------------------------------------------------------------*/

/*----------------------------------------------------------------------*/
void Criar(pilha *Pilha);
/*----------------------------------------------------------------------*/
void Empilhar(pilha *Pilha, int dir, int esq);
/*----------------------------------------------------------------------*/
celula2 Desempilhar(pilha *Pilha);
/*----------------------------------------------------------------------*/
void Destruir_pilha(pilha *Pilha);
/*----------------------------------------------------------------------*/
int Converte (FILE *entrada, char *caractere);
/*----------------------------------------------------------------------*/

#endif
