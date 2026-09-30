#include "Bureaucrat.hpp"
#include "ShrubberyCreatingForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include <cstdlib>
#include <ctime>

int main() {
    std::srand(std::time(NULL)); // Inicializa semilla aleatoria para Robotomy

    Bureaucrat boss("El Jefe", 1);
    Bureaucrat manager("Encargado", 40);
    Bureaucrat intern("Becario", 140);

    std::cout << "\n=== 1. Prueba: ShrubberyCreationForm ===" << std::endl;
    ShrubberyCreatingForm shrub("jardin");
    
    // Intento 1: ejecutar sin firmar
    boss.executeForm(shrub);

    // Intento 2: firmar y ejecutar
    intern.signForm(shrub);
    intern.executeForm(shrub); // Becario (140) no tiene rango (requiere 137)
    manager.executeForm(shrub); // Encargado (40) sí puede ejecutarlo

    std::cout << "\n=== 2. Prueba: RobotomyRequestForm ===" << std::endl;
    RobotomyRequestForm robot("Bender");
    
    manager.signForm(robot); // Requiere 72 para firmar
    manager.executeForm(robot); // Encargado (40) puede ejecutarlo (requiere 45)
    manager.executeForm(robot); // Segunda prueba para ver aleatoriedad

    std::cout << "\n=== 3. Prueba: PresidentialPardonForm ===" << std::endl;
    PresidentialPardonForm pardon("Arthur Dent");

    manager.signForm(pardon); // Encargado (40) no tiene rango para firmar (requiere 25)
    boss.signForm(pardon);
    manager.executeForm(pardon); // Encargado no puede ejecutar (requiere 5)
    boss.executeForm(pardon); // El Jefe (1) lo ejecuta

    std::cout << "\n=== Fin de pruebas ===" << std::endl;
    return 0;
}