/*
inicio
*/
#include<stdio.h>

#define LINHA 3
#define COLUNA 3
void exibirMatriz(char matriz[LINHA][COLUNA]);
void criarEspaco(char matriz[LINHA][COLUNA]);

int main(){
	char matriz[LINHA][COLUNA];
	
	criarEspaco(matriz);
	exibirMatriz(matriz);

	
	return 0;
}
//void exibirMatriz(char matriz[LINHA][COLUNA]){
//	int i,j;
//	for(i=0;i<LINHA;i++){
//		for(j=0;j<COLUNA;j++){
//			printf("%c\t|",matriz[i][j]);
//		}
//		printf("\n");
//	}
//}
void criarEspaco(char matriz[LINHA][COLUNA]){
	int i,j;
	for(i=0;i<LINHA;i++){
		for(j=0;j<COLUNA;j++){
			matriz[i][j]=' ';	
		}
	}
}
void exibirMatriz(char matriz[][COLUNA]){
	int i, j;
	printf("     0    1    2\n\n");
	for(i=0;i<LINHA;i++){
		printf("%d  ",i);
		for(j=0;j<COLUNA;j++){
			printf("  %c ", matriz[i][j]);
			if(j<2){
				printf("|");
			}
		}
		if(i<2){
			printf("\n   ---------------\n");
		}	
	}
	printf("\n\n");
}

