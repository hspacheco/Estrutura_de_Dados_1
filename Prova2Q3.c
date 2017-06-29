#include <stdio.h>
#include <stdlib.h>

/*PROBLEMA COM A FUNÇÃO IMPRIMIR DO FIM PARA O COMEÇO*/

typedef struct elem{
  int n;
  struct elem *ant;
  struct elem *prox;
}Elem;

typedef struct deque{
  Elem* ini;
  Elem* fim;
}Deque;

Deque* inicializa(void){
  Deque *f = (Deque*) malloc (sizeof(Deque));
  f->ini = NULL;
  f->fim = NULL;
  return f;
}

int vazia(Elem* l){
  return (l == NULL);
}

Elem* insere_ini(Elem* l, int x){
  Elem* p = (Elem*) malloc(sizeof(Elem));
  p->n = x;
  p->prox = l;
  p->ant = NULL;
  if(!vazia(l)){
    l->ant = p;
  }
  return p;
}

Elem* retira_ini(Elem* l){
  Elem* p = l->prox;
  if(vazia(p)){
    p->ant = NULL;
  }
  free(l);
  return p;
}

Elem* insere_fim(Elem* l, int x){
  Elem* p = (Elem*) malloc (sizeof(Elem));
  p->n = x;
  p->ant = l;
  p->prox = NULL;
  if(!vazia(l)){
    l->prox = l;
  }
  return p;
}

Elem* retira_fim(Elem* l){
  Elem* p = l->ant;
  if(vazia(p)){
    p->prox = NULL;
  }
  free(l);
  return p;
}

void insere_deque_ini(Deque* f, int x){
  f->ini = insere_ini(f->ini,x);
  if (vazia(f->fim)){
    f->fim = f->ini;
  }
}

void insere_deque_fim(Deque* f, int x){
  f->fim = insere_fim(f->fim,x);
  if(vazia(f->ini)){
    f->ini = f->fim;
  }
}

void deque_retira_ini(Deque* f){
  if(vazia(f->fim)){
    printf("Fila vazia\n");
    exit(1);
  }

  f->ini = retira_ini(f->ini);
  if(vazia(f->ini)){
    f->fim = NULL;
  }
}

void deque_retira_fim(Deque* f){
  if(vazia(f->ini)){
    printf("Fila vazia\n");
    exit(1);
  }

  f->fim = retira_fim(f->fim);
  if(vazia(f->fim)){
    f->ini = NULL;
  }
}

void imprime_do_fim(Deque* f){
  Elem *p;
  for(p=f->fim;p!=NULL;p=p->ant){
    printf("%d ", p->n);
  }
  printf("\n");
}

void imprime_do_ini(Deque* f){
  Elem *p;
  for(p=f->ini;p!=NULL;p=p->prox){
    printf("%d ", p->n);
  }
  printf("\n");
}

Deque* novo_deque(Deque* d){
  Deque *p = d;
  Elem *iaux, *faux;

  iaux = p->ini;
  faux = p->fim;

  faux->prox = iaux->prox;
  iaux->prox->ant = faux;

  faux->ant->prox = iaux;
  iaux->ant = faux->ant->prox;
  iaux->prox = NULL;

  p->ini = faux;
  p->fim = iaux;

  return p;

}

int main(){
  Deque *p, *teste;

  p = inicializa();
  insere_deque_ini(p,9);
  insere_deque_ini(p,10);
  insere_deque_ini(p,18);

  printf("Começo para o Fim\n");
  imprime_do_ini(p);
  printf("Fim para o Começo\n");
  imprime_do_fim(p);

  teste = novo_deque(p);
  imprime_do_ini(teste);


}
