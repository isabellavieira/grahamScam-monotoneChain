/*---------------------------------------------------------------------*/
/* 			Universidade Federal de São João del - Rei 
				Algoritmos e Estrutura de Dados III
				Ciência da Computação - 3º período
					
							TP4
						    
					Isabella Vieira Ferreira
					 Mônica Neli de Resende
						Novembro / 2012                                */
/*---------------------------------------------------------------------*/

#include "OpHull.h"

/*----------------------------------------------------------------------*/
/* Produto Vetorial								 						*/
/*----------------------------------------------------------------------*/

long long  Verificacao(celula P1, celula P2, celula P3){

	long long result;

	// Se resultado for > 0   ---> à esquerda (anti-horário)
	// Se resultado for < 0   ---> à direita (horário)
	// Se resultado for == 0  ---> colineares	

	result=(P2.x-P1.x)*(P3.y-P1.y)-(P2.y-P1.y)*(P3.x-P1.x);

	return result;
	
}

/*--------------------------------------------------------------------*/
/* Funcao para achar a menor coordenada x.							  */
/*--------------------------------------------------------------------*/

void menor_coordenada () {
	
	int i, menor;
	celula aux;
	
	// Por enquanto o menor é o y da primeira posição
	menor = 1;
	
	// Verificando qual ponto do vetor tem a menor coordenaa y.
	for (i=2; i<=Pontos.Tam; i++) {
	
		if (Pontos.inicio[i].x < Pontos.inicio[menor].x) {
		
			menor = i;
		}
	
		// Se der empate, verifica a coordenada x.
		else if ((Pontos.inicio[i].x) == (Pontos.inicio[menor].x)) {
			
			if 	(Pontos.inicio[i].y < Pontos.inicio[menor].y)  {
				menor = i;
			}
			
		}
	}
	
	aux = Pontos.inicio[1];				
	Pontos.inicio[1] = Pontos.inicio[menor];
	Pontos.inicio[menor] = aux;
	
}	
	

/*--------------------------------------------------------------------*/
/* Cálculo do ângulo polar											  */
/*--------------------------------------------------------------------*/

void angulo_polar () {
	
	int x, y,i ;
	
	for (i=2; i<=Pontos.Tam; i++) {
		
		y = Pontos.inicio[i].y - Pontos.inicio[1].y;
		x = Pontos.inicio[i].x - Pontos.inicio[1].x;
				
		Pontos.inicio[i].angulo = atan2(y,x);
		
	}
	
}
