/************************************************************************************************
Copyright (c) 2024 Felipe Saravia and others

Permission is hereby granted, free of charge, to any person obtaining
a copy of this software and associated documentation files (the
"Software"), to deal in the Software without restriction, including
without limitation the rights to use, copy, modify, merge, publish,
distribute, sublicense, and/or sell copies of the Software, and to
permit persons to whom the Software is furnished to do so, subject to
the following conditions:

The above copyright notice and this permission notice shall be
included in all copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,
EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF
MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND
NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE
LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION
OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION
WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.

SPDX-License-Identifier: MIT
*************************************************************************************************/

#ifndef GPIO_H
#define GPIO_H

/** @file
 ** @brief Capa de abstracción para gestion de puertos digitales
 **/

/* === Headers files inclusions ================================================================ */

#include <stdint.h>
#include <stdbool.h>

/* === Cabecera C++ ============================================================================ */

#ifdef __cplusplus
extern "C" {
#endif

/* === Public macros definitions =============================================================== */

/**
 * @brief Tipo de datos para manejar pines GPIO.
 *
 * `gpio_t` es un puntero a una estructura que representa un GPIO específico. 
 * Este tipo se utiliza para manipular y configurar pines GPIO a través de 
 * las funciones correspondientes.
 */
typedef struct gpio_h * gpio_t;

/* === Public data type declarations =========================================================== */

/* === Public variable declarations ============================================================ */

/* === Public function declarations ============================================================ */

/**
 * @brief Función para crear un puerto digital
 *
 * @param port Numero de puerto GPIO correspondiente
 * @param bit  Numero de bit asignado al puerto
 * @return gpio_t Puntero al objeto creado
 */
gpio_t GpioCreate(uint8_t port, uint8_t bit);

/**
 * @brief Configura la dirección de un pin GPIO.
 *
 * Esta función configura la dirección del pin GPIO especificado como entrada 
 * o salida.
 *
 * @param gpio   El pin GPIO a configurar.
 * @param output Establece en `true` para configurar como salida, `false` para entrada.
 */
void GpioSetDirection(gpio_t gpio, bool output);

/**
 * @brief Obtiene la dirección actual de un pin GPIO.
 *
 * Esta función devuelve la configuración de dirección del pin GPIO especificado, 
 * indicando si está configurado como entrada o salida.
 *
 * @param gpio El pin GPIO a verificar.
 * @return `true` si el pin está configurado como salida, `false` si está configurado como entrada.
 */
bool GpioGetDirection(gpio_t gpio);

/**
 * @brief Establece el estado de un pin GPIO.
 *
 * Esta función establece el nivel lógico del pin GPIO especificado. 
 * El pin debe estar configurado como salida antes de ajustar su estado.
 *
 * @param gpio  El pin GPIO a modificar.
 * @param state Establece en `true` para poner el pin en alto, `false` para ponerlo en bajo.
 */
void GpioSetState(gpio_t gpio, bool state);

/* === End of documentation ==================================================================== */

#ifdef __cplusplus
}
#endif

#endif /* GPIO_H */
