#include <stdio.h>
#include <stdlib.h>

struct sNODE{
  int dado;
  struct sNODE *prox;
};

struct sNODE *ini = NULL, *fim = NULL;

void inserir(int dado);
void remover(int dado);
struct sNODE *buscar(int dado);

int obter(struct sNODE *node);
int tamanho();
void imprimir();
void apagar();
void bubbleSort();

int main(){
    for (int i = 8; i > 0;i--){
        inserir(i);
    }
    imprimir();

    bubbleSort();
    
    imprimir();

  return 0;
}

void inserir(int dado){
  struct sNODE *novo = (struct sNODE*) malloc(sizeof(struct sNODE));
  novo->dado = dado;
  novo->prox = NULL;

  if (!ini)
	ini = fim = novo;
  else{
	fim->prox = novo;
	fim = novo;
 }
}

struct sNODE *buscar(int dado){
  struct sNODE *aux = ini;

  while (aux){
	if (dado == aux->dado)
  	    return aux;
	aux = aux->prox;
  }

  return NULL;
}

void remover(int dado){
  struct sNODE *aux = ini, *ant = NULL;

  while (aux){
	if (dado == aux->dado){
  	    if (aux == ini)
    	        ini = ini->prox;
  	    else if(aux == fim){
    	        ant->prox = NULL;
    	        fim = ant;
  	    } else
    	        ant->prox = aux->prox;
 	 
  	    free(aux);
  	    return;
	}
    
	ant = aux;
	aux = aux->prox;
  }
}

void apagar(){
  struct sNODE *aux = ini, *ant;
 
  while (aux){ant = aux;
	aux = aux->prox;
	free(ant);
  }
  ini = fim = NULL;
}

int obter(struct sNODE *node){
  if (!node){
	printf("Erro ao obter dado. Ponteiro invalido.");
	exit(0);
  }
 
  return node->dado;
}

int tamanho(){
  struct sNODE *aux = ini;
  int tam = 0;
 
  while (aux){
	tam++;
	aux = aux->prox;
  }
 
  return tam;
}

void imprimir(){
  struct sNODE *aux = ini;
 
  printf("[ ");
  while (aux){
	printf("%d ", aux->dado);
	aux = aux->prox;
  }
  printf("]\n");
}

void bubbleSort(){
    
    struct sNODE *aux,*current;
    int tam = tamanho();
    
    for(int i=0; i<tam; i++) {
        for(int j=0; j < tam - 1; j++) {
            if (j == 0){
              aux = ini;
              current = aux->prox;
            }
            if(aux->dado > current->dado){
                int x = aux->dado;
                aux->dado=current->dado;
                current -> dado = x;
            }
            
            aux = aux->prox;
            current = aux->prox;
        }
    }
}
