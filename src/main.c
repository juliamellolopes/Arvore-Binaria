#include "tree.h"

int main(){
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