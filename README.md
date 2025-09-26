# Sistema de Finanzas Personales

## Descripción
El problema recae en manejar una gran cantidad de volumenes de información que pueden provenir de distintas fuentes, como estados de cuenta, facturas, registros de gastos e ingresos.

Se precisa de un sistema que debe acceder a muchas cantidades de transacciones históricas, mientras además permite agregar nuevas, lo que requiere una estructura de datos escalable al largo plazo, que sean actualizables (información sobre impuestos aplicables).

El sistema podría organizar los datos mediante diversos criterios según las necesidades, como organizar gastos por monto, análisis de historial anual de transacciones (gastos, ingresos). Búsquedas de facturas específicas, relaciones entre cuentas bancarias, tarjetas de crédito y categorías de gastos y un posible patrón para estos últimos.

## Lo que hace mi programa
Hice un sistema básico que puede:
- Guardar transacciones con fecha, monto y categoria
- Buscar transacciones por ID usando dos métodos diferentes
- Ordenar los datos por monto, fecha o categoria
- Calcular totales de gastos e ingresos automáticamente
- Encontrar el gasto mas alto

## Como funciona

### Archivos principales:
- `finanzas.h` - Archivo principal con variables globales
- `recursion.h` - Funciones recursivas para calcular sumas
- `busquedas.h` - Busqueda lineal y binaria
- `sorts.h` - Algoritmos de ordenamiento
- `main.cpp` - Menu principal

### Lo que incluí:
- Menú para agregar transacciones nuevas
- Busqueda por ID con algoritmo lineal y binario
- Ordenamiento por diferentes criterios
- Calculos automáticos de balance
- Búsqueda por categorias de gasto

## Como compilar y ejecutar:
```bash
g++ main.cpp -o finanzas
./finanzas
```

## Algoritmos que use:
- **Recursion**: para sumar gastos, ingresos y encontrar el maximo
- **Busquedas**: implementé busqueda lineal O(n) y binaria O(log n)
- **Ordenamiento**: bubble sort, selection sort e insertion sort

## Cosas que no pude hacer bien:
- Solo aguanta 100 transacciones porque use arreglos fijos
- No guarda los datos cuando cierras el programa
- Los algoritmos de ordenamiento son medio lentos para muchos datos
- Falta validación mejor de los datos que mete el usuario

## Reflexión:
Este proyecto me ayudó a entender mejor como funcionan los algoritmos básicos. Aunque mi implementación no es perfecta, logré aplicar los conceptos de recursión, búsqueda y ordenamiento que vimos en clase. Me di cuenta que para manejar realmente grandes volúmenes de datos necesitaría estructuras más avanzadas y algoritmos más eficientes.

Proyecto para TC1031 - Algoritmos Fundamentales.
