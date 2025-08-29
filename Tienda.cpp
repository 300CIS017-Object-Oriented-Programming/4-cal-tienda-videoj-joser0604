//
// Created by Joser on 8/29/2025.
//
#include "Tienda.h"
#include <iostream>
using namespace std;

// =====================
// Catálogo de Juegos
// =====================

// Constantes de precios
const int PRECIO_ACCION1   = 200000;
const int PRECIO_ACCION2   = 250000;
const int PRECIO_ACCION3   = 180000;

const int PRECIO_AVENTURA1 = 220000;
const int PRECIO_AVENTURA2 = 270000;
const int PRECIO_AVENTURA3 = 210000;

const int PRECIO_DEPORTE1  = 230000;
const int PRECIO_DEPORTE2  = 260000;
const int PRECIO_DEPORTE3  = 240000;

const int PRECIO_ESTRATEGIA1 = 190000;
const int PRECIO_ESTRATEGIA2 = 200000;
const int PRECIO_ESTRATEGIA3 = 210000;


// =====================
// Funciones principales
// =====================

void mostrarCatalogoJuegos()
{
    cout << "\n===== Catálogo de Videojuegos =====\n";
    cout << "1. Accion - Doom Eternal (PC)       $" << PRECIO_ACCION1 << "\n";
    cout << "2. Accion - God of War (PS5)        $" << PRECIO_ACCION2 << "\n";
    cout << "3. Accion - Halo Infinite (Xbox)    $" << PRECIO_ACCION3 << "\n";

    cout << "4. Aventura - Zelda BOTW (Switch)   $" << PRECIO_AVENTURA1 << "\n";
    cout << "5. Aventura - Uncharted (PS5)       $" << PRECIO_AVENTURA2 << "\n";
    cout << "6. Aventura - Tomb Raider (PC)      $" << PRECIO_AVENTURA3 << "\n";

    cout << "7. Deportes - FIFA 25 (PS5)         $" << PRECIO_DEPORTE1 << "\n";
    cout << "8. Deportes - NBA 2K25 (Xbox)       $" << PRECIO_DEPORTE2 << "\n";
    cout << "9. Deportes - F1 25 (PC)            $" << PRECIO_DEPORTE3 << "\n";

    cout << "10. Estrategia - Age of Empires IV (PC) $" << PRECIO_ESTRATEGIA1 << "\n";
    cout << "11. Estrategia - Civilization VI (PC)   $" << PRECIO_ESTRATEGIA2 << "\n";
    cout << "12. Estrategia - Fire Emblem (Switch)   $" << PRECIO_ESTRATEGIA3 << "\n";
    cout << "===================================\n";
}

int leerCodigoJuego()
{
    cout << "Ingrese el código del juego (1-12): ";
    int codigo;
    cin >> codigo;
    while (codigo < 1 || codigo > 12)
    {
        cout << "Código inválido. Intente de nuevo (1-12): ";
        cin.clear();
        cin.ignore(10000, '\n');
        cin >> codigo;
    }
    return codigo;
}

int leerCantidadJuegos()
{
    cout << "Ingrese la cantidad (1-5): ";
    int cantidad;
    cin >> cantidad;
    while (cantidad < 1 || cantidad > 5)
    {
        cout << "Cantidad inválida. Intente de nuevo (1-5): ";
        cin.clear();
        cin.ignore(10000, '\n');
        cin >> cantidad;
    }
    return cantidad;
}

string obtenerNombreJuego(int codigoJuego)
{
    switch (codigoJuego)
    {
    case 1: return "Doom Eternal";
    case 2: return "God of War";
    case 3: return "Halo Infinite";
    case 4: return "Zelda BOTW";
    case 5: return "Uncharted";
    case 6: return "Tomb Raider";
    case 7: return "FIFA 25";
    case 8: return "NBA 2K25";
    case 9: return "F1 25";
    case 10: return "Age of Empires IV";
    case 11: return "Civilization VI";
    case 12: return "Fire Emblem";
    default: return "Desconocido";
    }
}

int obtenerPrecioJuego(int codigoJuego)
{
    switch (codigoJuego)
    {
    case 1: return PRECIO_ACCION1;
    case 2: return PRECIO_ACCION2;
    case 3: return PRECIO_ACCION3;
    case 4: return PRECIO_AVENTURA1;
    case 5: return PRECIO_AVENTURA2;
    case 6: return PRECIO_AVENTURA3;
    case 7: return PRECIO_DEPORTE1;
    case 8: return PRECIO_DEPORTE2;
    case 9: return PRECIO_DEPORTE3;
    case 10: return PRECIO_ESTRATEGIA1;
    case 11: return PRECIO_ESTRATEGIA2;
    case 12: return PRECIO_ESTRATEGIA3;
    default: return 0;
    }
}

string obtenerPlataforma(int codigoJuego)
{
    switch (codigoJuego)
    {
    case 1: return "PC";
    case 2: return "PS5";
    case 3: return "Xbox";
    case 4: return "Switch";
    case 5: return "PS5";
    case 6: return "PC";
    case 7: return "PS5";
    case 8: return "Xbox";
    case 9: return "PC";
    case 10: return "PC";
    case 11: return "PC";
    case 12: return "Switch";
    default: return "Desconocida";
    }
}

string obtenerCategoria(int codigoJuego)
{
    if (codigoJuego >= 1 && codigoJuego <= 3) return "Accion";
    if (codigoJuego >= 4 && codigoJuego <= 6) return "Aventura";
    if (codigoJuego >= 7 && codigoJuego <= 9) return "Deportes";
    if (codigoJuego >= 10 && codigoJuego <= 12) return "Estrategia";
    return "Desconocida";
}

void agregarJuegoAlCarrito(int codigos[], int cantidades[], int& cantidadJuegosRegistrados)
{
    if (cantidadJuegosRegistrados >= MAX_JUEGOS)
    {
        cout << "No es posible agregar más juegos al carrito.\n";
        return;
    }

    mostrarCatalogoJuegos();
    int codigo = leerCodigoJuego();
    int cantidad = leerCantidadJuegos();

    for (int i = 0; i < cantidadJuegosRegistrados; i++)
    {
        if (codigos[i] == codigo)
        {
            cantidades[i] += cantidad;
            cout << "Juego actualizado: " << obtenerNombreJuego(codigo)
                 << " x" << cantidades[i] << " (cantidad acumulada)\n\n";
            return;
        }
    }

    codigos[cantidadJuegosRegistrados] = codigo;
    cantidades[cantidadJuegosRegistrados] = cantidad;
    cantidadJuegosRegistrados++;

    cout << "Juego agregado: " << obtenerNombreJuego(codigo)
         << " x" << cantidad << "\n\n";
}

double calcularSubtotalCarrito(const int codigos[], const int cantidades[], int cantidadJuegosRegistrados)
{
    double subtotal = 0.0;
    for (int i = 0; i < cantidadJuegosRegistrados; i++)
    {
        int precioUnitario = obtenerPrecioJuego(codigos[i]);
        subtotal += precioUnitario * cantidades[i];
    }
    return subtotal;
}

int leerTipoCliente()
{
    cout << "Tipo de cliente (1=Oro, 2=Plata, 3=Regular): ";
    int tipo;
    cin >> tipo;
    while (tipo < 1 || tipo > 3)
    {
        cout << "Opción inválida. Intente de nuevo (1-3): ";
        cin.clear();
        cin.ignore(10000, '\n');
        cin >> tipo;
    }
    return tipo;
}

double obtenerPorcentajeDescuento(int tipoCliente)
{
    if (tipoCliente == 1) return DESCUENTO_ORO;
    if (tipoCliente == 2) return DESCUENTO_PLATA;
    return DESCUENTO_REGULAR;
}

double calcularDescuentosAdicionales(const int codigos[], const int cantidades[], int cantidadJuegosRegistrados)
{
    double descuentoExtra = 0.0;
    for (int i = 0; i < cantidadJuegosRegistrados; i++)
    {
        string plataforma = obtenerPlataforma(codigos[i]);
        string categoria  = obtenerCategoria(codigos[i]);
        int precio = obtenerPrecioJuego(codigos[i]);

        // Ejemplo de reglas adicionales
        if (plataforma == "PC")
        {
            descuentoExtra += precio * cantidades[i] * 0.05; // 5% extra en juegos de PC
        }
        if (categoria == "Deportes")
        {
            descuentoExtra += precio * cantidades[i] * 0.03; // 3% extra en Deportes
        }
    }
    return descuentoExtra;
}

double calcularTotalFinal(double subtotal, double porcentajeDescuento, double descuentosAdicionales)
{
    return (subtotal * (1.0 - porcentajeDescuento)) - descuentosAdicionales;
}

void mostrarResumenCompra(const int codigos[], const int cantidades[], int cantidadJuegosRegistrados, double porcentajeDescuento)
{
    cout << "\n===== Resumen de la Compra =====\n";
    double subtotal = 0.0;
    for (int i = 0; i < cantidadJuegosRegistrados; i++)
    {
        string nombre = obtenerNombreJuego(codigos[i]);
        int precio = obtenerPrecioJuego(codigos[i]);
        double parcial = precio * cantidades[i];
        subtotal += parcial;
        cout << "- " << nombre << " (" << obtenerPlataforma(codigos[i]) << ") x"
             << cantidades[i] << " = $" << parcial << "\n";
    }
    cout << "Subtotal: $" << subtotal << "\n";
    cout << "Descuento aplicado: " << (porcentajeDescuento * 100) << "%\n";
}

void cargarCompraDemo(int codigos[], int cantidades[], int& cantidadJuegosRegistrados)
{
    cantidadJuegosRegistrados = 0;

    codigos[0] = 2; // God of War
    cantidades[0] = 1;

    codigos[1] = 4; // Zelda BOTW
    cantidades[1] = 2;

    codigos[2] = 9; // F1 25
    cantidades[2] = 1;

    cantidadJuegosRegistrados = 3;

    cout << "\nSe ha cargado una compra de demostración:\n";
    cout << "- 1 God of War (PS5)\n";
    cout << "- 2 Zelda BOTW (Switch)\n";
    cout << "- 1 F1 25 (PC)\n\n";
}
