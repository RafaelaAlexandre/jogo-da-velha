/*
entrada de dados
*/
#include<stdio.h>
#include<ctype.h>
#include<stdlib.h>

#define TRUE 1
#define FALSE 0
#define LINHA 3
#define COLUNA 3

void exibirMatriz(char matriz[LINHA][COLUNA]);
void preencherMatriz(char matriz [][COLUNA]);
char receberDado(char caracter);

int main(){
	char matriz[LINHA][COLUNA];
	char jogador1,jogador2;	
	
	//preenchendo matriz com espaço em branco
	preencherMatriz(matriz);
	
	//validando entrada de dados
	do{
		printf("Escolha uma opcao: X ou O\n");
		printf("Jogador 1: ");		
		fflush(stdin);
		scanf("%c", &jogador1);
		jogador1=toupper(jogador1);
		
		jogador2=receberDado(jogador1);
				
	}while(jogador2==' ');
		
	printf("\njogador 1: %c\n", jogador1);
	printf("jogador 2: %c\n\n", jogador2);
	
	//exibindo a matriz vazia
	exibirMatriz(matriz);

	
	return 0;
}
void preencherMatriz(char matriz [][COLUNA]){
	int i, j;
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
char receberDado(char caracter){
	if(caracter=='X'){
		return 'O';
	}else{
		if(caracter=='O'){
			return 'X';
		}else{
			printf("INVALIDO!\nTENTE DE NOVO\n\n");
			return ' ';
		}
	}	
}

