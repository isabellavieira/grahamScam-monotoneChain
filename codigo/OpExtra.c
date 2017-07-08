/*---------------------------------------------------------------------*/
/* 			Universidade Federal de São João del - Rei 
				Algoritmos e Estrutura de Dados III
				Ciência da Computação - 3º período
					
							TP4
						    
					Isabella Vieira Ferreira
					 Mônica Neli de Resende
						Novembro / 2012                                */
/*---------------------------------------------------------------------*/

#include "OpExtra.h"

int iteste=1;
vetor CascoConvexo;				// Vetor onde ficará armazenado o Hull
vetor Pontos;

/*--------------------------------------------------------------------*/
/* Função responsável por criar a pilha.						      */
/*--------------------------------------------------------------------*/

void Criar(pilha *Pilha){
	
	Pilha->Fundo = (celula2 *) malloc(sizeof(celula2)*1);
	Pilha->Fundo->prox= NULL;
	Pilha->Topo = Pilha->Fundo;
	Pilha->Tam = 0;

}

/*----------------------------------------------------------------------*/
/* Função responsável por empilhar.								 		*/
/*----------------------------------------------------------------------*/

void Empilhar(pilha *Pilha, int dir, int esq) {  

	Apontador2 aux;
	
	aux = (celula2 *) malloc(sizeof(celula2)*1);
	aux->prox = Pilha->Topo;
	Pilha->Topo->dir = dir;	
	Pilha->Topo->esq = esq;		
	Pilha->Topo = aux;
	Pilha->Tam++;
	
}

/*-----------------------------------------------------------------------*/
/* Função responsável por desempilhar.				                     */
/*-----------------------------------------------------------------------*/

celula2 Desempilhar(pilha *Pilha) {
	
	Apontador2 aux;
	celula2 item;
	
	if (Pilha->Tam > 0){
	
		aux = Pilha->Topo;
		Pilha->Topo = Pilha->Topo->prox;
		item.dir = Pilha->Topo->dir;
		item.esq = Pilha->Topo->esq;
		free(aux);
		Pilha->Tam--;
		
	} else printf(":: ERRO: Pilha Vazia! ::\n");
	
	return item ;
	 
}

/*--------------------------------------------------------------------*/
/* Função responsável por destruir a pilha.							  */
/*--------------------------------------------------------------------*/

void Destruir_pilha(pilha *Pilha) {											
	
	while(Pilha->Tam > 0) Desempilhar(&(*Pilha));

	free(Pilha->Fundo);
				
}

/*----------------------------------------------------------------------*/
/* Função que le o número como char e o converte para inteiro.			*/
/*----------------------------------------------------------------------*/

int Converte (FILE *entrada, char *caractere){  

	char palavra[20]; 
	int i = 0;
	
	while ((*caractere) != ' ' && (*caractere) != '\n' ){
		
		palavra[i] = (*caractere);
		i++;
		fscanf(entrada, "%c" , &(*caractere));	
					
	}
	
	palavra[i] = '\0';
	
	return atoi(palavra);
}

