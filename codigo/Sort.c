/*----------------------------------------------------------------------*/
/* 			Universidade Federal de São João del - Rei 
				Algoritmos e Estrutura de Dados III
				Ciência da Computação - 3º período
					
							TP4
						    
					Isabella Vieira Ferreira
					 Mônica Neli de Resende
						Novembro / 2012                                 */
/*----------------------------------------------------------------------*/

#include "Sort.h"

/*----------------------------------------------------------------------*/
/* Função responsável por verificar se os dois pontos são iguais, menores
   ou iguais.														    */
/*----------------------------------------------------------------------*/

int Empate (celula ponto1, celula ponto2){

	if ((ponto1.x > ponto2.x) || (ponto1.x == ponto2.x && ponto1.y > ponto2.y)) return 1;
	else if (ponto1.x == ponto2.x && ponto1.y == ponto2.y) return 0;
	else return -1;

}

/*----------------------------------------------------------------------*/
/* Quicksort sequencial.												*/
/*----------------------------------------------------------------------*/

void QuickSort_Sec (int n){
	
	pilha Pilha;
	celula2 item;
	int esq, dir, i=0, j=0;
	
	Criar(&Pilha);
		
	esq = 0;
	dir = n-1;
	
	Empilhar(&Pilha, dir, esq);
	
	do{ 
	
		if (dir > esq){
			particionar(esq, dir, &i, &j);
						
			if ((j-esq) > (dir-i)){
				Empilhar(&Pilha, j, esq);
				esq = i;
			
			}else {
				Empilhar(&Pilha, dir, i);
				dir = j;			
			}
				
		}else{
			item = Desempilhar(&Pilha);
			dir = item.dir;
			esq = item.esq;
		
		} 
	
	
	}while(Pilha.Tam > 0);
	
	Destruir_pilha(&Pilha);
		
	return;
}

/*----------------------------------------------------------------------*/
/* Função que particiona o vetor pela metade e escolhe o meio como pivô.
	Os elementos à esquerda são menores que o pivô, e os elementos à 
	direita maiores que o pivô. 										*/
/* ----------------------------------------------------------------------*/

void particionar(int esq, int dir,int *i, int *j) {
	
	celula Pivo, w;

	*i = esq; 
	
	*j = dir;

	// obtem o pivô x. O pivô é o elemento do meio. 
	Pivo = Pontos.inicio[(*i + *j) / 2];
		
	do {
	
		// Enquanto a chave for menor que o pivô, "i anda para a direita".
		while ((Empate(Pontos.inicio[*i], Pivo) < 0) &&  (*i < dir)) (*i)++;
	
		//Enquanto a chave for maior que o pivô, "j anda para a esquerda".
		while  ((Empate(Pontos.inicio[*j], Pivo) > 0) && (*j > esq)) (*j)--;
		
		//Se os ponteiros "i" e "j" se cruzarem,ou "i" for menor que "j", troca os elementos de lugar.
		if (*i <= *j) {
			
			w = Pontos.inicio[*i]; 
			Pontos.inicio[*i] = Pontos.inicio[*j]; 
			Pontos.inicio[*j] = w;
			(*i)++; 
			(*j)--;
		}
		
	} while (*i <= *j);
	
}

/*----------------------------------------------------------------------*/
/* Quicksort não recursivo e paralelizado. Função que ordena os 
   elementos no vetor.													*/
/*----------------------------------------------------------------------*/

void *QuickSort_NaoRec (void *arg){

	thread_arg *argumentos = (thread_arg *) arg;

	pilha Pilha;
	celula2 item;
	int esq, dir, i=0, j=0;
	
	Criar(&Pilha);

	esq = argumentos->limite0;
	dir = argumentos->limite1;
			
	Empilhar(&Pilha, dir, esq);
	  	
	do { 
			
		if (dir > esq){

			particionar(esq, dir, &i, &j);
			  
			if ((j-esq) > (dir-i)){
				
				Empilhar(&Pilha, j, esq);
				esq = i;
			
			} else {
				
				Empilhar(&Pilha, dir, i);
				dir = j;			
				
			}
				
		} else {
			
			item = Desempilhar(&Pilha);
			dir = item.dir;
			esq = item.esq;
		} 
	
	
	} while(Pilha.Tam > 0);
	
	pthread_exit(NULL);
	
}


/*----------------------------------------------------------------------*/
/* Ordenação do Quicksort.												*/
/*----------------------------------------------------------------------*/

void Ordenacao (int NUMTHREADS){

	int i;
		
	pthread_t threads[NUMTHREADS];
	
	// Criando threads com malloc
	argumentos = (thread_arg *) malloc(sizeof(thread_arg)*NUMTHREADS);

	for (i = 0; i < NUMTHREADS; i++){

		// Identificação do processo
		argumentos[i].id = i;		
		// Valor da esquerda daquela particao		
		argumentos[i].limite0 = i * Pontos.Tam/NUMTHREADS;
		// Valor da direita daquela particao.
		argumentos[i].limite1 = (i+1)*Pontos.Tam/NUMTHREADS - 1;
					
		pthread_create(&(threads[i]),NULL,QuickSort_NaoRec, &(argumentos[i]));
		
	}
			
		
	for(i=0;i<NUMTHREADS;i++){
		 
		pthread_join(threads[i], NULL);
		
	}
	
	QuickSort_Sec (Pontos.Tam);

}
