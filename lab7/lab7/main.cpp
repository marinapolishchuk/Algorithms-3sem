//
//  main.cpp
//  lab7
//
//  Created by  Марина on 12/4/19.
//  Copyright © 2019 Marina Polishchuk. All rights reserved.
//

/*Узагальніть метод Рабіна-Карпа пошуку зразка в текстовому рядку так, щоб він дозволив розв’язати задачу пошуку заданого зразка
 розміром m на m у символьному масиві розміром n на n. Зразок можна рухати по горизонталі та вертикалі, але не обертати.*/

#include <iostream>
#include <string>


using namespace std;
const int P = 31;
const int MAXM = 1000;

int m, n;
int power[MAXM];
int ha[MAXM][MAXM], hb[MAXM][MAXM];
string a[MAXM], b[MAXM];

void calculatePowers(int n) {
    power[0] = 1;
    for (int i = 1; i < n; i++) {
        power[i] = power[i - 1] * P;
    }
}

void makeHash(string s, int* h) {
    h[0] = s[0];
    for (int i = 1; i < s.size(); i++) {
        power[i] = power[i - 1] * P;
        h[i] = h[i - 1] + s[i] * power[i];
    }
}

bool trivialCheck(int t, int q, int l, int r) {
    for (int i = l; i <= r; i++) {
        if (a[q][i] != b[q - t][i - l]) {
            return false;
        }
    }
    return true;
}

bool check(int t, int q, int l, int r) {
    if (ha[q][r] - (l ? ha[q][l - 1] : 0) != hb[q - t][n - 1] * power[l]) {
        return false;
    }
    else if (trivialCheck(t, q, l, r)) {
        return true;
    }
    return false;
}

/*будемо шукати в n нуьовий рядок рядка m алгоритмом рабіна-карпа, якщо знайшли її то перевірямо відрізки рядків під неє тим самим алгоритмом*/
int main() {
    cout << "Enter the size of text (n) and size of substr (m)" << endl;
    cin >> m >> n;
    if (m < n) {
        cout << "Error! size of substr is greater" << endl;
        return 1;
    }
    calculatePowers(m);
    
    cout << "dksfj" << endl;
    for (int i = 0; i < m; i++) {
        cin >> a[i];
        makeHash(a[i], ha[i]);
    }
    cout << " dkfsjkldf" << endl;
    for (int i = 0; i < n; i++) {
        cin >> b[i];
        makeHash(b[i], hb[i]);
    }
    
    for (int i = 0; i < m - n + 1; i++) {
        for (int j = 0; j < m - n + 1; j++) {
            bool found = true;
            for (int k = i; k < i + n; k++) {
                if (!check(i, k, j, j + n - 1)) {
                    
                    found = false;
                    break;
                }
            }
            if (found) {
                cout << "YES in [" << i << ", " << j << "]" << endl;
                
                return 0;
            }
        }
    }
    cout << "Not found" << endl;
    
    return 1;
}
