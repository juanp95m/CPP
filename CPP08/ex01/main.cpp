#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include "Span.hpp"

int main()
{
    // Test 1: Ejemplo exacto del subject
    std::cout << "--- Test oficial del subject ---" << std::endl;
    try
    {
        Span sp = Span(5);
        sp.addNumber(6);
        sp.addNumber(3);
        sp.addNumber(17);
        sp.addNumber(9);
        sp.addNumber(11);

        std::cout << sp.shortestSpan() << std::endl;
        std::cout << sp.longestSpan() << std::endl;
    }
    catch (const std::exception &e)
    {
        std::cerr << "Error: " << e.what() << std::endl;
    }

    // Test 2: Prueba con 15.000 números usando addRange
    std::cout << "\n--- Test con rango masivo (15.000 elementos) ---" << std::endl;
    try
    {
        unsigned int totalElements = 15000;
        Span bigSpan(totalElements);

        std::vector<int> randomNumbers;
        std::srand(static_cast<unsigned int>(std::time(NULL)));

        for (unsigned int i = 0; i < totalElements; ++i)
            randomNumbers.push_back(std::rand());

        bigSpan.addRange(randomNumbers.begin(), randomNumbers.end());

        std::cout << "Shortest span: " << bigSpan.shortestSpan() << std::endl;
        std::cout << "Longest span:  " << bigSpan.longestSpan() << std::endl;
    }
    catch (const std::exception &e)
    {
        std::cerr << "Error: " << e.what() << std::endl;
    }

    // Test 3: Casos límite y excepciones
    std::cout << "\n--- Test de excepciones ---" << std::endl;
    try
    {
        Span emptySpan(2);
        std::cout << "Calculando en Span vacio:" << std::endl;
        emptySpan.shortestSpan();
    }
    catch (const std::exception &e)
    {
        std::cerr << "Capturado con exito: " << e.what() << std::endl;
    }

    try
    {
        Span fullSpan(1);
        fullSpan.addNumber(42);
        std::cout << "Insertando por encima de la capacidad maxima:" << std::endl;
        fullSpan.addNumber(84);
    }
    catch (const std::exception &e)
    {
        std::cerr << "Capturado con exito: " << e.what() << std::endl;
    }

    return 0;
}