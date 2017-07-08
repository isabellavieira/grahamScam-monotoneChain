/*----------------------------------------------------------------------*/
/* 			Universidade Federal de São João del - Rei 
				Algoritmos e Estrutura de Dados III
				Ciência da Computação - 3º período
					
							TP4
						    
					Isabella Vieira Ferreira
					 Mônica Neli de Resende
						Novembro / 2012                                 */
/*----------------------------------------------------------------------*/

#include "OpHull.h"
#include "ConvexHull.h"
#include "OpExtra.h"
#include "Sort.h"
#include "InputOutput.h"

#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

/*----------------------------------------------------------------------*/
/* Função Principal.													*/
/*----------------------------------------------------------------------*/

int main(int argc, char *argv[]){
	
	int possibilidade = 0;
	int continua=1;
	pilha Pilha;
	int NUMTHREADS;
	char *numthread;
	char *estrategias;
	int estrategia;
	char *arquivo_entrada;
	FILE *entrada;
	FILE *Saida;
			
	// Armazenando os dados do parametro
	arquivo_entrada = argv[1];
	numthread = argv[2];
	estrategias = argv[3];
	
	// Convertendo os valores lidos para inteiro
	NUMTHREADS = atoi(numthread);
	estrategia = atoi(estrategias);
	
	entrada = fopen(arquivo_entrada, "r");
	Saida = fopen ("saida.out", "a");
	
	if ((entrada == NULL) || (NUMTHREADS == ' ') || (estrategia != 1 && estrategia != 2)){
		
		printf ("\nParametro incorreto!\n\n");
		printf ("Para compilar voce deve digitar:\n");
		printf ("./tp4 <nome-do-arquivo-de-entrada> <numero-threads> <estratégia> \n");
		printf ("\nA estrategia sera:\n");
		printf ("1 - para utilizar algoritmo Monotone Chain;\n");
		printf ("2 - para utilizar algoritmo Graham Scan.\n");
			
		return 1;
		
	}
	
	Leitura(entrada, &continua);
		
	while (continua){
		
		// Alocando dinamicamente vetor onde ficará o Hull.
		CascoConvexo.inicio = (celula *) malloc(sizeof(celula)*(2*Pontos.Tam));
		
		if (estrategia == 1) {
			
			Ordenacao(NUMTHREADS);
			possibilidade =	MonotoneChain();
			Imprimir_Monotone(Saida, possibilidade);
			
		} else if (estrategia == 2) {
			
			Criar(&Pilha);
			menor_coordenada(&Pontos);				
			angulo_polar(&Pontos);
			Ordenacao(NUMTHREADS);
			possibilidade =	Graham(&Pilha);
			Imprimir_Graham(Saida, possibilidade);
			Destruir_pilha (&Pilha);
						
		}
		
		free(Pontos.inicio);	
		free(CascoConvexo.inicio);
		Leitura(entrada, &continua);
	
		
	}
	
	fclose(entrada);
	fclose(Saida);
	
	return 0;
	
}
