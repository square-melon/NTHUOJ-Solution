#include "11001.h"
#include <algorithm>

Polynomial::Polynomial(const int &gp, const int co[51]) {
    for (int i = 0; i <= gp; i++) coefficients[i] = co[i];
    for (int i = gp + 1; i < 101; i++) coefficients[i] = 0;
    greatestPower = gp;
}

Polynomial Polynomial::operator+(const Polynomial &p) const {
    Polynomial res;
    int gp = max(greatestPower, p.greatestPower);
    for (int i = 0; i <= gp; i++) res.coefficients[i] = coefficients[i] + p.coefficients[i];
    while (gp > 0 && res.coefficients[gp] == 0) gp--;
    res.greatestPower = gp;
    return res;
}

Polynomial Polynomial::operator-(const Polynomial &p) const {
    Polynomial res;
    int gp = max(greatestPower, p.greatestPower);
    for (int i = 0; i <= gp; i++) res.coefficients[i] = coefficients[i] - p.coefficients[i];
    while (gp && res.coefficients[gp] == 0) gp--;
    res.greatestPower = gp;
    return res;
}

std::ostream& operator<<(std::ostream &os, const Polynomial &p) {
    int i;
    for (i = p.greatestPower; i >= 0; i--) {
        os << p.coefficients[i];
        if (i != 0) os << " ";
    }
    return os;
}