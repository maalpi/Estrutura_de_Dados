
#include <stdio.h>
#include <stdlib.h>

typedef struct sNODE{
  int dado;
  struct sNODE *ant;
  struct sNODE *prox;
}LISTA;

struct sNODE *ini = NULL, *fim = NULL;

void inserir(int dado);
void inserir_ini(int dado);
void remover(int dado);
LISTA *buscar(int dado);

int obter(LISTA *node);
int tamanho();
void imprimir();
void imprimir_reverso();
void apagar();

int main(){
  inserir_ini(20);
  inserir_ini(30);
  inserir_ini(40);
  inserir_ini(50);
  inserir(70);
  inserir(80);
  imprimir();
  imprimir_reverso();
  return 0;
}

void inserir(int dado){
  LISTA *novo = (struct sNODE*) malloc(sizeof(struct sNODE));
  
  novo->dado = dado;
  novo->ant = NULL;
  novo->prox = NULL;
  
  if (!ini)
	ini = fim = novo;
  else{
	fim->prox = novo;
	novo->ant = fim;
	fim = novo;
  }
}

void inserir_ini(int dado){
  LISTA *novo = (struct sNODE*) malloc(sizeof(struct sNODE));
  novo->dado = dado;
  novo->ant = NULL;
  novo->prox = NULL;

  if (!ini)
	ini = fim = novo;
  else{
    ini->ant = novo;
    novo->prox = ini;
    novo->ant = NULL;
    ini = novo;
  }
}

LISTA *buscar(int dado){
  LISTA *aux = ini;

  while (aux){
	if (dado == aux->dado)
      	return aux;
	aux = aux->prox;
  }

  return NULL;
}

void remover(int dado){
  LISTA *aux = buscar(dado);

  if (!aux)
	return;

  if (!aux->ant && !aux->prox)
	ini = fim = NULL;
  else if (aux == ini) {
	ini = ini->prox;
	ini->ant = NULL;
  } else if (aux == fim) {
	fim = fim->ant;
	fim->prox = NULL;
  } else {
	aux->ant->prox = aux->prox;
	aux->prox->ant = aux->ant;
  }
  free(aux);
}

void apagar(){
  LISTA *aux = ini, *ant;
 
  while (aux){
	ant = aux;
	aux = aux->prox;
	free(ant);
  }
  ini = fim = NULL;
}

int obter(LISTA *node){
  if (!node){
	printf("Erro ao obter dado. Ponteiro invalido.");
	exit(0);
  }
 
  return node->dado;
}

int tamanho(){
  LISTA *aux = ini;
  int tam = 0;
 
  while (aux){
	tam++;
	aux = aux->prox;
  }
 
  return tam;
}

void imprimir(){
  LISTA *aux = ini;
 
  printf("[ ");
  while (aux){
	printf("%d ", aux->dado);
	aux = aux->prox;
  }
  printf("]\n");
}

void imprimir_reverso(){
  LISTA *aux = fim;
 
  printf("[ ");
  while (aux){
	printf("%d ", aux->dado);
	aux = aux->ant;
  }
  printf("]\n");
}