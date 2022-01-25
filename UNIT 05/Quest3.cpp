#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct sNODE{
  int numero,passageiros;
  char piloto[20],modelo[20];
  struct sNODE *prox;
};

struct sFILA{
  struct sNODE *ini, *fim;
};

typedef struct sFILA FILA;
typedef struct sNODE NODE;

void criar(FILA *fi);
void apagar(FILA *fi);

void enqueue(FILA *fi, int numero,char *modelo,char *nome,int passageiros);
int dequeue(FILA *fi);

int tamanho(FILA *fi);
void imprimir(FILA *fi);
void getFront(FILA *fi);

int main(){
  FILA fila1;
  criar(&fila1);

  enqueue(&fila1, 777,"Boeing 57","Mateus Pierre",70);
  enqueue(&fila1, 257,"BBJ 787-9","Ramiro Pereira",10);
  enqueue(&fila1, 259,"ABC 567","Santiago",30);

  imprimir(&fila1);

  dequeue(&fila1);

  imprimir(&fila1);

  tamanho(&fila1);
  
  getFront(&fila1);

  apagar(&fila1);

  return 0;
}

void criar(FILA *fi)
{
 fi->ini = fi->fim = NULL;
}

void apagar(FILA *fi){
  NODE *aux = fi->ini, *ant = NULL;
 
  while (aux){
	ant = aux;
	aux = aux->prox;
	free(ant);
  }
  fi->ini = fi->fim = NULL;

}

void enqueue(FILA *fi, int numero,char *modelo,char *piloto,int passageiros){
  NODE *novo = (NODE*) malloc(sizeof(NODE));
  novo->numero = numero;
  strcpy(novo->piloto, piloto);
  strcpy(novo->modelo, modelo);
  novo->passageiros = passageiros;

  novo->prox = NULL;

  if (!fi->ini)
	fi->ini = fi->fim = novo;
  else{
	fi->fim->prox = novo;
	fi->fim = novo;
  }
}

int dequeue(FILA *fi){
  if (fi->ini) {
	int numero = fi->ini->numero,capacidade = fi->ini->passageiros;
  char modelo[30],nome[30];
  strcpy(nome, fi->ini->piloto);
  strcpy(modelo, fi->ini->modelo);

	struct sNODE *tmp = fi->ini;
    
	if (fi->ini == fi->fim)
  	   fi->ini = fi->fim = NULL;
	else
  	   fi->ini = fi->ini->prox;

	free(tmp);

	return printf("Aviao de numero: %d, modelo: %s, piloto: %s e com capacidade de: %d pessoas. Decolagem autorizada.\n",numero,modelo,nome,capacidade);
  }
  else {
	printf("Não há elementos. Fila vazia.\n");
	exit(1);
  }
}

int tamanho(FILA *fi){
  NODE *aux = fi->ini;
  int tam = 0;
 
  while (aux){
	tam++;
	aux = aux->prox;
  }
 
  return printf("Numero de avioes em espera: %d\n",tam);
}

void imprimir(FILA *fi){
  NODE *aux = fi->ini;
  printf("\n");

  while (aux){
	printf("Numero: %d Piloto: %s\n", aux->numero,aux->piloto);
	aux = aux->prox;
  }
  printf("\n");
}

void getFront(FILA *fi){
    NODE *aux = fi->ini;
    if (fi->ini == NULL){
       printf("Nao ha elementos. Fila vazia.\n");
	   
    }else{
        printf("O modelo do primeiro aviao da fila eh: %s || numero: %d || capacidade: %d || piloto: %s \n",aux->modelo,aux->numero,aux->passageiros,aux->piloto);
    }
}