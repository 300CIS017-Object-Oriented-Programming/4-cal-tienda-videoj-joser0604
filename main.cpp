//
// Created by Joser on 8/29/2025.
//
#include <iostream>
#include <string>
#include <iomanip>   // Para formateo de punto flotante
#include "Tienda.h"

using std::cout;
using std::cin;
using std::fixed;
using std::setprecision;

// ============================
// Funciones auxiliares del menú
// ============================
void mostrarMenuPrincipal()
{
    cout << "===== Tienda de Videojuegos - Menu Principal =====\n";
    cout << "1. Agregar juego al carrito\n";
    cout << "2. Ver subtotal del carrito\n";
    cout << "3. Finalizar y pagar\n";
    cout << "4. Cargar compra de demostracion\n";
    cout << "-1. Salir\n";
    cout << "Seleccione una opcion: ";
}

int leerOpcionMenu()
{
    int opcion;
    cin >> opcion;
    while (opcion < -1 || opcion > 4)
    {
        cout << "Opcion invalida. Intente de nuevo (-1 a 4): ";
        cin.clear();
        cin.ignore(10000, '\n');
        cin >> opcion;
    }
    return opcion;
}

// ============================
// Función principal
// ============================
int main()
{
    int codigos[MAX_JUEGOS] = {0};
    int cantidades[MAX_JUEGOS] = {0};
    int cantidadJuegosRegistrados = 0;

    int opcion = 0;
    do
    {
        mostrarMenuPrincipal();
        opcion = leerOpcionMenu();

        switch (opcion)
        {
        case 1:
            {
                agregarJuegoAlCarrito(codigos, cantidades, cantidadJuegosRegistrados);
                break;
            }
        case 2:
            {
                double subtotal = calcularSubtotalCarrito(codigos, cantidades, cantidadJuegosRegistrados);
                cout << fixed << setprecision(2);
                cout << "\nSubtotal actual: $" << subtotal << "\n\n";
                break;
            }
        case 3:
            {
                if (cantidadJuegosRegistrados == 0)
                {
                    cout << "\nNo hay juegos en el carrito.\n\n";
                    break;
                }

                double subtotal = calcularSubtotalCarrito(codigos, cantidades, cantidadJuegosRegistrados);
                int tipoCliente = leerTipoCliente();
                double porcentajeDescuento = obtenerPorcentajeDescuento(tipoCliente);
                double descuentosExtra = calcularDescuentosAdicionales(codigos, cantidades, cantidadJuegosRegistrados);

                mostrarResumenCompra(codigos, cantidades, cantidadJuegosRegistrados, porcentajeDescuento);

                double totalFinal = calcularTotalFinal(subtotal, porcentajeDescuento, descuentosExtra);

                cout << fixed << setprecision(2);
                cout << "Subtotal: $" << subtotal << "\n";
                cout << "Descuentos adicionales: $" << descuentosExtra << "\n";
                cout << "Total a pagar: $" << totalFinal << "\n\n";
                break;
            }
        case 4:
            {
                cargarCompraDemo(codigos, cantidades, cantidadJuegosRegistrados);
                break;
            }
        case -1:
            {
                cout << "\nSaliendo del sistema. Gracias por visitar la Tienda de Videojuegos!\n";
                break;
            }
        }
    }
    while (opcion != -1);

    return 0;
}
