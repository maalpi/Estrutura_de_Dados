#include <stdio.h>
#include <stdlib.h>

const unsigned MAX = 10;
int l[MAX], pos = 0;

void enqueue(int elemento);
int dequeue();

int tamanho();
void imprimir();
void apagar();
void getFront();

int main(void) {
    
    getFront();
    enqueue(20);
    enqueue(30);
    enqueue(40);
    imprimir();
    getFront();
    dequeue();
    getFront();
    imprimir();
    
  return 0;
}

void enqueue(int elemento){
  if (pos < MAX)
	l[pos++] = elemento;
  else
	printf("Não foi possível inserir %d. Fila cheia.\n",elemento);
}

int dequeue(){
  if (pos) {
	int dado = l[0];
	for (int i = 0 ; i < pos -1 ; i++)
  	l[i] = l[i+1];
	pos--;
	return dado;
  }
  else {
	printf("Não há elementos. Fila vazia.\n");
	exit(1);
  }
}

int tamanho(){
  return pos;
}

void imprimir(){
  printf("F[ ");
  for (int i = 0 ; i < pos ; i++)
	printf("%d ",l[i]);
  printf("]\n");
}

void apagar(){
  pos = 0;
}

void getFront(){
    if (!pos){
       printf("Nao ha elementos. Fila vazia.\n");
	   
    }else{
        printf("O primeiro elemento eh: %d\n",l[0]);
    }
}