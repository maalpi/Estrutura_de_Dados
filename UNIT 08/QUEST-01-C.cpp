#include <stdio.h>
#include <stdlib.h>

struct sNODE{
  unsigned col;
  unsigned dado;
  struct sNODE *prox;
};

struct sMATRIZ{
  int lin, col;
  struct sNODE **m;
};

struct sMATRIZ m;

void inicializar(unsigned t_lin, unsigned t_col);

void atribuir(unsigned lin, unsigned col, int dado);
int acessar(unsigned lin, unsigned col);

int tamanho();
void imprimir();
void apagar();

void diagonalP();
void diagonalS();

int main(void) {
     inicializar(10, 10);
  for (int i = 0, j = 9; i < 10;i++, j--){
    atribuir(i, i, i);
    atribuir(i, j, i);
  }
  diagonalP();
  diagonalS();
    
    return 0;
}

void inicializar(unsigned t_lin, unsigned t_col){
  m.lin = t_lin;
  m.col = t_col;
  m.m = (struct sNODE **) malloc(sizeof(struct sNODE *) * m.lin);

  for (int i = 0 ; i < m.lin ; i++)
	m.m[i] = NULL;
}

void atribuir(unsigned lin, unsigned col, int dado) {
  if (lin < m.lin && col < m.col) {
	struct sNODE *aux = m.m[lin], *ant = NULL;

	while (aux && col > aux->col) {
  	ant = aux;
  	aux = aux->prox;
	}

	if (aux && aux->col == col){
  	   if (dado == 0) {
    	      if (ant == NULL) m.m[lin] = aux->prox;
    	      else ant->prox = aux->prox;

    	   free(aux);

  	} else aux->dado = dado;

	} else if (dado != 0) {
  	   struct sNODE *novo = (struct sNODE *) malloc(sizeof(struct sNODE));
  	   novo->col = col;
  	   novo->dado = dado;
  	   novo->prox = aux;
  	   if (ant == NULL) m.m[lin] = novo;
  	   else ant->prox = novo;
	}

  } else {
	printf("Não é possível inserir elementos fora da Matriz.\n");
	exit(0);
  }
}

int acessar(unsigned lin, unsigned col) {
  if (lin < m.lin && col < m.col) {
	struct sNODE *aux = m.m[lin];

	while (aux && col > aux->col)
  	   aux = aux->prox;
    
	if (aux && col == aux->col)
  	return aux->dado;
    
	return 0;
  } else {
	printf("Não é possível acessar elementos fora da Matriz.\n");
	exit(0);
  }
}

int tamanho() {
  return m.lin * m.col;
}

void imprimir(){
  printf("M[\n");
  for (int i = 0 ; i < m.lin ; i++) {
	struct sNODE *aux = m.m[i];

	for (int j = 0 ; j < m.col ; j++) {
  	   if (aux && j == aux->col) {
    	      printf("%4d ",aux->dado);
    	      aux = aux->prox;
  	   } else printf("%4d ",0);
	}
	printf("\n");
  }
  printf("]\n");
}

void apagar(){
  for (int i = 0 ; i < m.lin ; i++) {
	struct sNODE *aux = m.m[i], *ant = NULL;

	while (aux) {
  	   ant = aux;
  	   aux = aux->prox;
  	   free(ant);
	}
  }
  free(m.m);
}   

void diagonalP(){
   printf("DP[\n");
  for (int i = 0 ; i < m.lin ; i++) {
	struct sNODE *aux = m.m[i];

	for (int j = 0 ; j < m.col ; j++) {
  	   if (aux && j == aux->col) {
             if (i == j){
    	      printf("%4d ",aux->dado);
             }
    	      aux = aux->prox;
  	   }else printf("    "); 
	}
	printf("\n");
    }
    printf("]\n");
}   

void diagonalS(){
   int n = m.col;
    
   printf("DS[\n");
  for (int i = 0 ; i < m.lin ; i++) {
	struct sNODE *aux = m.m[i];

	for (int j = 0 ; j < m.col ; j++) {
  	   if (aux && j == aux->col) {
             if (i  == ( n - 1 - j)){
    	      printf("%4d ",aux->dado);
             }
    	      aux = aux->prox;
  	   }else printf("    "); 
	}
	printf("\n");
    }
    printf("]\n");
}   
