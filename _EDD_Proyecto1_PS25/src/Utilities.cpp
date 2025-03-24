//
// Created by Carlos Cotom on 24/03/2025.
//

#include "../includes/Utilities.h"

#include <iostream>
#include <ostream>
#include <sstream>

void Utilities::verifyNumericEntry(int &value, std::string message) {
    std::string input;
    while (true) {
        try {
            std::cout << message;
            getline(std::cin, input);
            std::stringstream ss(input);
            if (!(ss >> value) || !(ss.eof())) {
                throw std::runtime_error("Debe Ingresar un Valor Numerico");
            }
        } catch (const std::exception &e) {
            std::cout <<">> Error!!!: " << e.what() << std::endl;
        }
    }
}

