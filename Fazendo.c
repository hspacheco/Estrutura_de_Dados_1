#include <stdio.h>
#include <stdlib.h>

typedef struct no{
    int n;
    struct no* no_esq;
    struct no* no_dir;
}No;                     /*CRIA ESTRUTURA DA ARVORE*/

No* inicializa(void){
    return NULL;
}

No* create_tree(int numero){
    No* arv = (No*)malloc(sizeof(No));
    arv->n = numero;
    arv->no_esq = NULL;   /*PONTEIROS PARA AS SUB-ARVORES APONTAM NULO*/
    arv->no_dir = NULL;
    return arv;
    
}

No* insert_tree_esq(No* Arvore, int n){
    No* tree = Arvore;

    if(tree == NULL){
        tree = create_tree(n); 
    }                          
    
    else tree->no_esq = insert_tree_esq(tree->no_esq,n); 

    return tree;

}

No* insert_tree_dir(No* Arvore, int n){
    No* tree = Arvore;

    if(tree == NULL){
        tree = create_tree(n); 
    }                          
    
    else tree->no_dir = insert_tree_dir(tree->no_dir,n); 

    return tree;

}


No* insert_tree(No* Arvore, int n){
    No* tree = Arvore;

    if(tree == NULL){
        tree = create_tree(n); //UNICO MOMENTO NO QUAL SERÁ CRIADA UMA NOVA
    }                          //ARVORE OU SUB ARVORE

    if(n > tree->n){
       tree->no_dir = insert_tree(tree->no_dir,n); /*CHAMADA RECURSIVA PARA SUB-ARVORE DA DIREITA*/
    }

    if(n < tree->n){
       tree->no_esq = insert_tree(tree->no_esq,n); /*CHAMADA RECURSIVA PARA SUB-ARVORE DA ESQUERDA*/
    }

    return tree;

}

int search_tree(No* arvore, int n){
    No* p=arvore;
    if(p==NULL){
        return 0;
    }
    else{
        return(p->n==n || search_tree(p->no_esq,n) || search_tree(p->no_dir,n));
        /*ESSA OPERACAO FAZ A SEQUENCIA DE BUSCAS NA ORDEM ESQ-DIR DE FORMA 
        QUAL A PRIMEIRA OPCAO SERA EXECUTADA DE FORMA RECURSIVA E INTERROMPERA
        CASO SEJA VERDADEIRA, JA QUE É USADO O OPERADOR LOGICO ||(OU)*/
    }
}


void print_pre(No* arvore){ /*RAIZ,SAE,SAD*/
     if(arvore != NULL){
        printf("%d ",arvore->n);
        print_pre(arvore->no_esq);
        print_pre(arvore->no_dir);
     }
}

void print_pos(No* arvore){ /*SAE,SAD,RAIZ*/
     if(arvore != NULL){
        print_pos(arvore->no_esq);
        print_pos(arvore->no_dir);
        printf("%d ",arvore->n);
     }
}


void print_in(No* arvore){ /*SAE,RAIZ,SAD*/
     if(arvore != NULL){
        print_in(arvore->no_esq);
        printf("%d ",arvore->n);
        print_in(arvore->no_dir);
     }
}

int search_sub_tree(No* arv){
  int x=3,y=7,z=2;
  if(arv == NULL){
    printf("Ta NULO esta bosta");
    return 0;
  }
  return( (arv->n == x && arv->no_esq->n==y && arv->no_dir->n==z) || search_sub_tree(arv->no_esq) || search_sub_tree(arv->no_dir));
}

void qntd_sub(No* arv){
  No* p = arv;
  
  while(p->no_esq != NULL && p->no_dir != NULL){
    
  }
}


int main(){
    No* arv;

    arv = inicializa();
    arv = insert_tree_dir(arv,5);
    arv = insert_tree_dir(arv,8);
    arv = insert_tree_dir(arv,3);
    arv = insert_tree_esq(arv,78);
    arv = insert_tree_esq(arv,31);
    
    
    printf("Pre-Ordem\n");
    print_pre(arv);
    printf("\n");
    printf("Pos-Ordem\n");
    print_pos(arv);
    printf("\n");
    printf("In-Ordem\n");
    print_in(arv);
    printf("\n\n");
    printf("Resultado da busca (Existe 1 | Nao 0) \n");
    printf("%d",search_tree(arv,7));
    
    
}
