#include <stdio.h>
#include <stdlib.h>

struct sFILA{
  int dado;
  int *arr, ini, fim;
  int MAX;
};

typedef struct sFILA FILA;

void criar(FILA *fi, int tam_MAX);
void apagar(FILA *fi);

void inserir_fim(FILA *fi, int dado);
int remover_ini(FILA *fi);

int tamanho(FILA *fi);
void imprimir(FILA *fi);

int main(){
  FILA fila1;
  criar(&fila1,10);

  inserir_fim(&fila1, 100);
  inserir_fim(&fila1, 50);
  inserir_fim(&fila1, 200);

  printf("Dequeue em Fila1 -> %d\n",remover_ini(&fila1));

  imprimir(&fila1);

  apagar(&fila1);


  return 0;
}

void criar(FILA *fi, int tam_MAX){
  fi->arr = (int*) malloc (tam_MAX * sizeof(int));
  fi->ini=fi->fim = 0;
  fi->MAX = tam_MAX;
}

void apagar(FILA *fi){
  
  fi->ini = fi->fim = 0;
}

void inserir_fim(FILA *fi,int elemento){
  if ((fi->fim + 1) != fi->ini && !(fi->fim + 1 == fi->MAX && !fi->ini) ){
	fi->arr[fi->fim] = elemento;
	//fim = (fim + 1) % MAX;
	fi->fim++;
	if (fi->fim == fi->MAX) fi->fim = 0;
  }
  else
	printf("Não foi possível inserir %d. Fila cheia.\n",elemento);
}

int remover_ini(FILA *fi){
  if (fi->ini != fi->fim) {
	int dado = fi->arr[fi->ini];
	//ini = (ini + 1) % MAX;
	fi->ini++;
	if (fi->ini == fi->MAX) fi->ini = 0;
	return dado;
  }
  else {
	printf("Não há elementos. Fila vazia.\n");
	exit(1);
  }
}

int tamanho(FILA *fi){
  if (fi->ini <= fi->fim)
	return fi->fim - fi->ini;
  else
	return fi->MAX - (fi->ini - fi->fim);
}

void imprimir(FILA *fi){
  printf("F[ ");
  for (int i = fi->ini ;  ; i++) {
	if (i == fi->MAX) i = 0;
	if (i == fi->fim) break;
	printf("%d ",fi->arr[i]);
  }
  printf("]\n");
}
