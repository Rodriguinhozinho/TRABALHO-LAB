#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include "functions-PL403.h"

void ordenarvetor(int vetor[]){
	int i, j, troca;
        for (i=0 ; i<TAM ; i++){  //percorre os valores do vetor  até ao v[TAM]
                for(j=0 ; j< TAM-1 ;j++){ //percorre os valores vizinhos do vetor e compara-os
                         if (vetor[j]> vetor[j+1]){ //tecnica de organização chamada booble sort
                                 troca = vetor[j];
                                 vetor[j] = vetor[j+1];
                                 vetor[j+1]=troca;
                          }
                }
        }
}

void simetricovetor(int vetor[]){ 
        int i, simetrico[TAM];
	for(i=0; i<TAM; i++){   //para todos os valores do vetor vai trocca-los para o simétrico e introduzir os valor num vetor chamado simétrico
		simetrico[i]=-vetor[i];
	}
	ordenarvetor(simetrico); // invoca a funcao anterior que vai ordenar no vetor simetrico
	printf("Vetor simétrico ordenado:\n");
	for (i=0 ; i<TAM; i++){
		printf("%d ", simetrico[i]);
	}
}

void somavetor(int vetor[]){
        int i, soma;
        for (i=0; i < TAM/2 ; i++){ //vai percorrer os valores do vetor até á metade
                soma = vetor[i] + vetor[i+TAM/2]; //soma metade do vetor com a outra metade
                printf("%d ", soma);
        }
}

void multiplovetor(int vetor[]){
        int i;
        printf("Valores nas posições multiplas de 3:\n");
        for (i=0; i<TAM ; i++){    
                if (i%3==0){  //percorre a posicao dos vetor e vai verificar  se a posiçao é mutlipla de 3 e vai mostrar qual é a posição
                        printf(" Posição-%d: %d ", i, vetor[i]);
                }
        }
}

void aleatoriovetor(int vetor[]){
        int i;
	srand(time(NULL)); // acompanha o tempo da vida real para gerar uma "seed" nova a cada vez que o programa é executado
        i = rand() % TAM; //retorna o número aleatorio do vetor pois está limitado pelo %TAM
        printf ("Valor aletório do vetor: %d", vetor[i]);
}

void matrizvetor(int vetor[]){
        int i, j, matriz[TAM][TAM]; 
        for (i=0; i<TAM ; i++){ // percorre os valores da linha da matriz(i)
                for (j= 0; j<TAM; j++){ //percorre os valores da coluna da matriz (j)
                        matriz[i][j] = vetor[(j + i)%TAM]; //utilizando o vetor vai criar uma matriz de forma cicla para que esta seja permutada(%tam)
                }
        }
        printf("Matriz:\n");
        for (i=0;i<TAM; i++){
                for(int j=0; j<TAM; j++){
                        printf("%3d " , matriz[i][j]); //mostra a matriz
                }
        printf("\n");
        }
}

void raizvetor(int vetor[]){
        int i;
        float x;
        printf("Raiz Quadrada =\n");
        for(i=0; i<TAM; i++){
                if(vetor[i]<0){  //vai mostrar quais valores sao impossiveis de calcular a raiz , ou seja , os negativos
                        printf("Valor %d Inválido (negativo)\n", vetor[i]);
                        continue; // faz com que o programa não encerre com os numeros negativos
                }
                x = sqrt(vetor[i]);  //calcula a raiz usando uma funcao da biblioteca math.h
                printf("Valor = %d - Raiz = %.2f\n", vetor[i], x); // mostra qual a posição e  o valor da raiz dessa posição
        }
}

void ajuda(){ // função que serve apenas para mostrar a pagina de ajuda, está separada do programa main para não poluir tanto o código
printf("\n AJUDA DO PROGRAMA \n");
printf("1 - Ordena o vetor com base no simétrico (inverso dos sinais)\n");
printf("2 - Soma os elementos da primeira metade com os da segunda metade\n");
printf("3 - Mostra apenas as  posições múltiplas de 3 e o seu respetivo valor\n");
printf("4 - Retorna um elemento aleatório do vetor\n");
printf("5 - Cria uma matriz 14x14 com permutações do vetor\n");
printf("6 - Delvove a posição e o respetivo valor caso seja possivel calcular a raiz quadrada (valores negativos serão ignorados)\n");
printf("8 - Leitura de um novo vetor e devolução de um novo vetor que mistura metado primeiro vetor e metade do segundo");
printf("9 - Calculo e retorno do máximo divisor comum de dois números consecutivos do vetor\n");
printf("10 - Construção de uma matriz 14x14 que resultará do produto do vetor introduzido pelo utilizador , original, por esse mesmo vetor porém ordenado\n");
printf("0 - Encerra o programa\n");
}

void misturavetor(int vetor[]){
        int i, vetor2[TAM], vauxiliar[TAM]; // dois vetor novos , o que vai sair no resultado final (vetor2[TAM]) e um vetor que serve para auxiliar
        for (i=0; i<TAM; i++){ 
                printf("Intruza números inteiros entre -3 e 27 para o novo vetor:\n");
                scanf("%d" ,&vauxiliar[i]);
                if (vauxiliar[i]< -3 || vauxiliar[i]>27){ // valida a entrada do novo vetor
                        printf("Valor Inválido!");
                        i--; // caso o valor introduzido seja inválido não vai contar a vez para o ciclo for
                }
        }
        for (i=0; i<TAM/2; i++){
                vetor2[i]= vetor[i]; // coloca a primeira metade do vetor original no vetor que vai resultar no final
        }
        for(i= TAM/2; i<TAM; i++){ // coloca a segunda metade do vetor novo no vetor que vai resultar no final
                vetor2[i] =vauxiliar[i];
        }
        printf("Vetor misturado:\n");
        for (i=0 ; i<TAM; i++){
                printf("%d " , vetor2[i]);
        }
}

void mdcvetor(int vetor[]){
        int i, x, y, z, menor, mdc;
        for (i=0; i<TAM -1 ;i++){
                x = vetor[i]; //coloca cada valor do vetor na variavél x
                y= vetor[i+1]; //coloca cada valor seguido de x na variavél y
                if (x<0){ 
                        x = -x; //caso o valor seja negativo ,transforma o em positivo
                }
                if (y<0){
                        y=-y; //caso o valor seja negativo, transforma-o em positivo
                }
                if (x<y){ 
                        menor = x;
                }
                if (y<x){
                        menor =y;
                }
                for (z = menor ; z >=1 ;z--){
                        if (x% z == 0 && y % z == 0){
                                mdc= z;
                                break;
                        }
                }
        printf("Maximo divisor comum entre %d e %d = %d\n", vetor[i], vetor[i+1], mdc);
        }
}

void matriz2vetor(int vetor[]){
        int i, j, ordenado[TAM], original[TAM], matriz2[TAM][TAM];
        for (i=0;i<TAM;i++){
                ordenado[i]=vetor[i]; 
        }
        ordenarvetor(ordenado);
        for (i=0; i<TAM; i++){
                for(j=0; j<TAM; j++){
                        matriz2[i][j]= vetor[i] * ordenado[j];
                }
        }
        printf("Matriz:\n");
        for(i=0;i<TAM;i++){
                for(j=0;j<TAM ;j++){
                        printf("%3d ", matriz2[i][j]);
                }
        printf("\n");
        }
}

void transpostavetor(int vetor[]){
        int i, j, ordenado[TAM], original[TAM], matriz2[TAM][TAM];
        for (i=0;i<TAM;i++){
                ordenado[i]=vetor[i];
        }
        ordenarvetor(ordenado);
        for (i=0; i<TAM; i++){
                for(j=0; j<TAM; j++){
                        matriz2[i][j]= vetor[i] * ordenado[j];
                }
        }
        printf("Matriz:\n");
        for(i=0;i<TAM;i++){
                for(j=0;j<TAM ;j++){
                        printf("%3d ", matriz2[j][i]);
                }
        printf("\n");
        }
}
