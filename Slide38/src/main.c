#include "tree.h"

int main() {

	system("clear");

	Tree *raiz;
	Record r;
	int tam;

	// char *a, *b;
	// a = "ava";
	// b = "ava";

	// int ret;

	// ret = memcmp(a, b, 5);

	// if(ret > 0)
	// 	printf("%s é maior do que %s\n", a, b);
	// else if(ret < 0)
	// 	printf("%s é menor do que %s\n", a, b);
	// else
	// 	printf("%s é igual a %s\n", a, b);

	char nome [13][20] = {
		"banana", "abacate", "abacaxi", "leite", "manteiga", "cenoura",
		"macarrao", "arroz", "feijao", "limao", "televisao", "computador", "celular"};
	
	raiz = createTree();

	// int vetor[] = {12, 7, 13, 23, 11, 3, 4, 8, 10, 99, 1, 17, 9};
	// tam = sizeof(vetor)/sizeof(vetor[0]);
	tam = sizeof(nome)/sizeof(nome[0]);

	Tree *aux;

	printf("ELEMENTOS ARVORE: {\n");
	for(int i=0; i < tam; i++) {
		r.key = i;
		r.palavra = nome[i];
		printf("%d ", r.key);
		printf("%s\n", r.palavra);
		insertItem(&raiz, r);
	}
	printf("}\n\n");
	
	printf("PRE ORDEN: {\n");
	preordem(raiz);
	
	printf("}\n\nCENTRAL: {\n");
	central(raiz);
	
	printf("}\n\nPOS ORDEN: {\n");
	posordem(raiz);

	char str[20] = "abacate";
	r.palavra = str;
	pesquisa(&raiz, &aux, r);

	printf("}\n\nCENTRAL: {\n");
	central(aux);

	printf("}\n");

	return EXIT_SUCCESS;
}