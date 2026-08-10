#include "Point.hpp"

int main(void) {
    // Definimos los 3 vértices del triángulo ABC
    Point const a(0.0f, 0.0f);
    Point const b(10.0f, 0.0f);
    Point const c(0.0f, 10.0f);

    // 1. Punto DENTRO del triángulo
    Point const inside(2.0f, 2.0f);
    
    // 2. Punto FUERA del triángulo
    Point const outside(12.0f, 5.0f);
    
    // 3. Punto en un VÉRTICE (ej. exactamente en el vértice A)
    Point const vertex(0.0f, 0.0f);
    
    // 4. Punto en un EDGE / BORDE (ej. en medio del segmento A-B)
    Point const edge(5.0f, 0.0f);

    std::cout << "--- TEST BSP ---" << std::endl;
    std::cout << "Inside  (2, 2):   " << (bsp(a, b, c, inside)  ? "IN" : "OUT") << std::endl;
    std::cout << "Outside (12, 5):  " << (bsp(a, b, c, outside) ? "IN" : "OUT") << std::endl;
    std::cout << "Vertex  (0, 0):   " << (bsp(a, b, c, vertex)  ? "IN" : "OUT") << std::endl;
    std::cout << "Edge    (5, 0):   " << (bsp(a, b, c, edge)    ? "IN" : "OUT") << std::endl;

    return 0;
}