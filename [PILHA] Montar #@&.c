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

void push(Pilha* p, char letra){
  p->topo = inserir(p->topo,letra);
  printf("Botei %c\n", p->topo->x);
}

void pop(Pilha* p){
  printf("Tirei %c\n", p->topo->x);
  p->topo = remov_ini(p->topo);
}


void faz(Pilha* p, char* fazer, char* elem){
  int i=0;
  int j=0;

  while(fazer[i] != '\0'){
    if(fazer[i] == '#'){
      push(p,elem[j]);
      j++;
    }
    else if(fazer[i] == '@'){
      pop(p);
    }
    else if(fazer[i] == '&'){
      printf("O %c esta in the top of the world", p->topo->x);
    }
    i++;
  }

}

int main(){
    /*#PUSH | @POP | &TOP*/

    char fazer[20] = {"##@##@@&"};
    char elem[20] = {"BHFR"};

    Pilha* p = criar();

    faz(p,fazer,elem);
}
