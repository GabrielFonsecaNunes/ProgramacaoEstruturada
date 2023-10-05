// Gabriel da Fonseca Nunes 11201921456
#include <stdio.h>

float CelsiusToFahrenheit(float c) {
    return (float) (9 * c / 5) + 32;
}

float FahrenheitToCelius(float f) {
    return (float) (5 / 9) * (f - 32) ;
}

void main() {
    float temp;

    printf("Informe valores em Celsius para conversão em Fahrenheit:");
    scanf("%f", &temp);
    printf("Fahrenheit: %f\n", CelsiusToFahrenheit(temp));

    printf("Informe valores em Fahrenheit para conversão em Celsius:");
    scanf("%f", &temp);
    printf("Fahrenheit: %f\n", CelsiusToFahrenheit(temp));
}