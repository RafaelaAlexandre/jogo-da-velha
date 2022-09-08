/*
validando vitória
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
void escolhendoPosicao(char matriz[][COLUNA], int *cont, char jogador1, char jogador2);
int validacaoPosicao(char caracter);
int validacaoVitoria(char matriz[][COLUNA], char caracter);
int verificarLinha(char matriz[][COLUNA], char caracter);
int verificarColuna(char matriz[][COLUNA], char caracter);
int verificarDiagonalPrincipal(char matriz[][COLUNA], char caracter);


int main(){
	int linha, coluna;
	char jogador1, jogador2, caracter, matriz[LINHA][COLUNA], validacao;
	int cont=2, i=0, parada;
	
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
void escolhendoPosicao(char matriz[][COLUNA], int *cont, char jogador1, char jogador2){
	int linha, coluna, retorno;
	char caracter;
	if(*cont==2){
		do{
			printf("[Jogador 1]Escolha a linha:   ");
			scanf("%d",&linha);
			printf("[Jogador 1]Escolha a coluna:  ");
			scanf("%d",&coluna);
//				caracter=;
			retorno=validacaoPosicao(matriz[linha][coluna]);
		}while(retorno==FALSE);						
		matriz[linha][coluna]=jogador1;	
		(*cont)--;					
	}else{
		do{
			printf("[Jogador 2]Escolha a linha: ");
			scanf("%d",&linha);
			printf("[Jogador 2]Escolha a coluna: ");
			scanf("%d",&coluna);
//				caracter=;
			retorno=validacaoPosicao(matriz[linha][coluna]);
		}while(retorno==FALSE);			
		matriz[linha][coluna]=jogador2;
		(*cont)++;
	}	
}
int validacaoPosicao(char caracter){
	
	if(caracter!=' '){
		printf("posicao invalida!!!\nTente de novo\n ");
		return FALSE;
	}
	return TRUE;
}
int validacaoVitoria(char matriz[][COLUNA], char caracter){
	int i,  j;
	
	if(verificarLinha(matriz, caracter)==TRUE){
		return TRUE;	
	}
	if(verificarColuna(matriz, caracter)==TRUE){
		return TRUE;	
	}
	if(verificarDiagonalPrincipal(matriz, caracter)==TRUE){
		return TRUE;	
	}
//	if(verificarDiagonalSecundaria(matriz, caracter)==TRUE){
//		return TRUE;	
//	}
	return FALSE;	
}
int verificarLinha(char matriz[][COLUNA], char caracter){
	int i, j, cont=0;
	for(i=0;i<LINHA;i++){
		cont=0;
		for(j=0;j<COLUNA;j++){
			if(matriz[i][j]==caracter){
				cont++;
//				printf("%d", cont);
			}
		}
		if(cont==3){
			return TRUE;
		}
	}
	return FALSE;
}
int verificarColuna(char matriz[][COLUNA], char caracter){
	int i, j, cont;
	for(i=0;i<LINHA;i++){
		cont=0;
		for(j=0;j<COLUNA;j++){
			if(matriz[j][i]==caracter){
				cont++;
			}
		}
		if(cont==3){
			return TRUE;
		}
	}
	return FALSE;
}
int verificarDiagonalPrincipal(char matriz[][COLUNA], char caracter){
	int i, j, cont=0;
		for(i=0,j=COLUNA-1;j>=0;i++,j--){
			if(matriz[i][j]==caracter){
				cont++;
			}
		if(cont==3){
			return TRUE;
		}
	}
	return FALSE;
}

