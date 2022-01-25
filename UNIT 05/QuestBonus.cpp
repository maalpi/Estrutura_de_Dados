#include <stdio.h>
#include <stdlib.h>

struct sNODE{
  int dado;
  struct sNODE *prox;
};

struct sFILA{
  struct sNODE *ini, *fim;
};

typedef struct sFILA FILA;
typedef struct sNODE NODE;

void criar(FILA *fi);
void apagar(FILA *fi);

void inserir_ini(FILA *fi,int dado);
void inserir_fim(FILA *fi, int dado);

int remover_ini(FILA *fi);
int remover_fim(FILA *fi);

int tamanho(FILA *fi);
void imprimir(FILA *fi);

int main(){
  FILA fila1;
  criar(&fila1);

  inserir_fim(&fila1, 100);
  inserir_fim(&fila1, 200);
  inserir_ini(&fila1, 50);
  inserir_ini(&fila1, 25);
  inserir_fim(&fila1,400);

  imprimir(&fila1);

  printf("Removendo elemento inicial -> %d da fila\n",remover_ini(&fila1));

  printf("Removendo elemento final -> %d da fila\n",remover_fim(&fila1));
  printf("Removendo elemento final -> %d da fila\n",remover_fim(&fila1));

  printf("Removendo elemento inicial -> %d da fila\n",remover_ini(&fila1));

  imprimir(&fila1);

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

void inserir_ini(FILA *fi, int dado){
  NODE *novo = (NODE*) malloc(sizeof(NODE));
  novo->dado = dado;
  novo->prox = NULL;

  if (!fi->ini)
	fi->ini = fi->fim = novo;
  else{
    novo->prox = fi->ini;
    fi->ini = novo;
  }
}

void inserir_fim(FILA *fi, int dado){
  NODE *novo = (NODE*) malloc(sizeof(NODE));
  novo->dado = dado;
  novo->prox = NULL;

  if (!fi->ini)
	fi->ini = fi->fim = novo;
  else{
	fi->fim->prox = novo;
	fi->fim = novo;
  }
}


int remover_ini(FILA *fi){
    if (fi->ini) {
	int dado = fi->ini->dado;
	struct sNODE *tmp = fi->ini;
    
	if (fi->ini == fi->fim)
  	   fi->ini = fi->fim = NULL;
	else
  	   fi->ini = fi->ini->prox;

	free(tmp);

	return dado;
  }
  else {
	printf("Não há elementos. Fila vazia.\n");
	exit(1);
  }
}

int remover_fim(FILA *fi){
    int x = tamanho(fi);
    NODE *aux = fi->ini,*ant = NULL;

    if (fi->ini) {
	    int cont = 1,dado;
        while(aux){
            dado = aux->dado;
            if (cont == x){
    	        if (fi->ini == fi->fim)
  	                fi->ini = fi->fim = NULL;
	            else
                    ant->prox = NULL;
                    fi->fim = ant;

	            free(aux);
	            return dado;
            }
        ant = aux;
        aux = aux->prox;
        
        cont++;    
        }
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
 
  return tam;
}

void imprimir(FILA *fi){
  NODE *aux = fi->ini;
 
  printf("F[ ");
  while (aux){
	printf("%d ", aux->dado);
	aux = aux->prox;
  }
  printf("]\n");
}
