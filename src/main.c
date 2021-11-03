#include "tree.h"
#include "slide37.c"
#include "slide38.c"

int main(){
	int opc;
	printf("Informe a opcao que deseja: /n");
	printf("1-slide27 \n 2-slide38");
	scanf("%d", &opc);

	switch(opc)
	{
	case 1:
		slide37();
		break;
	
	case 2:
		slide38();
		break;

	default:
		break;
	}
	
}