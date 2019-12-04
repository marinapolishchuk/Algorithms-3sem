//
//  main.cpp
//  lab6
//
//  Created by  Марина on 12/4/19.
//  Copyright © 2019 Marina Polishchuk. All rights reserved.
//

// Алгоритм, який за лінійний час визначав би, чи є текстовий рядок Т циклічним зсувом іншого рядка Т* (наприклад, abc та cab).

#include <iostream>
#include <string>
#include <vector>

//Подвоюємо перший текстовий рядок і застосовуємо алгоритм КМП, який працює лінійно
int circularShiftCheck(const std::string& first, const std::string& second) {

    if ((first.size() == 0 && second.size() == 0) || (first.size() != second.size())) {
        return -1;
    }
    
    std::string c = first + first;
    
    //рахуємо префікс функцію
    std::vector<int> prefix_func;
    prefix_func.resize(second.size());
    prefix_func[0] = 0;
    
    for (int i = 1; i < prefix_func.size(); ++i) {
        
        int pos = prefix_func[i - 1];
        while (pos > 0 && second[pos] != second[i]) {
            pos = prefix_func[pos - 1];
        }
        prefix_func[i] = pos + (second[pos] == second[i] ? 1 : 0);
    }
    
    int pos = 0;
    
    for (int i = 0; i < c.size(); ++i) {
        
        while (pos > 0 && (pos >= second.size() || second[pos] != c[i])) {
            pos = prefix_func[pos - 1];
        }
        if (c[i] == second[pos]) {
            pos++;
        }
        if (pos == second.size()) {
            return (i - pos + 1);
        }
    }
    
    return -1;
}

int main() {
    
    std::string first = "abcabz";
    std::string second = "aabaabaaa"; //010123452
    
    
    if (circularShiftCheck(first, second) != -1) {
        
        std::cout << "Yes" << std::endl;
        
    } else {
        
        std::cout << "No" << std::endl;
    }
    
    return 0;
}
