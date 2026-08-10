#include "Point.hpp"


// Función auxiliar para calcular el producto cruzado 2D
static Fixed area(Point const p1, Point const p2, Point const p) {
	return (p1.getX() - p.getX()) * (p2.getY() - p.getY()) - (p2.getX() - p.getX()) * (p1.getY() - p.getY());
}

bool bsp(Point const a, Point const b, Point const c, Point const point) {
	Fixed d1 = area(a, b, point);
	Fixed d2 = area(b, c, point);
	Fixed d3 = area(c, a, point);

	// Si algún resultado es 0, el punto está en un borde o vértice -> false
	if (d1 == 0 || d2 == 0 || d3 == 0)
		return false;

	// Comprobamos si las 3 orientaciones tienen el mismo signo
	bool has_neg = (d1 < 0) || (d2 < 0) || (d3 < 0);
	bool has_pos = (d1 > 0) || (d2 > 0) || (d3 > 0);

	// Si no tiene mezcla de positivos y negativos, está estrictamente dentro
	return !(has_neg && has_pos);
}

