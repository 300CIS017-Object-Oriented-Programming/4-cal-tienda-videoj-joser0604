//
// Created by Joser on 8/29/2025.
//

#ifndef TIENDA_H
#define TIENDA_H
#include <string>
using namespace std;

// ========================
// Constantes de descuentos
// ========================
const double DESCUENTO_ORO     = 0.15;
const double DESCUENTO_PLATA   = 0.08;
const double DESCUENTO_REGULAR = 0.0;

// ========================
// Límite de juegos
// ========================
const int MAX_JUEGOS = 20;

// ========================
// Prototipos de funciones
// ========================

/**
 * Muestra en consola el catálogo de videojuegos
 */
void mostrarCatalogoJuegos();

/**
 * Solicita y valida el código de un juego (1-12)
 * @return código del juego
 */
int leerCodigoJuego();

/**
 * Solicita y valida la cantidad de juegos (1-5)
 * @return cantidad ingresada
 */
int leerCantidadJuegos();

/**
 * Obtiene el nombre del juego dado su código
 * @param codigoJuego código del juego
 * @return nombre del juego
 */
string obtenerNombreJuego(int codigoJuego);

/**
 * Obtiene el precio del juego dado su código
 * @param codigoJuego código del juego
 * @return precio del juego
 */
int obtenerPrecioJuego(int codigoJuego);

/**
 * Obtiene la plataforma del juego (PS5, Xbox, PC, Switch)
 * @param codigoJuego código del juego
 * @return plataforma
 */
string obtenerPlataforma(int codigoJuego);

/**
 * Obtiene la categoría del juego (Acción, Aventura, Deportes, Estrategia)
 * @param codigoJuego código del juego
 * @return categoría
 */
string obtenerCategoria(int codigoJuego);

/**
 * Registra un juego en el carrito de compras
 * @param codigos arreglo con los códigos de juegos
 * @param cantidades arreglo con las cantidades de cada juego
 * @param cantidadJuegosRegistrados número de juegos ya registrados en el carrito
 */
void agregarJuegoAlCarrito(int codigos[], int cantidades[], int& cantidadJuegosRegistrados);

/**
 * Calcula el subtotal del carrito sin aplicar descuentos
 * @param codigos arreglo con los códigos de juegos
 * @param cantidades arreglo con las cantidades
 * @param cantidadJuegosRegistrados cantidad de juegos en el carrito
 * @return subtotal de la compra
 */
double calcularSubtotalCarrito(const int codigos[], const int cantidades[], int cantidadJuegosRegistrados);

/**
 * Solicita y valida el tipo de cliente (1=Oro, 2=Plata, 3=Regular)
 * @return tipo de cliente
 */
int leerTipoCliente();

/**
 * Retorna el porcentaje de descuento según el tipo de cliente
 * @param tipoCliente tipo de cliente
 * @return porcentaje de descuento
 */
double obtenerPorcentajeDescuento(int tipoCliente);

/**
 * Calcula descuentos adicionales por plataforma o categoría
 * (ejemplo: 5% extra en juegos de PC, 3% en Deportes)
 * @param codigos arreglo de códigos
 * @param cantidades arreglo de cantidades
 * @param cantidadJuegosRegistrados cantidad de juegos en el carrito
 * @return total de descuentos adicionales
 */
double calcularDescuentosAdicionales(const int codigos[], const int cantidades[], int cantidadJuegosRegistrados);

/**
 * Calcula el total final con los descuentos aplicados
 * @param subtotal subtotal de la compra
 * @param porcentajeDescuento descuento por tipo de cliente
 * @param descuentosAdicionales descuentos adicionales
 * @return total final de la compra
 */
double calcularTotalFinal(double subtotal, double porcentajeDescuento, double descuentosAdicionales);

/**
 * Muestra en consola el resumen de la compra
 * @param codigos arreglo con los códigos de juegos
 * @param cantidades arreglo con las cantidades
 * @param cantidadJuegosRegistrados cantidad de juegos
 * @param porcentajeDescuento descuento por tipo de cliente
 */
void mostrarResumenCompra(const int codigos[], const int cantidades[], int cantidadJuegosRegistrados, double porcentajeDescuento);

/**
 * Precarga una compra de demostración en el carrito
 * @param codigos arreglo de códigos
 * @param cantidades arreglo de cantidades
 * @param cantidadJuegosRegistrados referencia al contador de juegos
 */
void cargarCompraDemo(int codigos[], int cantidades[], int& cantidadJuegosRegistrados);

#endif // TIENDA_H