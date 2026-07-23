#include "replace.hpp"

// Este algoritmo es la alternativa limpia a std::string::replace. Lo que hace es 
// recorrer la cadena original de izquierda a derecha, cortando las partes que no 
// cambian e intercalando s2 cada vez que encuentra s1.

std::string replaceLine(std::string line, const std::string &s1, const std::string &s2){
	std::string newLine;
	size_t pos = 0;
	size_t found;

	while ((found = line.find(s1, pos)) != std::string::npos){
		newLine += line.substr(pos, found - pos);                  //Extrae un trozo de la línea original. Empieza en pos (donde nos habíamos quedado) y coge un número de caracteres igual a found - pos (es decir, la distancia que hay desde nuestro cursor hasta donde empieza s1).
		newLine += s2;
		pos = found + s1.length();
	}
	newLine += line.substr(pos);
	return newLine;
}





/*
EJEMPLO: 
Algoritmo de reemplazo de texto
Línea original (line): "Un perro y otro perro"

s1: "perro"

s2: "gato"

pos = 0. Busca "perro" a partir de 0 -> Encuentra en found = 3.

Corta desde 0 hasta 3 ("Un ") -> newLine pasa a ser "Un ".

Pega s2 ("gato") -> newLine pasa a ser "Un gato".

Avanza pos = 3 + 5 = 8 (justo después del primer "perro").

Vuelve a buscar a partir de 8 -> Encuentra el segundo "perro" en found = 16.

Corta desde 8 hasta 16 (" y otro ") -> newLine pasa a ser "Un gato y otro ".

Pega s2 ("gato") -> newLine pasa a ser "Un gato y otro gato".

Avanza pos = 16 + 5 = 21.

Busca a partir de 21 -> Ya no hay más "perro", devuelve npos. Sale del bucle.

newLine += line.substr(21) -> Como ya no queda texto después del 21, no añade nada más.

Imprime en el archivo: "Un gato y otro gato".


Sí. En replace.cpp lo importante es la función replaceLine, que reemplaza todas las apariciones de s1 por s2 dentro de una línea.

1. std::string replaceLine(std::string line, const std::string &s1, const std::string &s2)
Declara una función que recibe:

line: la línea original
s1: el texto que se quiere buscar
s2: el texto que se quiere poner en su lugar
2. std::string newLine;
Crea una cadena vacía donde se irá construyendo la línea nueva.

3. size_t pos = 0;
Marca desde qué posición empezar a buscar dentro de line.

4. size_t found;
Variable donde se guardará la posición donde se encuentre s1.

5. while ((found = line.find(s1, pos)) != std::string::npos)
Busca s1 dentro de line empezando desde pos.
Si lo encuentra, entra al bucle.
Si no lo encuentra, sale.

6. newLine += line.substr(pos, found - pos);
Añade a newLine todo lo que hay desde pos hasta justo antes de la coincidencia.
O sea, copia la parte de la línea que no cambia.

7. newLine += s2;
En vez de s1, mete s2.

8. pos = found + s1.length();
Avanza la posición de búsqueda hasta después del texto que acabas de reemplazar.

9. newLine += line.substr(pos);
Cuando ya no quedan más coincidencias, añade el resto de la línea original que falta por copiar.

10. return newLine;
Devuelve la línea ya modificada.

*/

