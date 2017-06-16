#include <stdio.h>
#include <stdlib.h>

typedef struct elem{
    char x;
    struct elem *prox;
}Elem;

typedef struct pilha{
    Elem *topo;
}Pilha;

Pilha* criar(void){
  Pilha *p = (Pilha*) malloc(sizeof(Pilha));
  p->topo = NULL;
}

Elem* inserir(Elem* p, char c){
  Elem* l = (Elem*) malloc(sizeof(Elem));
  l->x = c;
  l->prox = p;
  return l;
}

Elem* remov_ini(Elem* l){
    Elem* p = l->prox;
    free(l);
    return p;
}

void pop(Pilha* p){
    while(p->topo != NULL){
      printf("%c", p->topo->x);
      p->topo = remov_ini(p->topo);
    }
    printf(" ");
}

void push(Pilha* p, char* frase){
    int i=0;

    while(frase[i] != '\0'){
      if(frase[i] != ' ') p->topo = inserir(p->topo,frase[i]);
      else pop(p);

      i++;
    }
    pop(p);
}

int main(){
  char teste[50] = {"Zeca Pagodinho do Arrocha"};
  Pilha* p = criar();

  push(p,teste);
}
