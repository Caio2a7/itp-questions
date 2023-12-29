#include "Carro.hpp"
#include <iostream>

int main(){
    Carro carro1;

    carro1.setAnoFabricacao(1995);
    carro1.setMarca("BMW");
    carro1.setModelo("M5");
    carro1.imprimirDados();

    return 0;
}