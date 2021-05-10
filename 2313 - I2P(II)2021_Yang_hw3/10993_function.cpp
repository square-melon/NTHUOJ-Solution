#include <iostream>
#include "10993.h"
#define max(a, b) a > b ? a : b

using namespace std;

Polynomial::Polynomial() {
    greatestPower = 0;
    for (int i = 0; i < 51; i++) coefficients[i] = 0;
}

Polynomial::Polynomial(const int p, const int co[51]) {
    greatestPower = p;
    for (int i = p; i >= 0; i--) coefficients[i] = co[i];
    for (int i = p + 1; i < 51; i++) coefficients[i] = 0;
}

Polynomial Polynomial::add(const Polynomial p) const {
    int power = max(greatestPower, p.greatestPower);
    Polynomial res;
    for (int i = power; i >= 0; i--)
        res.coefficients[i] = coefficients[i] + p.coefficients[i];
    while (power > 0 && res.coefficients[power] == 0) power--;
    res.greatestPower = power;
    return res;
}

Polynomial Polynomial::subtract(const Polynomial p) const {
    int power = max(greatestPower, p.greatestPower);
    Polynomial res;
    for (int i = power; i >= 0; i--)
        res.coefficients[i] = coefficients[i] - p.coefficients[i];
    while (power > 0 && res.coefficients[power] == 0) power--;
    res.greatestPower = power;
    return res;
}

Polynomial Polynomial::multiplication(const Polynomial p) const {
    int power = greatestPower + p.greatestPower;
    Polynomial res;
    for (int i = 0; i <= greatestPower; i++) {
        for (int j = 0; j <= p.greatestPower; j++) 
            res.coefficients[i+j] += coefficients[i] * p.coefficients[j];
    }
    while (power > 0 && res.coefficients[power] == 0) power--;
    res.greatestPower = power;
    return res;
}

void Polynomial::output() const {
    for (int i = greatestPower; i >= 0; i--) {
        cout << coefficients[i];
        if (i != 0) cout << ' ';
    }
}