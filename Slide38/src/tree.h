#ifndef TREE_H 
#define TREE_H

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct Record Record;
typedef struct Tree Tree;

struct Record{
	int key;
	char *value;
};

struct Tree{
	Record reg;
	Tree *esq, *dir;
};

Tree* CreateTree();
void insertTree(Tree **t, Record r);
void pesquisa(Tree **t, Tree **aux, Record r, int *quant);
int isInTree(Tree *t, Record r);

void removeTree(Tree **t, Record r);
void antecessor(Tree **t, Tree *aux);

void preordem(Tree *t);
void central(Tree *t);
void posordem(Tree *t);

void pesquisaRAM(Tree **t, Tree **aux, Record r);

#endif
