#include<stdio.h>
#include<stdlib.h>
#define TAM 6

int main(){
	
	char MoveRover[TAM];
	int i, posicao = 0, posicaoatual = 0, posicaoanterior = 0;
	
	
	printf("Movimentando o Robo Rover: Digite D para movimentar para a Direita e E para movimentar para a Esquerda:\n");
	
	for(i=0;i<TAM;i++){
		printf("\nDigite o %i movimento: ",i+1);
		scanf("%c",&MoveRover[i]);
		fflush(stdin);
	}
	
	for(i=0;i<TAM;i++){	
		
	if((MoveRover[i]=='d' || MoveRover[i]=='D') && (posicao % TAM < 3)){
				
		posicaoanterior = posicao;
		posicao = posicaoanterior + 1;		
	/*	posicaoatual = posicaoanterior + posicao;
	/*	posicaoanterior = posicaoatual - posicao;	*/
	}
	
	if((MoveRover[i]=='e' || MoveRover[i]=='E') && (posicao % TAM > 0 )){
			
		posicaoanterior = posicao;
		posicao = posicaoanterior - 1;		
	/*	posicaoatual = posicaoanterior + posicao;*/
	}
	
	if((MoveRover[i]=='c' || MoveRover[i]=='C') && (posicao % TAM > 3)){
								
		posicaoanterior = posicao;
		posicao = posicaoanterior - 4;		
	/*	posicaoatual = posicaoanterior + posicao;*/
	}
	
	if((MoveRover[i]=='b' || MoveRover[i]=='B') && (posicao < (TAM*(TAM-1)))){
				
		posicaoanterior = posicao;
		posicao = posicaoanterior + 4;		
	/*	posicaoatual = posicaoanterior + posicao;*/
	}
	
	/*if((posicao < 0 ) && (posicao < TAM * (TAM - 1))){
		
		posicao = posicaoanterior;
	}*/
	
}
	
	printf("\n\nA posicao do robo e: %i\n\n",posicao);
			
	return 0;
		
}