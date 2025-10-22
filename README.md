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

Ejemplo de archivo CSV que el proyecto sí puede cargar (transacciones.csv):

  Fecha,Monto,Categoria,Tipo,MetodoPago,EsNecesario
  2025-10-01,111479.09,0,2,1,0
  2025-10-03,850.50,1,1,2,1
  2025-10-05,120.00,2,1,1,1
  2025-10-10,5000.00,0,3,1,0
  2025-10-15,2000.00,0,4,3,0

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

Se cargaron 21 transacciones desde transacciones.csv

En caso de haber algun error:

Error: No se pudo abrir el archivo transacciones.csv

## Desarrollo de competencias

### SICT0301: Evalúa los componentes
#### Hace un análisis de complejidad correcto y completo para los algoritmos de ordenamiento usados en el programa.
Con respecto al avance anterior, en este avacne se implementan tres algoritmos de ordenamiento en sorts.h. La complejidad O(n^2) se determinó viendo la estructura de ciclos anidados en cada funcion: ordenarPorMonto donde utiliza bubble sorto con un ciclo externo que recorre n-1 elementos, y el interno que recorre n-1-i elementos; ordenarPorFecha usa selection sort, donde se realiza la busqueda del elemento mas pequeño en cada iteracion, esto pues recorriendo los elementos restantes; y ordenarPorCategoria utiliza insertion srot que compara cada nuevo elemento con todos los anteriores hasta determinar us posicion. 

En estos tres casos, el numero total de las comparaciones se cuadriplica con el tamaño de la entrada, o O(n^2). El aprendizaje con respecto al avance 1, es que no necesariamente se afecta la complejidad cambiando la estructura de datos, porque este sigue siendo determinado por cuantas veces se compara e intercambian elementos, no por como se acceden. 

#### Hace un análisis de complejidad correcto y completo de todas las estructuras de datos y cada uno de sus usos en el programa.
El proyecto utiliza dos estructuras de datos. La lista doblemente ligada (en dlist.h), es la principal que almacena las transacciones, donde lo que se realiza con mas frecuencia es agregar elementos al final mediante add, este tiene complejidad de O(1), porque solo actualiza el puntero sin recorrer la lista. Get accede a elementos por indice, tiene complejidad O(n), porque recorre secuencialmente desde head hasta la posicion desdeada, contanto uno por uno los nodos, es necesario porque necesitamos acceder a posiciones específicas. Remove tambien es O(n) porque es preciso localizar el elemento en la posicion indicada con un recorrido secuencial, y despues reajustar los punteros "previous" y "next" de los nodos que se encuentran adyacentes. Lenght unicamente reotrna el contador size por lo que es O(1).

El stack implementado en stack.h, al utilizar std::list nos permite tener una complejidad de O(1) en operacioens como push, que agrega elementos al frente, top para acceder al primer elemento y pop que elimina el primer elemento. Es decir, se mantiene la complejidad porque unicamnete se hace uso del inicio de la lista, sin recorrerla. 

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

## Proximos pasos

Me gustaria terminar de implementar bien el pago a tarjetas de credito, como consultar el saldo disponible en la tarjeta de credito en caso de haberse usado, el pagar la tarjeta de credito con salo de tarjetas de debito, esto requiere el rastreo de salddo utilizado, rastrear pagos y calcular el saldo disponible.

También por lo que veo en una siguiente entrega se tendrá que guardar la inofmraicón en un csv, por lo que implementarla será el siguiente paso también.