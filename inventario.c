#include <stdio.h>
#include <string.h>
#include "inventario.h"

int ingresarDatos(char nombres[10][50], float precios[]) {
    int n;
    do {
        printf("¿Cuantos productos desea ingresar? (Max 10): ");
        scanf("%d", &n);
        if (n < 1 || n > 10) {
            printf("Error: El número de productos debe estar entre 1 y 10.\n");
        }
    } while (n < 1 || n > 10);
    
    for(int i = 0; i < n; i++) {
        printf("Nombre del producto %d: ", i + 1);
        scanf("%s", nombres[i]); 
        printf("Precio de %s: ", nombres[i]);
        scanf("%f", &precios[i]); 
    }
    return n; 
}

float calcularTotal(float precios[], int n) {
    float suma = 0;
    for(int i = 0; i < n; i++) {
        suma += precios[i];
    }
    return suma;
}

void encontrarExtremos(char nombres[10][50], float precios[], int n) {
    int posCaro = 0, posBarato = 0;
    for(int i = 1; i < n; i++) {
        if(precios[i] > precios[posCaro]) posCaro = i;
        if(precios[i] < precios[posBarato]) posBarato = i;
    }
    printf("\nProducto mas caro: %s ($%.2f)", nombres[posCaro], precios[posCaro]);
    printf("\nProducto mas barato: %s ($%.2f)\n", nombres[posBarato], precios[posBarato]);
}

float calcularPromedio(float precios[], int n) {
    if(n == 0) 
    return 0;
    return calcularTotal(precios, n) / n;
}

void buscarProducto(char nombres[10][50], float precios[], int n) {
    char objetivo[50];
    int hallado = 0;
    printf("\nIngrese el nombre del producto a buscar: ");
    scanf("%s", objetivo);
    
    for(int i = 0; i < n; i++) {

        int iguales = 1;
        int j = 0;
        while (nombres[i][j] != '\0' || objetivo[j] != '\0') {
            if (nombres[i][j] != objetivo[j]) {
                iguales = 0;
                break;
            }
            j++;
        }

        if(iguales == 1) {
            printf("¡Encontrado! El precio de %s es: $%.2f\n", nombres[i], precios[i]);
            hallado = 1;
            break; 
        }
    }
    if(!hallado) printf("El producto no existe en el inventario.\n");
}
