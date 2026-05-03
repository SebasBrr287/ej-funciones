#include <stdio.h>
#include <string.h>
#include "inventario.h"


int ingresarDatos(char nombres[10][50], float precios[]) {
    int n;
    
    do {
        printf("¿Cuantos productos desea ingresar? (1-10): ");
        scanf("%d", &n);
        
        if (n < 1 || n > 10) {
            printf("Error: El numero debe estar entre 1 y 10.\n");
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
}

float calcularTotal(float precios[], int n) {
    float suma = 0;
    for(int i = 0; i < n; i++) {
        suma = suma + precios[i];
    }
    return suma;
}

void encontrarExtremos(char nombres[10][50], float precios[], int n) {
    int posCaro = 0;
    int posBarato = 0;

    for(int i = 1; i < n; i++) {
        if(precios[i] > precios[posCaro]) {
            posCaro = i;
        }
        if(precios[i] < precios[posBarato]) {
            posBarato = i;
        }
    }
    printf("\nMas caro: %s ($%.2f)", nombres[posCaro], precios[posCaro]);
    printf("\nMas barato: %s ($%.2f)\n", nombres[posBarato], precios[posBarato]);
}

float calcularPromedio(float precios[], int n) {
    if(n == 0) return 0;
    return calcularTotal(precios, n) / n;
}

void buscarProducto(char nombres[10][50], float precios[], int n) {
    char objetivo[50];
    int hallado = 0;

    printf("\nNombre a buscar: ");
    scanf("%s", objetivo);
    
    for(int i = 0; i < n; i++) {
        int iguales = 1;
        
        
        for(int j = 0; nombres[i][j] != '\0' || objetivo[j] != '\0'; j++) {
            if(nombres[i][j] != objetivo[j]) {
                iguales = 0; // Encontramos una letra distinta
                break;
            }
        }

        if(iguales == 1) {
            printf("¡Encontrado! Precio: $%.2f\n", precios[i]);
            hallado = 1;
            break; 
        }
    }

    if(hallado == 0) printf("Producto no existe.\n");
}
