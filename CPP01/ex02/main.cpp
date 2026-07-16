#include <iostream>
#include <string>

int main(void){
    std::string myVariable = "HI THIS IS BRAIN";
    std::string *stringPTR = &myVariable;
    std::string &stringREF = myVariable;

    // ADRESS
    std::cout << &myVariable << std::endl; //(Direccion de la variable original)
    std::cout << stringPTR << std::endl;   //(Direccion almacenada del puntero)
    std::cout << &stringREF << std::endl;  //(Direccion de la referencia)

    // VALUES
    std::cout << *stringPTR << std::endl;  //(Valor apuntado por el puntero)
    std::cout << myVariable << std::endl;  //(Valor de la variable original)
    std::cout << stringREF << std::endl;   //(Valor de la referencia)

    return 0;
}