# Sistema de Gestión de Finanzas Personales

## Descripción del Problema

El manejo de finanzas personales presenta desafíos significativos en el procesamiento de grandes volúmenes de información provenientes de múltiples fuentes:

- **Estados de cuenta bancarios**
- **Facturas y comprobantes**
- **Registros de gastos e ingresos**
- **Transacciones de tarjetas de crédito**

### Problemática Principal

Se requiere un sistema capaz de:

1. **Acceder eficientemente** a grandes cantidades de transacciones históricas
2. **Permitir la inserción** de nuevas transacciones en tiempo real
3. **Mantener estructuras de datos escalables** a largo plazo
4. **Actualizar información dinámica** (como cambios en impuestos aplicables)

### Necesidades de Organización

El sistema debe organizar los datos mediante diversos criterios:

- **Ordenamiento por monto** para análisis de gastos significativos
- **Análisis temporal** del historial anual de transacciones
- **Búsqueda específica** de facturas y transacciones por ID
- **Categorización** de gastos e ingresos
- **Identificación de patrones** de gasto y comportamiento financiero

## Solución Implementada

### Arquitectura del Sistema

El proyecto implementa una solución modular utilizando conceptos fundamentales de algoritmos y estructuras de datos:

```
finanzas.h          - Definiciones globales y funciones principales
├── recursion.h     - Algoritmos recursivos para cálculos financieros
├── busquedas.h     - Algoritmos de búsqueda y localización
└── sorts.h         - Algoritmos de ordenamiento y organización
```

### Algoritmos Implementados

#### **Recursión (recursion.h)**
- `sumaGastosRecursiva()` - Cálculo recursivo de gastos totales **O(n)**
- `sumaIngresosRecursiva()` - Cálculo recursivo de ingresos totales **O(n)**
- `maxGastoRecursivo()` - Búsqueda del gasto máximo usando divide y vencerás **O(n)**
- `contarTransaccionesRec()` - Conteo recursivo de transacciones

#### **Búsquedas (busquedas.h)**
- `busquedaLineal()` - Búsqueda secuencial por ID **O(n)**
- `busquedaBinaria()` - Búsqueda binaria optimizada **O(log n)**
- `existeTransaccion()` - Verificación de existencia de transacciones
- `contarPorCategoria()` - Análisis por categorías de gasto **O(n)**

#### **Ordenamiento (sorts.h)**
- `ordenarPorMonto()` - Ordenamiento burbuja por monto **O(n²)**
- `ordenarPorFecha()` - Ordenamiento por selección temporal **O(n²)**
- `ordenarPorCategoria()` - Ordenamiento por inserción alfabético **O(n²)**
- `intercambiar()` - Función auxiliar para intercambio de datos

### Estructura de Datos

**Arreglos paralelos optimizados:**
```cpp
int ids[MAX_TRANSACCIONES];           // Identificadores únicos
string fechas[MAX_TRANSACCIONES];     // Timestamps temporales
float montos[MAX_TRANSACCIONES];      // Valores monetarios
string categorias[MAX_TRANSACCIONES]; // Clasificación de transacciones
bool esIngreso[MAX_TRANSACCIONES];    // Tipo de transacción
```

### Funcionalidades del Sistema

#### **Gestión de Transacciones**
1. **Agregar nuevas transacciones** con validación de límites
2. **Visualizar todas las transacciones** con formato estructurado
3. **Cargar datos de prueba** para testing del sistema

#### **Análisis Financiero**
1. **Resumen financiero automático** (ingresos, gastos, balance)
2. **Búsqueda por categorías** específicas
3. **Identificación de gastos máximos** usando algoritmos recursivos
4. **Análisis de patrones** de gasto por categoría

#### **Operaciones de Búsqueda y Ordenamiento**
1. **Búsqueda por ID** con algoritmos lineal y binario
2. **Ordenamiento multi-criterio** (monto, fecha, categoría)
3. **Verificación de existencia** de transacciones específicas

## Compilación y Ejecución

### Requisitos
- Compilador C++ (g++, clang++)
- Estándar C++11 o superior

### Instrucciones
```bash
# Compilar el proyecto
g++ main.cpp -o finanzas

# Ejecutar el sistema
./finanzas
```

### Menú de Opciones
```
1.  Ver todas las transacciones
2.  Agregar nueva transacción
3.  Buscar por ID (búsqueda lineal)
4.  Buscar por ID (búsqueda binaria)
5.  Ordenar por monto
6.  Ordenar por fecha
7.  Ordenar por categoría
8.  Ver resumen financiero
9.  Buscar por categoría
10. Ver gasto máximo
0.  Salir del sistema
```

## Escalabilidad y Limitaciones

### Ventajas del Diseño
- **Modularidad** permite extensiones futuras
- **Algoritmos eficientes** para operaciones frecuentes
- **Estructura simple** facilita mantenimiento
- **Separación de responsabilidades** entre módulos

### Limitaciones Actuales
- **Capacidad máxima** de 100 transacciones (configurable)
- **Almacenamiento en memoria** (no persistente)
- **Algoritmos básicos** con oportunidades de optimización

### Mejoras Futuras Sugeridas
1. **Implementación de estructuras de datos avanzadas** (árboles, hash tables)
2. **Persistencia en base de datos** para manejo de grandes volúmenes
3. **Algoritmos de ordenamiento más eficientes** (quicksort, mergesort)
4. **Análisis predictivo** de patrones de gasto
5. **Interfaz gráfica** para mejor experiencia de usuario

## Casos de Uso

### Análisis de Gastos Mensuales
```cpp
// Buscar todas las transacciones de una categoría específica
buscarPorCategoria("Supermercado");
int total = contarPorCategoria("Supermercado");
```

### Búsqueda de Transacciones Específicas
```cpp
// Búsqueda eficiente por ID
int posicion = busquedaBinaria(1025);
if (posicion != -1) {
    // Transacción encontrada
}
```

### Ordenamiento para Análisis
```cpp
// Ordenar por monto para identificar gastos significativos
ordenarPorMonto();
// Ordenar por fecha para análisis temporal
ordenarPorFecha();
```

Este sistema proporciona una base sólida para el manejo de finanzas personales, implementando algoritmos fundamentales de forma eficiente y escalable.