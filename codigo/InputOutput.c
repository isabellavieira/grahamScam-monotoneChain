/*---------------------------------------------------------------------*/
/* 			Universidade Federal de São João del - Rei 
				Algoritmos e Estrutura de Dados III
				Ciência da Computação - 3º período
					
							TP4
						    
					Isabella Vieira Ferreira
					 Mônica Neli de Resende
						Novembro / 2012                                */
/*---------------------------------------------------------------------*/

#include "InputOutput.h"

/*----------------------------------------------------------------------*/
/* Função responsável por fazer a leitura do arquivo.                   */
/* Retorna um vetor contendo em cada célula as coordenadas de um ponto. */
/*----------------------------------------------------------------------*/

void Leitura (FILE *entrada, int *continua) {
	
	char caractere;									// Variável para a leitura
	int i;											// Contador
	int num;
	
	fscanf(entrada, "%c" , &caractere);				// Lendo o número de pontos a serem lidos
	num = Converte(entrada, &caractere);
	
	if (num != 0) {	
		
		Pontos.Tam = num;
		Pontos.inicio = (celula *) malloc (sizeof(celula)*(Pontos.Tam));					
		
		
		for (i = 0; i < Pontos.Tam; i++) {
			
			fscanf(entrada,"%c", &caractere);
			Pontos.inicio[i].x = Converte(entrada, &caractere);
			fscanf(entrada,"%c", &caractere);
			Pontos.inicio[i].y = Converte(entrada, &caractere);
								
		}	 
		
	} else *continua = 0;
	
	return;
	 
}

/*----------------------------------------------------------------------*/
/* Função responsável por imprimir no arquivo os resultados.		    */
/*----------------------------------------------------------------------*/

void Imprimir_Monotone (FILE *Saida, int possibilidade) {											
			
	int i;

	char Teste_i[] = "Teste";	
	
	fprintf(Saida, "%s " ,Teste_i);
	fprintf(Saida, "%d\n" ,iteste);	

	if (possibilidade == -1){
		
		fprintf(Saida, "%s\n" ,"impossivel");
	
	} else {
	
		for (i = 0; i < CascoConvexo.Tam-1; i++){
			
			fprintf(Saida, "%d %d\n" ,CascoConvexo.inicio[i].x, CascoConvexo.inicio[i].y);	
		
		}
	}
	
	// Contador dos testes - variável global
	iteste++;
			
}

/*----------------------------------------------------------------------*/
/* Função responsável por imprimir no arquivo os resultados.		    */
/*----------------------------------------------------------------------*/

void Imprimir_Graham (FILE *Saida, int possibilidade) {											

int i;

	char Teste_i[] = "Teste";
	
	
	fprintf(Saida, "%s " ,Teste_i);
	fprintf(Saida, "%d\n" ,iteste);	

	if (possibilidade == -1){
		
		fprintf(Saida, "%s\n" ,"impossivel");
	
	} else {
	
		for (i = 0; i < CascoConvexo.Tam; i++){
			
			fprintf(Saida, "%d %d\n" ,CascoConvexo.inicio[i].x, CascoConvexo.inicio[i].y);	
		
		}
	}
	
	// Contador dos testes - variável global
	iteste++;
			
}
