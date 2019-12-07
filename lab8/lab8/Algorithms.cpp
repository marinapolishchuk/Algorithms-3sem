//
//  Algorithms.cpp
//  lab8
//
//  Created by  Марина on 12/4/19.
//  Copyright © 2019 Marina Polishchuk. All rights reserved.
//

#include "Algorithms.hpp"
#include <vector>
#include <algorithm>
//#define ALPHABET 256

//teta(nm)
int SimpleSearch(const std::string &first, const std::string& second) {
    
    int s1 = first.size();
    int s2 = second.size();
    
    for (int i = 0; i <= s1 - s2; ++i) {
        
        bool flag = true;
        
        for (int j = 0; j < s2; ++j) {
        
            if (first[i + j] != second[j]) {
                flag = false;
                break;
            }
        }
        if (flag) {
            return i;
        }
    }
    
    return -1;
}



bool comp(std::string::const_iterator a, const std::string::const_iterator b, int num) {
    for (auto i = a, j = b; i < a + num; i++, j++) {
        if (*i != *j) return false;
    }
    return true;
}

//O(m/n) - best; O(m/alphabet.size) - average;
int HorspoolSearch(const std::string& first, const std::string& second) {
    
    unsigned int skip_table[256];
    
    for (int i = 0; i < 256; i++) {
        skip_table[i] = second.size();
    }

    for (int i = 0; i < second.size() - 1; i++) {
        skip_table[(int)second[i]] = second.size() - i - 1;
    }

    int i = 0;
    while (i <= first.size() - second.size()) {
        if (first[i + second.size() - 1] == second[second.size() - 1]) {
            if (comp(first.begin() + i, second.begin(), second.size() - 2) == true) {
                return i;
            }
        }
        i += skip_table[(int)first[i + second.size() - 1]];
    }

    return -1;
}


int BoyerMooreSearch(const std::string& first, const std::string& second) {

    std::vector<int> good_shift(second.size() + 1, second.size());
    std::vector<int> bad_char(256, second.size());
    std::vector<int> z(second.size(), 0);

    for (int j = 1, maxZidx = 0, maxZ = 0; j < second.size(); ++j) {
        if (j <= maxZ) z[j] = std::min(maxZ - j + 1, z[j - maxZidx]);

        while (j + z[j] < second.size() && first[second.size() - 1 - z[j]] == first[second.size() - 1 - (j + z[j])]) z[j]++;

        if (j + z[j] - 1 > maxZ) {
            maxZidx = j;
            maxZ = j + z[j] - 1;
        }
    }

    for (int j = second.size() - 1; j > 0; --j) {
        good_shift[second.size() - z[j]] = j;
    }

    for (int j = 1, r = 0; j <= second.size() - 1; ++j) {
        if (j + z[j] == second.size()) {
            for (; r <= j; r++) {
                if (good_shift[r] == second.size()) {
                    good_shift[r] = j;
                }
            }
        }
    }


    for (int j = 0; j < second.size() - 1; j++) {
        bad_char[(int)second[j]] = second.size() - j - 1;
    }

    int i = 0;
    while (i <= second.size() - first.size()) {
        int j = 0;
        for (j = second.size() - 1; j >= 0 && second[j] == first[i + j]; --j);
        if (j < 0) {
            return i;
        }
        else {
            i += std::max((good_shift[j + 1]), (int)(bad_char[(int)first[i + j]] - second.size() + j + 1));
        }
    }
    return -1;
    
}


int RabinKarpeSearch(const std::string& first, const std::string& second) {

    const int p = 31;
    std::vector<long long> p_pow(std::max(second.length(), first.length()));
    p_pow[0] = 1;
    for (size_t i = 1; i<p_pow.size(); ++i) {
        p_pow[i] = p_pow[i - 1] * p;
    }

    std::vector<long long> h(first.length());
    for (size_t i = 0; i<first.length(); ++i) {
        h[i] = (first[i] - 'a' + 1) * p_pow[i];
        if (i)  h[i] += h[i - 1];
    }

    long long h_s = 0;
    for (size_t i = 0; i<second.length(); ++i) {
        h_s += (second[i] - 'a' + 1) * p_pow[i];
    }

    for (size_t i = 0; i + second.length() - 1 < first.length(); ++i) {
        long long cur_h = h[i + second.length() - 1];
        if (i) {
            cur_h -= h[i - 1];
        }
        if (cur_h == h_s * p_pow[i]) {
            return i;
        }
    }

    return -1;
}


int KMPSearch(const std::string& first, const std::string& second) {
    
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
    
    for (int i = 0; i < first.size(); ++i) {
        
        while (pos > 0 && (pos >= second.size() || second[pos] != first[i])) {
            pos = prefix_func[pos - 1];
        }
        if (first[i] == second[pos]) {
            pos++;
        }
        if (pos == second.size()) {
            return (i - pos + 1);
        }
    }
    
    return -1;
}
