	#include<stdio.h>
	#include<stdlib.h>
	#define TAM 6
	
	int main(){
		
		//Declaração das variáveis
		char MoveRover[TAM];
		int i, posicao, contador = 0;
		
		//Entrada de Dados
		printf("Movimentando o Robo Rover: Digite D para movimentar para a Direita e E para movimentar para a Esquerda:\n");
		
		for(i=0;i<TAM;i++){
			printf("\nDigite o %i movimento: ",i+1);
			scanf("%c",&MoveRover[i]);
			fflush(stdin);
		}
		
		//Processamento
		for(i=0;i<TAM;i++){
						
		if(MoveRover[i]=='d' || MoveRover[i]=='D'){
			
			contador++;
			
		}else if(MoveRover[i]=='e' || MoveRover[i]=='E'){
							
			contador--;
		
		}
		
		if(contador < 0){
			
			contador = 0;	
		}
		
	}
		//Saída de Dados
		printf("\n\nA posicao do robo e: %i\n\n",contador);
					
		return 0;
			
	}
