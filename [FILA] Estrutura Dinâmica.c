#include <stdio.h>
#include <stdlib.h>

/*FILA - FIFO - FIRST IN, FIRST OUT*/

typedef struct elem{
  int x;
  struct elem* prox;
}Elem;

typedef struct fila{
  Elem* ini;
  Elem* fim;
}Fila;

int vazia(Fila* f){
  return (f == NULL);
}

Fila* criar(void){
  Fila* f = (Fila*) malloc(sizeof(Fila));
  f->ini = NULL;
  f->fim = NULL;
  return f;
}

void inserir(Fila* f, int n){
  Elem* p = (Elem*) malloc(sizeof(Elem));
  p->x = n;
  p->prox = NULL;

  if(f->fim == NULL){
    f->ini = p;
    f->fim = p;
  }
  else if(f->fim != NULL){
    f->fim->prox = p;
  }
  f->fim = p;
}

void remover(Fila*f){
  if(vazia(f)){
    printf("Fila vazia\n");
    exit(1);
  }
  else{
    f->ini = f->ini->prox;
    if(f->ini == NULL){
      f->fim = NULL;
    }
  }
}

void imprime(Fila* f){
  Elem* p;
  for(p=f->ini;p!=NULL;p=p->prox){
    printf("%d ", p->x);
  }
}

int main(){
  Fila *f;

  f = criar();
  inserir(f,9);
  inserir(f,15);
  inserir(f,18);
  imprime(f);
  remover(f);
  imprime(f);

}
