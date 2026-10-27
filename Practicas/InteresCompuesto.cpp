#include <stdio.h>

double calcularInteresCompuesto(double, double, int);



int main() {
    double capitalInicial, tasa;
    int periodos;

    printf("CALCULADORA DE INTERES COMPUESTO\n");
    printf("================================\n\n");
    
    printf("Capital inicial: ");
    scanf("%lf", &capitalInicial);
    printf("Tasa de interes (ej: 0.05 para 5%%): ");
    scanf("%lf", &tasa);
    printf("Numero de periodos: ");
    scanf("%d", &periodos);

    if (capitalInicial <= 0 || tasa < 0 || periodos <= 0) {
        printf("Error: Todos los valores deben ser positivos\n");
        return 1;
    }

    double saldoFinal = calcularInteresCompuesto(capitalInicial, tasa, periodos);
    
    printf("\nSaldo final despues de %d periodos: %.2lf\n", periodos, saldoFinal);

return 0;
}






double calcularInteresCompuesto(double capitalInicial, double tasa, int periodos) {
    double capital = capitalInicial;
    
    printf("\n%s | %s | %s | %s\n", 
           "Periodo", "Capital Inicial", "Interes", "Capital Final");
    printf("--------------------------------------------------------------\n");

    for (int i = 1; i <= periodos; i++) {
        double interes = capital * tasa;
        double capitalFinal = capital + interes;

        printf("%7d | %14.2lf | %7.2lf | %13.2lf\n",i, capital, interes, capitalFinal);
		capital = capitalFinal;
    }
return capital;
}