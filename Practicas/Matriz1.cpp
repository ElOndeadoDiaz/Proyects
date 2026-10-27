#include <iostream>

using namespace std;

int main() {
  
  int filas, columnas; 
 
  cout << "Ingrese el numero de filas: ";
  cin >> filas;
  cout << "Ingrese el numero de columnas: ";
  cin >> columnas;
  
   int matriz[filas][columnas];
 
  for (int i = 0; i < filas; i++) {
    for (int j = 0; j < columnas; j++) {
      cout << "Ingrese el dato para la fila " << i + 1 << ", columna " << j + 1 << ": ";
      cin >> matriz[i][j];
    }
  }

  cout << "\nMatriz:\n";
  for (int i = 0; i < filas; i++) {
    for (int j = 0; j < columnas; j++) {
      cout << matriz[i][j] << " ";
    }
    cout << endl;
  }

  return 0;
}