/*
ta funcionando!
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
int verificarDiagonalSecundaria(char matriz[][COLUNA], char caracter);
void exibirGanhador(char caracter, int rodada, char jogador1, char jogador2);

int main(){
	int linha, coluna;
	char jogador1, jogador2, caracter, matriz[LINHA][COLUNA], validacao;
	int cont=2, i=0, parada;

	//exibindo regras
	printf("*****************JOGO DA VELHA**************\n\n");
	printf("Regras:\n\n");
	printf("Jogador 1 escolher uma FIGURA: X ou O.\n");
	printf("Jogador 2 fica com a outra figura.\n");
	printf("ALternadamente, os jogadores escolhem uma posicao ");
	printf("(escolhendo o numero da linha e da coluna) ");
	printf("de uma matriz 3x3.\n");
	printf("GANHA o jogador que formar uma sequencia (horizontal, vertical ou diagonal) ");	
	printf("primeiro, com suas respecticas figuras.\n");
	printf("EMPATA o jogo caso termine os espa�oes antes de um dos jogadores ");
	printf("completarem suas sequencias.\n\n");	
	printf("VAMOS COMECAR!\n\n");		
	system("pause"); 
	system("cls");	
	
	//preenchendo matriz com espa�o em branco
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
	
	system("pause");
	system("cls");
	
	do{
		printf("\nJogador 1: %c\t", jogador1);
		printf("Jogador 2: %c\t\n\n", jogador2);
		exibirMatriz(matriz);
		escolhendoPosicao(matriz, &cont, jogador1, jogador2);
		
		parada=validacaoVitoria(matriz, jogador1);
		if(parada==TRUE){
			validacao=jogador1;
		}else{
			parada=validacaoVitoria(matriz, jogador2);
			if(parada==TRUE){
				validacao=jogador2;
			}else{
				validacao=' ';
			}
		}		
		i++;
		exibirMatriz(matriz);
		system("pause");
		system("cls");
	}while((validacao!=jogador1)&&(validacao!=jogador2)&&(i<(LINHA*COLUNA)));
			
	exibirMatriz(matriz);
	exibirGanhador(validacao, parada, jogador1, jogador2);

	
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
			retorno=validacaoPosicao(matriz[linha][coluna]);
		}while(retorno==FALSE);						
		matriz[linha][coluna]=jogador1;	
		(*cont)--;					
	}else{
		do{
			printf("[Jogador 2]Escolha a linha:   ");
			scanf("%d",&linha);
			printf("[Jogador 2]Escolha a coluna:  ");
			scanf("%d",&coluna);
			retorno=validacaoPosicao(matriz[linha][coluna]);
		}while(retorno==FALSE);			
		matriz[linha][coluna]=jogador2;
		(*cont)++;
	}	
}
int validacaoPosicao(char caracter){
	
	if(caracter!=' '){
		printf("\nPosicao invalida!!!\nTente de novo\n\n ");
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
	if(verificarDiagonalSecundaria(matriz, caracter)==TRUE){
		return TRUE;	
	}
	return FALSE;	
}
int verificarLinha(char matriz[][COLUNA], char caracter){
	int i, j, cont=0;
	for(i=0;i<LINHA;i++){
		cont=0;
		for(j=0;j<COLUNA;j++){
			if(matriz[i][j]==caracter){
				cont++;
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
int verificarDiagonalSecundaria(char matriz[][COLUNA], char caracter){
	int j, cont=0;
	for(j=0;j<COLUNA;j++){
		if(matriz[j][j]==caracter){
			cont++;
		}
		if(cont==3){
			return TRUE;
		}
	}
	return FALSE;
}
void exibirGanhador(char caracter, int rodada, char jogador1, char jogador2){
	
	if(rodada==9){
		printf("**********DEU VELHA***********\n\n");
		printf("RESULTADO: EMPATE\n\n");
	}else{
		if(caracter==jogador1){
		printf("**********VITORIA***********\n\n");
		printf("RESULTADO: JOGADOR 1 VENCEU\n\n"); 
		}else{
			if(caracter==jogador2){
				printf("**********VITORIA***********\n\n");
				printf("RESULTADO: JOGADOR 2 VENCEU\n\n");
			}else{
				printf("**********DEU VELHA***********\n\n");
				printf("RESULTADO: EMPATE\n\n");
			}
			 
		}
	}
}
