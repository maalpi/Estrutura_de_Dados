#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct sNODE{
  char dado[100];
  struct sNODE *prox;
};

struct sNODE *topo = NULL;

void push(char *dado);

void imprimir();

void apagar();

int main(void) {
    push("MATEUS");
    push("LINDO");
    imprimir();
    
  return 0;
}

void push(char *dado){
  struct sNODE *novo = (struct sNODE*) malloc(sizeof(struct sNODE));
  strcpy(novo->dado, dado);
  novo->prox = NULL;

  if (!topo)
	topo = novo;
  else{
	novo->prox = topo;
	topo = novo;
  }
}


void imprimir(){
  struct sNODE *aux = topo;
  int tam;
  printf("P[ ");
  while (aux){
  tam = strlen(aux->dado);
  for (int i=tam-1;i>=0;i--){
	  printf("%d ", aux->dado);
  }
	aux = aux->prox;
  }
  printf("]\n");
}

void apagar(){
  struct sNODE *aux = topo, *ant;
 
  while (aux){
	ant = aux;
	aux = aux->prox;
	free(ant);
  }
  topo = NULL;
}