/*---------------------------------------------------------------------*/
/* 			Universidade Federal de São João del - Rei 
				Algoritmos e Estrutura de Dados III
				Ciência da Computação - 3º período
					
							TP4
						    
					Isabella Vieira Ferreira
					 Mônica Neli de Resende
						Novembro / 2012                                */
/*---------------------------------------------------------------------*/

#include "ConvexHull.h"

/*--------------------------------------------------------------------*/
/* Monotone Chain								     				  */
/*--------------------------------------------------------------------*/

int MonotoneChain() {
	
	int i;
	int t = 0, k = 0;
	
	// Casco Convexo inferior
	for (i = 0; i < Pontos.Tam; i++) {
		
		// O giro não pode ser à direita (sentido horário) < 0, nem colinear == 0. Se for, não inclui no Hull
		while (k >= 2 && Verificacao(CascoConvexo.inicio[k - 2], CascoConvexo.inicio[k - 1], Pontos.inicio[i]) <= 0) k--;
		
		CascoConvexo.inicio[k++] = Pontos.inicio[i];
	}
	
	// Casco Convexo superior
	t = k + 1;				// Para começar a preencher a partir da próxima posição que foi preenchida no casco inferior
	for (i = Pontos.Tam - 2; i >= 0; i--) {
		
		while (k >= t && Verificacao(CascoConvexo.inicio[k - 2], CascoConvexo.inicio[k - 1], Pontos.inicio[i]) <= 0)  k--;
		
		CascoConvexo.inicio[k++] = Pontos.inicio[i];

	}
	
	// Tamanho do casco convexo
	CascoConvexo.Tam = k;
	
	// Testando se é possível ter um casco convexo, mínimo 3 pontos	
	if (k > 3)  return 1;
	
	// Se não é possível ter um casco convexo, retorna -1
	return -1;
	
}

/*--------------------------------------------------------------------*/
/* Graham Scan									     				  */
/*--------------------------------------------------------------------*/

int Graham (pilha *Pilha){
	int i=2, resultado, cont = 0;;
	celula2 ponto;
	
	Empilhar(&(*Pilha), Pontos.inicio[0].x, Pontos.inicio[0].y);
	Empilhar(&(*Pilha), Pontos.inicio[1].x, Pontos.inicio[1].y);
		
	while(i < Pontos.Tam){
		
	
		// Verificando se P3(na posição i do vetor) esta à esquerda do vetor P1P2(formado pelo ponto do Topo e o abaixo do topo da pilha)
		resultado = (Pilha->Topo->prox->dir - Pilha->Topo->prox->prox->dir)*(Pontos.inicio[i].y - Pilha->Topo->prox->prox->esq) - (Pilha->Topo->prox->esq - Pilha->Topo->prox->prox->esq) * (Pontos.inicio[i].x - Pilha->Topo->prox->prox->dir);

																		//Se resultado for > 0   ---> à esquerda (anti-horário)
																		//Se resultado for < 0 ---> à direita (horário)
		// Faz parte do fecho											//Se resultado for == 0 ---> colineares
		if (resultado > 0){												
			
			Empilhar(&(*Pilha), Pontos.inicio[i].x, Pontos.inicio[i].y);
			i++;
																		
		}else if (Pilha->Tam > 2) {
			
			Desempilhar(&(*Pilha));
			
		}else {

			break;
		
		}
				
	}
	
	
	if (Pilha->Tam > 3){
				
		i = Pilha->Tam-1;
		
		cont = Pilha->Tam;
		CascoConvexo.Tam = Pilha->Tam;
		
		while (cont != 0){
			
			ponto = Desempilhar(&(*Pilha));
			CascoConvexo.inicio[i].x = ponto.dir;
			CascoConvexo.inicio[i].y = ponto.esq;
			i--;
			cont--;
		}
	
	}else return -1;
	
	return 0;
}

