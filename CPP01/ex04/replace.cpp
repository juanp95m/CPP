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


*/

