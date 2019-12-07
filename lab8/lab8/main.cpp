//
//  main.cpp
//  lab8
//
//  Created by  Марина on 12/4/19.
//  Copyright © 2019 Marina Polishchuk. All rights reserved.
//

//Алгоритми пошуку зразка в текстовому рядку: наївний, Хорспула, Боєра-Мура, КПМ та Рабіна-Карпа і порівняйте їх ефективність.

#include "Algorithms.hpp"
#include <chrono>

int main() {
    
    std::string a = "qwerty";
    std::string b = "er";
    
    std::cout << "The string:\n" << a << std::endl;
    std::cout << "\nThe substring:\n" << b << std::endl;
    
    auto time = std::chrono::high_resolution_clock::now();
    
    
    //Simple
    std::cout << "\nSimple Search" << std::endl;
    time = std::chrono::high_resolution_clock::now();
    std::cout << "Start position: " << SimpleSearch(a, b) << std::endl;
    std::cout << "Time " << std::chrono::duration_cast<std::chrono::nanoseconds>(std::chrono::high_resolution_clock::now() - time).count() << "ns" << std::endl;
    
    
    //HORSOOL SEARCH
    std::cout << "\nHorsool Search" << std::endl;
    time = std::chrono::high_resolution_clock::now();
    std::cout << "Start position: " << HorspoolSearch(a, b) << std::endl;
    std::cout << "Time " << std::chrono::duration_cast<std::chrono::nanoseconds>(std::chrono::high_resolution_clock::now() - time).count() << "ns" << std::endl;
    
    
    //BOYER-MOORE SEARCH
    std::cout << "\nBoyer-Moore Search" << std::endl;
    time = std::chrono::high_resolution_clock::now();
    std::cout << "Start position: " << BoyerMooreSearch(a, b) << std::endl;
    std::cout << "Time " << std::chrono::duration_cast<std::chrono::nanoseconds>(std::chrono::high_resolution_clock::now() - time).count() << "ns" << std::endl;
    
    
    //RABIN-KARP SEARCH
    std::cout << "\nRabin-Karp Search" << std::endl;
    time = std::chrono::high_resolution_clock::now();
    std::cout << "Start Position: " << RabinKarpeSearch(a, b) << std::endl;
    std::cout << "Time " << std::chrono::duration_cast<std::chrono::nanoseconds>(std::chrono::high_resolution_clock::now() - time).count() << "ns" << std::endl;

    
    //KMP
    std::cout << "\nKnuth-Morris-Pratt Search" << std::endl;
    time = std::chrono::high_resolution_clock::now();
    std::cout << "Start position: " << KMPSearch(a, b) << std::endl;
    std::cout << "Time " << std::chrono::duration_cast<std::chrono::nanoseconds>(std::chrono::high_resolution_clock::now() - time).count() << "ns" << std::endl;

    return 0;
}


