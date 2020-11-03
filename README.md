# Informe: Trabajo Práctico N°2: Recolectores y Productores

Alumno: Federico Elías

Padrón: 96105

Fecha de entrega: 03/11/2020

# División de responsabilidades:

- CheckStore:
		Contiene los nombres de los archivos validados y el resultado de su
		respectiva validación. Recibe ambos por parámetro y los deposita en un
		vector de string. También es capaz de imprimir toda su lista de nombre
		de archivo más el resultado, por pantalla.

- FileStore:
		Contiene los nombres de los archivos a ser abiertos para validar,
		recibe el nombre del archivo, lo agrega a un vector de strings y luego
		ordena de forma descendente la lista de nombres totales; luego, cuando
		se le pide un archivo devuelve, si la lista no está vacía, el último
		miembro de la lista, que es el de menor orden alfabético.

- Parser:
		Es la clase que se encarga de parsear los archivos. Puede devolver
		una línea entera o, para cada línea de código, devolver la primera palabra,
		la instrucción, la cantidad de palabras totales, la cantidad de palabras
		sin contar la etiqueta, o reconocer si una línea de código es
		un salto condicional, incondicional o return.
		Esta clase no es instanciada porque no depende de un estado interno,
		todos sus métodos son estáticos y se los llama como métodos de clase	

- Node:
		Contiene el valor de una línea de código y apunta a sus dos nodos vecinos,
		que representan las líneas de códigos a la que el programa puede saltar según
		qué tipo de instrucción represente el nodo.

- DFSTree:
		Implementación del árbol DFS adaptada para el trabajo, establece las conexiones
		de los nodos de acuerdo al contenido de cada línea de código. También recorre
		el árbol hasta encontrar un bucle o bien hasta terminar de recorrer todos los
		nodos. También puede indicar si en el código hay un bucle o si hay instrucciones
		que no son usadas.

- Checker:
		Implementa la clase Thread, usando la API que fue presentada en clase,
		donde cada hilo toma un archivo de FileStore, lo evalúa con la clase DFSTree
		en base a si en el código hay un bucle o instrucciones sin usar,
		y luego deposita el resultado en CheckStore.

- Programa:
		Corre el flujo del programa tomando los argumentos de entrada, crea la cantidad
		de hilos indicada en el llamado del programa por consola, crea un FileStore
		y un CheckStore, luego hace correr los hilos y, cuando estos terminan,
		los joinea e imprime los resultados por pantalla.
		
# Diagrama de ejecución

![DiagramaTP2](https://github.com/nazar9318/taller1-2c2020-TP2/blob/master/assets/DiagramaTP2.png)
