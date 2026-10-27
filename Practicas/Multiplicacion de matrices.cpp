#include<iostream>
using namespace std;

int CrearMatriz(int, int);


int main(){
	int filasA,columnasA, filasB, columnasB;
	printf("Ingrese las filas de la matriz A: ");
	scanf("%d",&filasA);
	printf("Ingrese las columnas de la matriz A: ");
	scanf("%d",&columnasA);
	printf("Ingrese las filas de la matriz B: ");
	scanf("%d",&filasB);
	printf("Ingrese las columnas de la matriz B: ");
	scanf("%d",&columnasB);
	
	printf("\nMatriz A\n");
	int matrizA[filasA][columnasA]={CrearMatriz(filasA,columnasA)};
	printf("\nMatriz B\n");
	int matrizB[filasB][columnasB]={CrearMatriz(filasB,columnasB)};
	
	int matrizRes[filasA][columnasB];
	
	//Multiplicacion de matrices
	for(int i=0; i<filasA; i++){
		for(int j=0; j<columnasB; j++){
			matrizRes[i][j]=0;
			for(int k=0; k<columnasA; k++){
				matrizRes[i][j]+=matrizA[i][k]*matrizB[k][j];
			}
		}
	}
	cout<<"\nMatriz Resultante\n";
	for(int i=0; i<filasA; i++){
		printf("\n");
		for(int j=0; j<columnasA; j++){
			printf(" ",matrizA);
		}
	}
	/*
	//imprime la resultante
	cout<<"\nMatriz Resultante\n";
	for(int i=0; i<filasA; i++){
		printf("\n");
		for(int j=0; j<columnasB; j++){
			printf(" ",matrizRes[i][j]);
		}
	}*/
	
}


int  CrearMatriz(int f, int c){
	int matriz[f][c];
	for(int i=0; i<f; i++){
		for(int j=0; j<c; j++){
			printf("Elemento [%d,%d]\n",i+1,j+1);
			scanf("%d",&matriz[i][j]);
		}
	}
	return matriz[f][c];
}