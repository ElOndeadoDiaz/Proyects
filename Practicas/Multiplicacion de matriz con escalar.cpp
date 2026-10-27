#include<iostream>
using namespace std;

int main(){
	int fil, col, esc;
	//Se pide las dimensiones de la matriz
	cout<<"Ingrese la fila de la matriz:\n";
	cin>>fil;
	cout<<"Ingrese la columna de la matriz:\n";
	cin>>col;
	
	//Matriz ingreso de datos
	int matriz[fil][col];
	
	for(int i=0; i<fil; i++){
		for(int j=0; j<col; j++){
			cout<<"Ingrese el dato para la fila "<<i+1<< ", columna "<<j+1<<": ";
			cin>>matriz[i][j];
		}
	}
	
	//Se pide el escalar
	cout<<"Ingrese el numero:\n";
	cin>>esc;
	
	//Multiplicacion de la matriz y el escalar
	for(int i=0; i<fil; i++){
		for(int j=0; j<col; j++){
			matriz[i][j]*=esc;
		}
	}
	
	//Se muestra el resultado
	cout<<"\n Matriz Resultante\n";
	for(int i=0; i<fil; i++){
		cout<<"\n";
		for(int j=0; j<col; j++){
			cout<<matriz[i][j]<<" ";
		}
	}
}