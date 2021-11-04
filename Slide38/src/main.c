#include "tree.h"

int main(){

	char reg[30][10] = {"arroz", "feijao", "macarrao", "frango", "ovo", "miojo", "suco", "leite", "amendoin",
	"biscoito", "toddy", "alface", "tomate", "cebola", "chips", "agua", "milho", "alho", "saumao", "chocolate",
	"farinha", "carne", "molho", "lasanha", "fricasse", "refri", "espumante", "massa", "batata", "couve"};

	Tree *raiz = CreateTree();
  	Tree *aux = CreateTree();
	Record r;
	int quant = 0, quantVet = 0;

  	printf("ELEMENTOS DA ARVORE: { ");
  	for(int i = 0; i < 30; i++){
		r.key = i;
		r.value = reg[i];
		insertTree(&raiz, r);
    	printf("%s ", reg[i]);
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

  	char str[10][10] = {"arroz","leite","brinquedo", "carne", "cadeira", "mesa", "ovo", "massa", "couve","cebola"};

	for(int i = 0; i < 10; i++){
		r.value = str[i];
		pesquisa(&raiz, &aux, r, &quant);
	}

	for (int i = 0; i < 10; i++){
		for(int j = 0; j <  30; j++){
			quantVet++;
			if(strcmp(reg[j], str[i]) == 0){
				break;
			}
		}
	}
	
	printf("Quantidade de pesquisa na arvore: %d\n", quant);
	printf("Quantidade de pesquisa no vetor: %d\n", quantVet);

}