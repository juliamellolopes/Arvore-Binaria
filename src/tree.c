#include "tree.h"

Tree* CreateTree(){
	return NULL;
}

void insertTree(Tree **t, Record r){

  if(*t == NULL){
    *t = (Tree*)malloc(sizeof(Tree));
    (*t)->esq = NULL; 
    (*t)->dir = NULL; 
    (*t)->reg = r; 
  
  } else {
    
    if(r.key < (*t)->reg.key){
      insertTree(&(*t)->esq, r);
    }
    
    if(r.key > (*t)->reg.key){
      insertTree(&(*t)->dir, r);
    }
  
  }

}

void pesquisa(Tree **t, Tree **aux, Record r){

  if(*t == NULL){
    printf("[ERROR]: Node not found!");
    return;
  }

  if((*t)->reg.key > r.key){ pesquisa(&(*t)->esq, aux, r); return;}
  if((*t)->reg.key < r.key){ pesquisa(&(*t)->dir, aux, r); return;}

  *aux = *t;
}


int isInTree(Tree *t, Record r) {
  
  if(t == NULL){ 
    return 0;
  }
  
  return t->reg.key == r.key || isInTree(t->esq, r) || isInTree(t->dir, r);
}


void antecessor(Tree **t, Tree *aux){ 

	if ((*t)->dir != NULL){ 
		antecessor(&(*t)->dir, aux);
		return;
  }
  	
  aux->reg = (*t)->reg;
  aux = *t; 
  *t = (*t)->esq;
  free(aux);
} 


void removeTree(Tree **t, Record r){
	Tree *aux;
  	
  	if (*t == NULL){ 
  		printf("[ERROR]: Record not found!!!\n");
    	return;
  	}

  	if (r.key < (*t)->reg.key){ removeTree(&(*t)->esq, r); return; }
  	if (r.key > (*t)->reg.key){ removeTree(&(*t)->dir, r); return; }

  	if ((*t)->dir == NULL){ 
  		aux = *t;  
  		*t = (*t)->esq;
    	free(aux);
    	return;
  	}

  	if ((*t)->esq != NULL){ antecessor(&(*t)->esq, *t); return; }

  	aux = *t;  
  	*t = (*t)->dir;
  	free(aux);
}

void preordem(Tree *t)
{
  if(!(t == NULL)){
    printf("%d ", t->reg.key);
    preordem(t->esq); 
    preordem(t->dir); 
  }
}


void central(Tree *t)
{
  if(!(t == NULL)){
    central(t->esq); 
    printf("%d ", t->reg.key);
    central(t->dir); 
  }
}

void posordem(Tree *t)
{
  if(!(t == NULL)){
    posordem(t->esq); 
    posordem(t->dir); 
    printf("%d ", t->reg.key);
  }
}

void slide37(){
  int reg[13] = {12,7,13,23,11,3,4,8,10,99,1,17,9};
	Tree *raiz = CreateTree();
	Record r;

  printf("ELEMENTOS DA ARVORE: { ");
  for(int i = 0; i < 13; i++){
		r.key = reg[i];
		r.value = 1;
		insertTree(&raiz, r);
    printf("%d ", reg[i]);
	}
  printf("}\n\n");

  r.key = 23;
	removeTree(&raiz, r);

	printf("REMOVE 23 E IMPRIME A ARVORE  ");
	printf("METODO CENTRAL: { ");
	central(raiz);
	printf("}\n\n");
  printf("METODO PRE-ORDEM: { ");
	preordem(raiz);
  printf("}\n\n");
  printf("METODO POS-ORDEM: { ");
	posordem(raiz);
  printf("}\n\n");

	r.key = 11;
	removeTree(&raiz, r);

	printf("REMOVE 11 E IMPRIME A ARVORE { ");
	printf("METODO CENTRAL: { ");
	central(raiz);
	printf("}\n\n");
  printf("METODO PRE-ORDEM: { ");
	preordem(raiz);
  printf("}\n\n");
  printf("METODO POS-ORDEM: { ");
	posordem(raiz);
  printf("}\n\n");

	r.key = 12;
	removeTree(&raiz, r);

	printf("REMOVE 12 E IMPRIME A ARVORE { ");
	printf("METODO CENTRAL: { ");
	central(raiz);
	printf("}\n\n");
  printf("METODO PRE-ORDEM: { ");
	preordem(raiz);
  printf("}\n\n");
  printf("METODO POS-ORDEM: { ");
	posordem(raiz);
  printf("}\n\n");

	r.key = 8;
	removeTree(&raiz, r);

	printf("REMOVE 8 E IMPRIME A ARVORE { ");
	printf("METODO CENTRAL: { ");
	central(raiz);
	printf("}\n\n");
  printf("METODO PRE-ORDEM: { ");
	preordem(raiz);
  printf("}\n\n");
  printf("METODO POS-ORDEM: { ");
	posordem(raiz);
  printf("}\n\n");
}

void slide38(){
  char reg[5] = {
    "arroz", "feijao", "macarrao", "frango", "ovo"};
	Tree *raiz = CreateTree();
  Tree *aux = CreateTree();
	Record r;

  printf("ELEMENTOS DA ARVORE: { ");
  for(int i = 0; i < 5; i++){
		r.key = reg[i];
		r.value = 1;
		insertTree(&raiz, r);
    printf("%d ", reg[i]);
	}
  printf("}\n\n");

	printf("IMPRIMIR METODO CENTRAL: { ");
	central(raiz);
	printf("}\n\n");

  printf("IMPRIMIR METODO PRE-ORDEM: { ");
	preordem(raiz);
  printf("}\n\n");

  printf("IMPRIMIR METODO POS-ORDEM: { ");
	posordem(raiz);
  printf("}\n\n");

  r.key = "arroz";
	pesquisa(&raiz, &aux, r);
  printf("%s", aux);

  
}
