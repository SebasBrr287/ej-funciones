#include <stdio.h>
#include "inventario.h"

int main() {

    char nombres[10][50];
    float precios[10];
    int numProductos;


    numProductos = ingresarDatos(nombres, precios);

    float total = calcularTotal(precios, numProductos);
    printf("\nValor total del inventario: $%.2f\n", total);

    float promedio = calcularPromedio(precios, numProductos);
    printf("Precio promedio de los productos: $%.2f\n", promedio);

    encontrarExtremos(nombres, precios, numProductos);

    buscarProducto(nombres, precios, numProductos);

    return 0;
}
