#include<iostream>
using namespace std;

int main(){
    int fil, col, i, j, matriz[fil][col];
    
    cout<<"\t MATRIZ\n---------------------------------------------\n";
    
    cout<<"Ingrese el numero de filas:\n";
    cin>>fil;
    cout<<"Ingrese el nmumero de columnas:\n";
    cin>>col;
    
    for(i=0;i<fil;i++){
        for(j=0;j<col;j++){
            cout<<"Ingrese el dato para la fila "<<i+1<<" , columna "<<j+1<<": ";
            cin>>matriz[i][j];
        }
    }
    cout<<"\nMatriz:\n";
    for(i=0;i<fil;<i++){
        for(j=0;j<col;j++){
            cout<<matriz[i][j]<< " ";
            }
        }
    return 0;
}   
