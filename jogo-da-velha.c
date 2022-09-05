/*
inicio
*/
#include<stdio.h>

#define LINHA 2
#define COLUNA 2

void exibirMatriz(char matriz[LINHA][COLUNA]);

int main(){
	char matriz[LINHA][COLUNA];
	
	exibirMatriz(matriz);

	
	return 0;
}
void exibirMatriz(char matriz[LINHA][COLUNA]){
	int i,j;
	for(i=0;i<LINHA;i++){
		for(j=0;j<COLUNA;j++){
			printf("%c\t|",matriz);
		}
		printf("\n");
	}
}
