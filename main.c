#include <stdio.h>
#include "inventario.h"

int main() {

    char nombres[10][50];
    float precios[10];
    int cantidad;

    cantidad = ingresarDatos(nombres, precios);

    if(cantidad > 0) {
        printf("\nRESULTADO\n ");
        printf("\nTotal en inventario: $%.2f", calcularTotal(precios, cantidad));
        printf("\nPrecio promedio: $%.2f", calcularPromedio(precios, cantidad));
        
        encontrarExtremos(nombres, precios, cantidad);
        buscarProducto(nombres, precios, cantidad);
    } else {
        printf("No hay productos registrados.\n");
    }

    return 0;
}