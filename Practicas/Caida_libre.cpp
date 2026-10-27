#include <stdio.h>

// Definimos la constante de gravedad
#define G 9.81

// Función que calcula la posición en función del tiempo
double posicion(double h, double t) {
    return h - 0.5 * G * t * t;   // fórmula de caída libre
}

int main() {
    double h;        // altura inicial
    double dt_ms;    // diferencial de tiempo en milisegundos
    double t = 0;    // tiempo en segundos

    // Entrada de datos
    printf("Ingrese altura inicial (m): ");
    scanf("%lf", &h);
    printf("Ingrese diferencial de tiempo (ms): ");
    scanf("%lf", &dt_ms);

    // Conversión de milisegundos a segundos
    double dt = dt_ms / 1000.0;   // o bien, la conversión de milisegundos a segundos es multiplicar los msx10^-3

    // Hacemos la tabla
    printf("\nTiempo (s)\tAltura (m)\n");
    printf("-----------------------------\n");

    // Bucle hasta que el objeto llegue al suelo
    while(1) {
        double y = posicion(h, t);   // calculamos la altura
        if(y < 0) y = 0;             // ajustamos si pasa de cero
        printf("%.6f\t\t%.6lf\n", t, y);
        if(y <= 0) break;            // detenemos cuando toca el suelo
        t += dt;                     // avanzamos en el tiempo
    }

return 0;
}