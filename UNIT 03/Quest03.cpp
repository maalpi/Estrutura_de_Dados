

#include <stdio.h>
#include <stdlib.h>

struct sNODE{
  int dado;
  struct sNODE *ant;
  struct sNODE *prox;
};

struct sLISTA{
  struct sNODE *ini, *fim;
};

typedef struct sLISTA LISTA;
typedef struct sNODE NODE;

void inicializar(LISTA *lst);
void apagar(LISTA *lst);

void inserir_ord(LISTA *lst, int dado);
void remover(LISTA *lst, int dado);
NODE *buscar(LISTA *lst, int dado);

int obter(NODE *node);
int tamanho(LISTA *lst);
void imprimir(LISTA *lst);

void reverse(LISTA *node);

int main(){
  LISTA lst;
  inicializar(&lst);

  inserir_ord(&lst, 100);
  inserir_ord(&lst, 200);
  inserir_ord(&lst, 300);
  inserir_ord(&lst, 250);

  imprimir(&lst);

  reverse(&lst);
  imprimir(&lst);

  apagar(&lst);

  return 0;
}

void inicializar(LISTA* lst){
  lst->ini = lst->fim = NULL;
}

void apagar(LISTA* lst){
  NODE *aux = lst->ini, *ant;
 
  while (aux){
	ant = aux;
	aux = aux->prox;
	free(ant);
  }
  lst->ini = lst->fim = NULL;
}

void inserir_ord(LISTA *lst, int dado){
  NODE *novo = (NODE*) malloc(sizeof(NODE));
  NODE *aux = lst->ini;

  int dados = dado;
  novo->dado = dado;
  novo->prox = NULL;
  novo->ant = NULL;

 while (aux && dado < aux->dado){
      aux = aux->prox; 
  }
  if (!lst->ini){
	lst->ini = lst->fim = novo;
  }else if (aux == lst->ini){
    novo->prox = lst->ini;
	  lst->ini->ant = novo;
	  lst->ini = novo;
  }
  else if(!aux){
    lst->fim->prox = novo;
	  novo->ant = lst->fim;
	  lst->fim = novo;
  }
  else{
    aux->ant->prox = novo;
	  novo->ant = aux->ant;
	  novo->prox = aux;
	  aux->ant = novo;
  }
}

NODE *buscar(LISTA *lst,int dado){
   NODE *aux = lst->ini;

  while (aux){
	if (dado == aux->dado)
  	    return aux;
	aux = aux->prox;
  }

  return NULL;
}

void remover(LISTA *lst, int dado){
  NODE *aux = buscar(lst,dado);

  	if (aux == lst->ini)
    	lst->ini = lst->ini->prox;
  	else if(aux == lst->fim){
    	aux->ant->prox = NULL;
    	lst->fim = aux->ant;
  	} else
    	aux->ant->prox = aux->prox;
 	 
  	free(aux);
  	return;
	
}

int obter(NODE *node){
  if (!node){
	printf("Erro ao obter dado. Ponteiro invalido.");
	exit(0);
  }
 
  return node->dado;
}

int tamanho(LISTA *lst){
  NODE *aux = lst->ini;
  int tam = 0;
 
  while (aux){
	tam++;
	aux = aux->prox;
  }
 
  return tam;
}

void imprimir(LISTA *lst){
  NODE *aux = lst->ini;
 
  printf("[ ");
  while (aux){
	printf("%d ", aux->dado);
	aux = aux->prox;
  }
  printf("]\n");
}

void reverse(LISTA *lst) {
    
    if (*lst == NULL) return;

    NODE *aux = lst->ini, *ant;

    ant = aux->prox;

    if (ant == NULL) return;
    reverse(&ant);
    
    aux->prox->prox = aux;
    aux->prox = NULL;
    aux = ant;
}
