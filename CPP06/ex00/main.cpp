#include "ScalarConverter.hpp"

int main(int ac, char* av[]) {
	if (ac != 2) {
		std::cout << "Uso: ./convert <literal>" << std::endl;
		return 1;
	}

	ScalarConverter::convert(av[1]);
	return 0;
}

/*
 * CASOS DE PRUEBA RECOMENDADOS:
 * 
 * 1. CHAR:
 *    ./convert 'c'        -> Letra imprimible normal
 *    ./convert 'a'        -> char: 'a', int: 97, float: 97.0f, double: 97.0
 *    ./convert '*'        -> Símbolo imprimible
 * 
 * 2. INT:
 *    ./convert 0          -> Cero
 *    ./convert 42         -> Positivo estándar (char: '*')
 *    ./convert -42        -> Negativo
 *    ./convert 2147483647 -> INT_MAX
 *    ./convert -2147483648-> INT_MIN
 * 
 * 3. FLOAT:
 *    ./convert 0.0f       -> Cero con sufijo
 *    ./convert 4.2f       -> Decimal positivo
 *    ./convert -4.2f      -> Decimal negativo
 * 
 * 4. DOUBLE:
 *    ./convert 0.0        -> Cero sin sufijo
 *    ./convert 42.0       -> Decimal entero
 *    ./convert 42.42      -> Decimal estándar
 * 
 * 5. PSEUDOLITERALES:
 *    ./convert nan
 *    ./convert nanf
 *    ./convert +inf
 *    ./convert -inf
 *    ./convert +inff
 *    ./convert -inff
 * 
 * 6. CASOS LÍMITE / ERRORES:
 *    ./convert 2147483648 -> Overflow de int (debe dar int impossible)
 *    ./convert hello      -> Entrada no válida (todo impossible)
 *    ./convert 128        -> Char fuera de rango ASCII (char: impossible)
 *    ./convert 0          -> ASCII no imprimible (char: Non displayable)
 */