#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct sNODE{
  char nome[30];
  char ocupacao[30];
  int dado;

  struct sNODE *ant;
  struct sNODE *prox;
}LISTA;

struct sNODE *ini = NULL, *fim = NULL;

void inserir(char *nome,char *ocupacao,int dado);
void remover(char *nome);
LISTA *buscar(char *nome);

int obter(LISTA *node);
int tamanho();
void imprimir();

void apagar();

int main(){
  
  inserir("Mateus","Programador",6000);
  inserir("Livia","Programador",6001);
  inserir("Liz","Programador",6002);
  inserir("Pedro","Programador",6003);

  imprimir();
  
  remover("Mateus");
  imprimir();
  
  return 0;
}

void inserir(char *nome,char *ocupacao,int dado){
  LISTA *novo = (struct sNODE*) malloc(sizeof(struct sNODE));
  LISTA *aux = ini;
  novo->dado = dado;
  strcpy(novo->nome, nome);
  strcpy(novo->ocupacao, ocupacao);
  novo->ant = NULL;
  novo->prox = NULL;
  
  while (aux && dado < aux->dado){
      aux = aux->prox; 
  }
  if (!ini){
	ini = fim = novo;
  }else if (aux == ini){
    novo->prox = ini;
	ini = novo;
  }
  else if(!aux){
    fim->prox=novo;
    novo->ant = fim;
    fim = novo;
  }
  else{
    aux->ant->prox=novo;
    novo->ant = aux->ant;
    novo->prox=aux;
    aux->ant = novo;
  }
}



LISTA *buscar(char *nome){
  LISTA *aux = ini;

  while (aux){
	if ((strcmp(nome,aux->nome)==0)){
        return aux;
  }
  aux = aux->prox;
  }

  return NULL;
}

void remover(char *nome){
  
  LISTA *aux = ini, *tras = NULL;

  while (aux){
	if ((strcmp(nome,aux->nome)==0)){
  	    if (aux == ini)
    	        ini = ini->prox;
  	    else if(aux == fim){
    	        tras->prox = NULL;
    	        fim = tras;
  	    } else
    	        tras->prox = aux->prox;
 	 
  	    free(aux);
  	    return;
	}
    
	tras = aux;
	aux = aux->prox;
  }
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
  
  printf("\n");
  while (aux){
  printf("Nome: %s ||",aux->nome);
  printf(" Profissao: %s ||",aux->ocupacao);
	printf(" Salario: %d ", aux->dado);
	aux = aux->prox;
  printf("\n");
  }
  
}
