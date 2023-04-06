

#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

int nLinhas=8; 	//Quantidade de linha da Matriz
int nColunas=8; //Quantidade de Colunas da Matriz
int i=0,j=0;
char simb='*';
int pos1BloqLinha=0;
int pos1BloqColuna=2;
int posIniLinha=0;
int posIniColuna=0;
int posFimLinha=7;
int posFimColuna=7;
int l=0;
int c=0;
int desv_baixo=0;

/* Programa Principal */

int main(void){
	
	
char matriz[nLinhas][nColunas];	//Declaração da Matriz

//Matriz inicial sem posicionamento

	printf("Matriz Inicial\n "); 
	printf("\n");

	for (i=0;i<nLinhas;i++){
		for (j=0;j<nColunas;j++){
			if ((i==pos1BloqLinha) && (j==pos1BloqColuna)){
				matriz[i][j]='B';
			}else{matriz[i][j]=simb;
						}
		printf(" %c ",matriz[i][j]);
	}
		printf("\n"); // Quebra de linha 
	}
		printf("\n");
		
	//Matriz de posicionamentos
	
	for (l=posIniLinha;l<=posFimLinha;l++){       //l utilizado para incremento nas linhas
		for (c=posIniColuna;c<=posFimColuna;c++){	//c utilizado para incremento nas colunas
				printf("Matriz Posição Rover %i,%i\n ",l,c ); 
	printf("\n");

	for (i=0;i<nLinhas;i++){
		for (j=0;j<nColunas;j++){
			if ((i==l) && (j==c) && (matriz[i][j]!='B')) {
				matriz[i][j]='R';
				posIniColuna=c;
				
					if ((desv_baixo>0) && (matriz[i-1][j]!='B') && (matriz[i-1][j+1]!='B')){ // Analisa se ocorreu um desvio abaixo. Caso tenha ocorrido fica monitorando as posições superiores para verificar se pode retomar.
							l--;
							c--;
							desv_baixo--;
					}
							
					if ((matriz[i][j+1]=='B')){ // Caso a proxima posição da matriz esteja bloqueada incrementa 1 linha e acresce o contador de desvio abaixo
							l++;
							desv_baixo++;
					}
					
				
				
				
			}
		/*	if ((matriz[i][j]=='B')  ){//&& (matriz[i+1][j]!='B'
				matriz[i+1][j-1]='R';
				//posIniLinha++;
				//posFimLinha++;
			}
		*/
		printf(" %c ",matriz[i][j]);
	}
		printf("\n"); // Quebra de linha 
	}
	
		printf("\n");
	
		}
		
	}

	
	
	
	
    return 0;
}
