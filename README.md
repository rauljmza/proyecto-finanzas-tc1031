# Proyecto: Nombre de tu proyecto
Escribe aquí un overview general de tu proyecto

## Descripción del avance 1
Un proyecto básico de gestión de gastos e ingresos en el que unicamnete se pueden registrar hasta 100 transacciones con informacion como fecha, monto, categoria y una descripcion. Se hizo uso de algotimtos de busqeuda lineal y bunaria, y ordenarlos mediante 3 algoritmos diferentes: Bubble Sort para el ordenamiento pot monto, Selection Sort para fechas e Insertion Sorto para las categorias, todos con una complejidad O(n^2). La limitacion principal es que se ocupa la misma memoria sin importar si se guardan 10 o 100 transacciones.

## Descripción del avance 2
El nuevo proyecto de gestión de gastos e ingresos permite tener un mejor control de las transacciones mediante las nuevas categorias añadidas, y la posibilidad de determinar un metodo de pago entre distintas cuentas de banco. Esto a su vez permitiría conocer cuales gastos son innecesarios, ordenarlos por monto, fecha, categoria, por tipo, por metodo de pago y por ID; teniendo como "dashboard" de dichos datos el resumen para saber cómo vamos en nuestras finanzas.

El avance 2 representa un "renacimiento" con respecto al avance 1. Se elimna el limite de 100 transacciones debido a que se implementa una estructura de datos dinámica la cual es la lista doblemente ligada. Es decir, que en lugar de mantener conjuntos de datos separados, cada transacciones ahora es un objeto con información encapsulada. 

### Cambios sobre el primer avance
1. Se hizo la sutitución de los 6 arreglos paralelos estáticos por una única estructura DList:
El hecho de tener limites para añadir gastos resulta insostenible incluso al corto plazo, ademas, el hecho de mantener los 6 arreglos sincronizados manualmente era propenso a errores. La lista doblemente ligada permite el crecimiento dinamico segun la necesidad y encapusla la inforamcion de una transaccion en un objeto, sin embargo, esto represetó que pasó de O(1) a O(n).

2. Se hizo la eliminación de la busqueda binaria, reemplazandola por la busqueda lineal:
Originalmente, se ordenaba todo usando bubble sort O(n^2) en cada llamada, lo que resultaba en una complejidad mayor comparada a la actual de O(n) de la busqueda lineal. Esto ademas limitaba la busqeuda por otras variables, obligando al usuario final a buscar unicamente por el ID.

3. Se añadió la estructura stack para deshacer:
Si añadiera una transacción y después la ordenara por una categoría, y quisiera eliminar la última transaccion sin el stack se eliminaria el ultimo en la lista en lugar del ultimo agregada. El stack mantiene un orden cronológico de inserción, importante para tener un historial inmutable en mis finanzas, que es independiente a cualquier ordenamiento, lo que garantiza por ejemplo que top() siempre me devolverá la última tranascción, esto unicamente representa una complejidad O(1).

4. Implementacion de Gestión de bancos y tarjetas:
En mis gastos personales, elegir con que metodo de pago realice un gasto es importante, registrar solo "BBVA" como texto libre no me permitiría rastrear si la tarjeta usada fue la de credito o debito, ni tener nocion de mis limites de credito. La funcion seleccionarMetodoPago() muestra las tarjetas numeradas.

## Descripción del avance 3
El avance 3 completa el sistema de finanzas personales agregando las funcionalidades que faltaban para tener un control total sobre las tarjetas de credito y la persistencia de datos. Ahora el proyecto permite guardar todas las transacciones en un archivo CSV, consultar los saldos utilizados de las tarjetas de credito con su porcentaje de uso, y realizar pagos de tarjetas de credito desde tarjetas de debito, todo esto registrando automaticamente las transacciones tipo 4.

Este avance represeta la culminacion del sistema, debido a que ahora se tiene un ciclo completo de gestion financiera: se pueden registrar gastos con tarjetas de credito, monitorear cuanto se debe, pagar esas deudas y exportar toda la inforamcion para respaldo o analisis externo. La implementacion de guardarEnCSV permtie al usuario no perder sus datos al cerrar el programa, esto pues siendo fundamental para un sistema de finanzas real.

### Cambios sobre el segundo avance
1. Se implementó la funcionalidad de guardar en CSV (guardarEnCSV):
El avance 2 unicamnete permitia cargar datos desde CSV pero no guardarlos, lo que significaba que toda la informacion se perdía al cerrar el programa. Ahora con la opción 10 del menu, el usuario puede exportar todas sus transacciones a un archivo CSV con el nombre que desee, manteniendo el mismo formato que se usa para cargar, esto permite un flujo bidireccional de datos.

2. Se completó la consulta de saldo de tarjetas de credito:
Anteriormente la funcion consultarSaldoTarjetaCredito() solo mostraba un mensaje de "en desarrollo", ahora realiza el calculo completo del saldo utilizado restando los pagos realizados a los gastos hechos con cada tarjeta, mostrando el porcentaje de uso del limite de credito. Esto es critico para evitar sobregiros y mantener un buen historial crediticio.

3. Se agregó el sistema completo de pago de tarjetas:
La funcion pagarTarjetaCredito() que estaba pendiente ahora permite seleccionar la tarjeta a pagar, verificar el saldo adeudado, elegir desde que tarjeta de debito se realizará el pago, y crear automaticamente la transaccion tipo 4. El sistema valida que no se pague mas del saldo utilizado y que no se intente pagar cuando no hay deuda, esto pues evitando errores del usuario.

## Instrucciones para compilar el avance de proyecto
Ejecuta el siguiente comando en la terminal:

`g++ main.cpp -o finanzas.exe` 

## Instrucciones para ejecutar el avance de proyecto
Ejecuta el siguiente comando en la terminal:

`./finanzas` 

## Descripción de las entradas del avance de proyecto
El proyecto acepta dos tipos de entradas:

1. El usuario ingresa información a través del menú de opciones, para agregar una transaccion debe de ingresar el tipo de transaccion, la fecha, el monto, la categoria, metodo de pago y si el gasto fue necesario o no.

2. El proyecto ahora puede cargar transacciones desde un csv, siempre y cuando se encuentre en la misma carpeta. Esto a traves del menu en la opción 9. A continuación el formato en el que se debe ingresar la informacion correctamente:

Fecha,Monto,Categoria(1=Comida 2=Transporte 3=Servicios 4=Antojos 5=Compras),Tipo,MetodoPago,EsNecesario

El archivo transacciones.csv incluido contiene 87 transacciones representativas de 2 meses (septiembre y octubre 2024) que muestran todo el potencial del sistema:
  - 66 gastos diversos (necesarios y no necesarios)
  - 15 ingresos (nominas quincenales y bonos)
  - 5 pagos de tarjetas de credito
  - 4 transferencias entre cuentas
  - Todas las categorias de gastos representadas
  - Todos los 5 metodos de pago utilizados
  - Montos desde $45 hasta $118,607

Extracto del archivo CSV incluido:

  Fecha,Monto,Categoria,Tipo,MetodoPago,EsNecesario
  2024-09-01,55000.00,0,2,1,0
  2024-09-03,1200.00,1,1,3,1
  2024-09-05,2800.00,3,1,4,1
  2024-09-15,3500.00,0,4,3,0
  2024-10-10,5000.00,0,3,1,0

  Correspondencia de métodos de pago por defecto:
  1. Didi
  2. Mercado Pago Debito
  3. Mercado Pago Credito
  4. Nu Debito
  5. Nu Credito

## Descripción de las salidas del avance de proyecto

1. Al ejecutar el registro de una transaccion desde el menu se muestra la transaccion realizada de la siguiente manera:

ID: 1 - Fecha: 2025-10-01 - Tipo: Ingreso - Monto: $111479.09 - Categoria: Sin categoria - Metodo: Didi

2. Al cargar la informacion mediante un csv deberia imprimir lo siguiente:

Se cargaron 87 transacciones desde transacciones.csv

En caso de haber algun error:

Error: No se pudo abrir el archivo transacciones.csv

3. Al guardar las transacciones en CSV (opción 10) se muestra:

Transacciones guardadas en archivo_salida.csv

4. Al consultar el saldo de una tarjeta de credito se muestra:

=== RESUMEN DE TARJETA ===
Tarjeta: Mercado Pago Credito
Limite de credito: $4030
Total de gastos: $2350.50
Total de pagos: $800
Saldo utilizado: $1550.50
Saldo disponible: $2479.50
Porcentaje de uso: 38.47%

5. Al pagar una tarjeta de credito exitosamente:

=== PAGO EXITOSO ===
Se pago: $500
Desde: Didi
A: Mercado Pago Credito
Nuevo saldo utilizado: $1050.50
Saldo disponible: $2979.50

## Desarrollo de competencias

### SICT0301: Evalúa los componentes
#### Hace un análisis de complejidad correcto y completo para los algoritmos de ordenamiento usados en el programa.
Con respecto al avance anterior, en este avacne se implementan tres algotimtos de ordenamiento en sorts.h analizando sus tres casos de complejidad:

Bubble sorto (ordenarPorMonto y ordenarPorTipo): En el mejor caso cuando los datos ya estan ordenados sigue siendo O(n^2) porque no tiene optimizacion de bandera para detectar si ya esta ordenado, debe hacer todas las comparaciones. En el caso promedio tambien es O(n^2) porque estadisticamente hara la mitad de los intercambios posibles. En el peor caso cuando esta ordenado inversamente es O(n^2) haciendo el maximo de intercambios posibles, esto pues siendo el mas ineficiente.

Selection srot (ordenarPorFecha y ordenarPorMetodoPago): Para los tres casos siempre es O(n^2) debido a que siempre busca el minimo elemento en cada iteracion sin importar si los datos ya estan ordenados o no, esto pues siendo el mas consistente pero nunca mejora su desempeño.

Insertion sort (ordenarPorCategoria y ordenarPorId): En el mejor caso cuando ya esta ordenado es O(n) porque unicamnete hace una comparacion por elemento sin intercambios. En el caso promedio es O(n^2) cuando los elementos estan parcialmente desordenados. En el peor caso con datos inversamente ordenados es O(n^2) porque cada elemento debe moverse hasta el inicio.

Para mi el aprendizaje es que insertion sort es el unico que se beneficia cuando los datos tienen cierto orden previo, lo cual es comun en transacciones que se agregan cronologicamente y luego se reordenan ligeramente 

#### Hace un análisis de complejidad correcto y completo de todas las estructuras de datos y cada uno de sus usos en el programa.
El proyecto utiliza dos estructuras de datos analizadas con sus tres casos:

Lista doblemente ligada (DList): Para add() los tres casos son O(1) porque siempre agrega al final actualizando solo el puntero tail. Para get(index) el mejor caso es O(1) cuando se accede al primer elemento, el caso promedio es O(n/2) cuando se busca en la mitad de la lista, y el peor caso es O(n) cuando se busca el ultimo elemento. Para remove(index) el mejor caso es O(1) si se elimina el primer elemento, caso promedio O(n/2) para elementos en medio, y peor caso O(n) para eliminar el ultimo despues de recorrer toda la lista, esto pues recorriendo nodo por nodo. Length() siempre es O(1) en los tres casos porque unicamnete reotrna el contador size.

Stack (StackList): Para todas sus operaciones push(), pop() y top() la complejidad es O(1) en mejor caso, caso promedio y peor caso, debido a que std::list permite insercion y eliminacion eficiente al frente. Empty() tambien es O(1) en los tres casos. Esto es critico para la funcionalidad de deshacer que debe ser rapida sin importar cuantas transacciones existan 

Con respecto al avance 1, los arreglos estaticos ofrecian el acceso unicamnete con O(1), pero el limite siempre era fijo y se desperdiciaba sino se utilizaba completamente, por otro lado DList pues ahora tiene una complejidad de O(n), pero a cambio tenemos una estructura dinamica con capcaidad ilimitada (limite fisico de la memoria).

### SICT0302: Toma decisiones
#### Selecciona un algoritmo de ordenamiento adecuado al problema y lo usa correctamente.
En el archivo sorts.h es posible ver que bubble sort es utilizado para ordenar por monto y por tipo de transaccion, debido a que se requieren comparaciones numericas simples, este algoritmo mantiene el orden relativo de elementos iguales, lo que es importantes cuando dos transacciones tienen el mismo monto.

Selection sort es aplicado para ordenar por fecha y por metodo de pago, esto aprovechando que se minimiza el numero de intercambios, importante en este caso porque se hace con strings que tiene un mayor coste que los numeros.

Insertion sort se utiliza para ordenar por categoria y por ID, siendo este eficiente cuando ya hay un cierto orden o cuando se agregan nuevos elementos a listas que ya estaban ordenadas, esto siendo especialmente necesario porque se agregan transacciones secuencialmente.

Para mí el utilizar varios algoritmos de ordenamiento en lugar de uno universal representa un aprendizaje, debido a que ahora en este avance cada uno tiene un propósito específico basado en las características de los datos con los que se hará la discriminación.

#### Selecciona una estructura de datos adecuada al problema y la usa correctamente.
El proyecto utiliza la lista doblemente ligada como estructura principa y stack como estructura auxiliar. La DList la seleccioné porque permite un crecimiento dinamico entre inserción al final, la cual es la operacion mas frecuente debido a que se registran transacciones, esto está reflejado en finanzas.h se declara DList<Transacciones> como el almacenamiento principal, lo que representa un avance con respecto a los sesis arreglos anteriores que estaban propensos a la desincronización.

El stack, también en finanzas.h, se tiene un orden cronologico lo que resuelve que se puedan deshacer registros de transacciones (ultima transaccion agregada) despues de haber ordenado por monto o por algun otro orden.

Para mi el aprendizaje es que las estructuras no son intercambiables sino que cada una tiene propiedades que hacen adecuadas para cosas en especifico. Los arreglos anteriores ofrecian el acceso con O(1), sin embargo con un limite fijo, por otro lado DList no tiene acceso directo, pero las operaciones como agregar, recorrer y ordenar no requieren el acceso aleatorio frecuente. El hecho de contar con una sola estructura podría ser insuficiente para acciones como deshacer, ya que hacerlo solo con la DList, esta tendría una dificultad de O(n), mientras que Stack como estructura auxiliar lo hace con O(1).

### SICT0303: Implementa acciones científicas
#### Implementa mecanismos para consultar información de las estructras correctos.
El proyecto utiliza algunos metodos para consultar informacion de las estructuras de datos de acuerdo a los diferentes criterios de busqueda. La busqueda por ID, implementada en busquedas.h, recorrde la DList comparando cada ID hasta encontrarlo, retornando el indice, y este imprime toda la transaccion. La consulta por categoria (buscarPorCategoria()) filtra y muestra todas las transacciones de una categoria, estas siendo tambien siendo contadas (contarPorCategoria()), entre otras busquedas.

En el resumen, implementado en finanzas.h, se realiza una consulta que recorre toda la estructura, sumando totales de ingresos, gastos, necesarios y no necesarios en un solo recorrido O(n). Y finalmente otro a destacar es la consulta del stack, en la que top accede al elemento superior sin relaizar modificaciones a la estructura y pop lo elimina.

Para mi el aprendizaje es que las estructuras requieren mecanismos de consulta propios, por ejemplo DList realiza las consultas mediante un recorrido secuencial con get, stack mediante top el cual solo accede al tope.

#### Implementa mecanismos de lectura de archivos para cargar datos a las estructuras de manera correcta.
La carga de datos en le proyecto se hizo mediante dos formas. Al ejecutar el programa ejecuta la función cargarDatosPrueba, en la que puse por default algunos bancos, y cinco tarjetas asociadas, así como tres transacciones iniciales, esto como modo de prueba del funcionamiento/consulta.

Ahora, en el menu el usuario puede cargar transacciones de forma masiva, desde un archivo csv, donde el programa solicita el nombre del archivo (incluyendo la extension), este se abre mediante la clase ifstream de C++. La funcion cargarDesdeCSV primero revisa que el archivo exista y que este pueda abrirse, despues inmediatamente descarta la primera linea ya que esta contiene los encabezados para que el usuario pueda identificar cual "columna" corresponde a que informacion, y después procesa cada linea, creadno un stringsream que permite la extracción de los campos separados por comas en un orden especifico por su tipo de dato. Una vez procesada se usa la funcion "agregarTransaccion" que crea el objeto transacciones asignando un ID y toda la informacion anterior, agregada tanto a la lista doblemente ligada como al stack de historial.

#### Implementa mecanismos de escritura de archivos para guardar los datos de las estructuras de manera correcta.
En este avance 3 se completo la funcionalidad de guardarEnCSV que permite exportar todas las transacciones almacenadas en la estructura DList a un archivo CSV. La implementacion recorre toda la lista doblemente ligada con complejidad O(n), extrayendo cada campo del objeto Transaccion mediante los getters correspondientes. El formato de salida mantiene compatibilidad total con el formato de entrada, lo que signifca que un archivo guardado puede ser cargado nuevamente sin modificaciones.

La funcion utiliza ofstream de C++ para crear o sobreescribir el archivo especificado por el usuario, primero escribe la linea de encabezados "Fecha,Monto,Categoria,Tipo,MetodoPago,EsNecesario" y despues itera por todas las transacciones escribiendo cada una en una linea separada. Para mi el aprendizaje aqui es que la escritura de archivos requiere considerar el formato de datos, la compatibilidad con otros sistemas y la preservacion de la informacion, esto pues siendo critico cuando se trata de datos financieros donde la perdida de informacion podría tener consecuencias graves.

### SICT0301: Evalúa los componentes
#### Hace un análisis de complejidad correcto y completo para todos los demás componentes del programa y determina la complejidad final del programa.
Analizando el programa completo con sus tres casos de complejidad:

**Mejor caso del sistema - O(1):** Cuando el usuario solo agrega transacciones sin consultar ni ordenar nada. Las operaciones agregarTransaccion() ejecutan DList::add y Stack::push ambas en O(1), deshacerUltimaTransaccion() usa Stack::pop en O(1) y luego busca en DList pero con pocas transacciones sigue siendo rapido. Este es el caso cuando se usa el sistema unicamnete para registro rapido de gastos.

**Caso promedio del sistema - O(n):** El uso tipico involucra agregar transacciones O(1), consultar resumen financiero O(n), buscar por categoria O(n), mostrar todas las transacciones O(n), cargar o guardar CSV O(n). La mayoria de operaciones requieren recorrer la lista una vez. Los ordenamientos O(n^2) son ocasionales, tal vez una vez por sesion. Las busqeudas lineales O(n) son frecuentes pero aceptables porque no requieren mantener orden previo, esto pues siendo practico.

**Peor caso del sistema - O(n^2):** Ocurre cuando el usuario ordena frecuentemente las transacciones. Bubble sorto siempre es O(n^2), selection srot siempre es O(n^2), insertion sort es O(n^2) con datos desordenados. Si el usuario ordena por monto, luego por fecha, luego por categoria en una sesion, cada operacion es O(n^2). Con 87 transacciones como en el CSV incluido esto significa 7569 comparaciones por cada ordenamiento.

Analizando operaciones individuales en detalle:
- agregarTransaccion: O(1) en los tres casos
- mostrarTransacciones: O(n) en los tres casos
- buscarPorId: mejor O(1), promedio O(n/2), peor O(n)
- ordenar (cualquiera): mejor O(n) unicamnete insertion con datos ordenados, promedio y peor O(n^2)
- consultarSaldoTarjetaCredito: O(n) en los tres casos debe recorrer todas las transacciones
- cargarDesdeCSV: O(n) en los tres casos
- guardarEnCSV: O(n) en los tres casos

La complejidad final del programa es: mejor caso O(1) para operaciones simples, caso promedio O(n) para uso normal, peor caso O(n^2) cuando se ordena frecuentemente. Esto pues es aceptable para finanzas personales donde n < 1000 transacciones tipicamente.

Para mi el aprendizaje es que un sistema puede tener multiples complejidades dependiendo del patron de uso, y que el analisis debe considerar no solo las operaciones individuales sino tambien la frecuencia con que el usuario las ejecuta en la practica

## Proximos pasos

Con este avance 3 se completaron todas las funcionalidades basicas del sistema de finanzas personales. Los proximos pasos podrían incluir la implementacion de graficas para visualizar tendencias de gastos, alertas cuando se acerque al limite de credito, presupuestos mensuales con seguimiento automatico, y tal vez una interfaz grafica para hacer el sistema mas accesible. Tambien seria interesante agregar soporte para multiples usuarios y encriptacion de datos para mayor seguridad.