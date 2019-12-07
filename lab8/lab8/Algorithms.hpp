//
//  Algorithms.hpp
//  lab8
//
//  Created by  Марина on 12/4/19.
//  Copyright © 2019 Marina Polishchuk. All rights reserved.
//

#ifndef Algorithms_hpp
#define Algorithms_hpp

#include <string>
#include <iostream>

int SimpleSearch(const std::string& first, const std::string& second);
int HorspoolSearch(const std::string& first, const std::string& second);
int BoyerMooreSearch(const std::string& first, const std::string& second);
int RabinKarpeSearch(const std::string& first, const std::string& second);
int KMPSearch(const std::string& first, const std::string& second);

#endif /* Algorithms_hpp */
