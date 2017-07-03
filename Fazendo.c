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

int search_sub_tree(No* arv, No* subarv){
  
  if(arv == NULL){
    return 0;
  }
  
  if((arv->n==subarv->n) && (arv->no_esq->n==subarv->no_esq->n ) && (arv->no_dir->n==subarv->no_dir->n)){
    return 1;
  }
  else{
    return (search_sub_tree(arv->no_esq,subarv) || search_sub_tree(arv->no_dir,subarv));
  }
}

No* insert_qlq_no(No* arv,int n){
  
    if(arv==NULL){
        return 0;
    }
    else{
        if(arv->n==n || search_tree(arv->no_esq,n) || search_tree(arv->no_dir,n)){
          return arv;
        }
    }
}

int arvores_iguais(No* arv1, No* arv2){
  
  if(arv1 == NULL && arv2 == NULL) return 1;
  
  if(arv1 == NULL || arv2 == NULL ){
    return 0;
  }
  else{
    return((arv1->n == arv2->n) && arvores_iguais(arv1->no_esq,arv2->no_esq) && arvores_iguais(arv1->no_dir,arv2->no_dir));
  } 
}

static int cont = 0;
  
int qnts_arvores(No* arv, No* subarv){

  if(arv->no_esq == NULL && arv->no_dir==NULL){
    return 0;
  }

  if(arvores_iguais(arv,subarv) == 1){
    cont++;
  }
  
  return(qnts_arvores(arv->no_esq,subarv) || qnts_arvores(arv->no_dir,subarv));
}

int main(){
    No *arv, *arv2,*teste;
    No* subarv;

    arv = inicializa();
    arv2 = inicializa();
    subarv = inicializa();
    teste = inicializa();
    
    arv = insert_tree(arv,8);
    arv = insert_tree(arv,5);
    arv = insert_tree(arv,12);
    arv = insert_tree(arv,23);
    arv = insert_tree(arv,11);
    
    arv2 = insert_tree(arv2,8);
    arv2 = insert_tree(arv2,5);
    arv2 = insert_tree(arv2,12);
    arv2 = insert_tree(arv2,23);
    arv2 = insert_tree(arv2,11);
    
    subarv = insert_tree(subarv,12);
    subarv = insert_tree(subarv,11);
    subarv = insert_tree(subarv,23);

    teste = insert_tree(teste,12);
    teste = insert_tree(teste,11);
    teste = insert_tree(teste,23);

    printf("\n\n######### MyArvore ########\n");
    printf("\nPre-Ordem\n");
    print_pre(arv);
    printf("\nPos-Ordem\n");
    print_pos(arv);
    printf("\nIn-Ordem\n");
    print_in(arv);
    printf("\n\n");
    printf("\nResultado da busca (Existe 1 | Nao 0) \n");
    printf("%d",search_tree(arv,7));
    
    printf("\n\n######### Sub-Arvore ########\n");
    printf("\nPre-Ordem\n");
    print_pre(subarv);
    printf("\nPos-Ordem\n");
    print_pos(subarv);
    printf("\nIn-Ordem\n");
    print_in(subarv);
    printf("\n\n");
    printf("\nResultado da busca da Sub-arvore na Arvore (Existe 1 | Nao 0) \n");
    printf("%d",search_sub_tree(arv,subarv));
    
    printf("\nArvores sao iguais ? (Sim 1 | Nao 0) \n");
    printf("%d\n", arvores_iguais(arv,arv2));
    
    printf("\n\n######### Nova Arvore ########\n");
    arv->no_esq = teste;
    printf("\nPre-Ordem\n");
    print_pre(arv);
    printf("\nPos-Ordem\n");
    print_pos(arv);
    printf("\nIn-Ordem\n");
    print_in(arv);
    printf("\n\n");
    
    
    printf("\nArvores sao iguais ? (Sim 1 | Nao 0) \n");
    printf("%d\n", arvores_iguais(arv,arv2));
    
    qnts_arvores(arv,subarv);
    printf("Quantas Sub-Arvores existem na Arvore principal ?\n");
    printf("%d", cont);
    printf("\n\n");
  

}
