
#include <stdio.h>
#include <stdlib.h>

struct sNODE{
  int dado;
  struct sNODE *prox;
};

struct sNODE *ini = NULL, *fim = NULL;

void enqueue(int dado);
int dequeue();

int tamanho();
void imprimir();
void apagar();
void getFront();

int main(void) {
    enqueue(20);
    enqueue(30);
    enqueue(40);
    imprimir();
    getFront();
    dequeue();
    getFront();
  return 0;
}

void enqueue(int dado){
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

int dequeue(){
  if (ini) {
	int dado = ini->dado;
	struct sNODE *tmp = ini;
    
	if (ini == fim)
  	   ini = fim = NULL;
	else
  	   ini = ini->prox;

	free(tmp);

	return dado;
  }
  else {
	printf("Não há elementos. Fila vazia.\n");
	exit(1);
  }
}

void apagar(){
  struct sNODE *aux = ini, *ant = NULL;
 
  while (aux){
	ant = aux;
	aux = aux->prox;
	free(ant);
  }
  ini = fim = NULL;
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
 
  printf("F[ ");
  while (aux){
	printf("%d ", aux->dado);
	aux = aux->prox;
  }
  printf("]\n");
}

void getFront(){
    if (ini == NULL){
       printf("Nao ha elementos. Fila vazia.\n");
	   
    }else{
        printf("O primeiro elemento eh: %d\n",ini->dado);
    }
}