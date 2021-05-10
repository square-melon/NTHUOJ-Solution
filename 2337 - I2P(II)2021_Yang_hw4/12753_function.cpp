#include "12753.h"
#include <string.h>
#include <iomanip>

// sign : true means negative, false means positive

BigInt::BigInt() {
    for (int i = 0; i < N; i++) bigInt[i] = 0;
    sign = false;
}

BigInt::BigInt(char *str) {
    int end = 0, sz = 0;
    if (str[0] == '-') {
        sign = true;
        end = 1;
    } else sign = false;
    for (int i = strlen(str) - 1; i >= end; i -= 8) {
        int num = 0;
        for (int j = 7; j >= 0; j--) {
            if (i-j < end) continue;
            num = num * 10 + (str[i-j] - '0');
        }
        bigInt[sz] = num;
        sz++;
    }
    for (int i = sz; i < N; i++) bigInt[i] = 0;
}

BigInt::BigInt(const BigInt &b) {
    sign = b.sign;
    for (int i = 0; i < N; i++) bigInt[i] = b.bigInt[i];
}

BigInt& BigInt::operator = (const BigInt& b) {
    sign = b.sign;
    for (int i = 0; i < N; i++) bigInt[i] = b.bigInt[i];
    return *this;
}

bool BigInt::operator < (BigInt b) {
    if (sign && !b.sign) return true;
    if (!sign && b.sign) return false;
    int i = N - 1;
    while (i >= 0 && bigInt[i] == b.bigInt[i]) i--;
    if (i == -1) return false;
    if (!sign && !b.sign) return bigInt[i] < b.bigInt[i];
    else return bigInt[i] > b.bigInt[i];
}

bool BigInt::operator > (BigInt b) {
    if (sign && !b.sign) return false;
    if (!sign && b.sign) return true;
    int i = N - 1;
    while (i >= 0 && bigInt[i] == b.bigInt[i]) i--;
    if (i == -1) return false;
    if (!sign && !b.sign) return bigInt[i] > b.bigInt[i];
    else return bigInt[i] < b.bigInt[i];
}

bool BigInt::operator == (BigInt b) {
    if ((sign && !b.sign) || (!sign && b.sign)) return false;
    int i = N - 1;
    while (i >= 0 && bigInt[i] == b.bigInt[i]) i--;
    return i == -1;
}

bool BigInt::operator >= (BigInt b) {
    return (*this > b) || (*this == b);
}

bool BigInt::operator <= (BigInt b) {
    return (*this < b) || (*this == b);
}

BigInt BigInt::operator + (BigInt b) {
    BigInt res;
    for (int i = 0; i < N; i++) {
        res.bigInt[i] += bigInt[i] + b.bigInt[i];
        if (res.bigInt[i] >= BASE) {
            res.bigInt[i+1] += res.bigInt[i] / BASE;
            res.bigInt[i] %= BASE;
        }
    }
    return res;
}

BigInt BigInt::operator - (BigInt b) {
    BigInt res;
    // deal with the result of subtract to avoid negative result
    if ((*this).sign) { // negative number
        res = (*this) + b;
        res.sign = true;
    } else {
        if ((*this) >= b) {
            for (int i = 0; i < N; i++) {
                res.bigInt[i] += bigInt[i] - b.bigInt[i];
                if (res.bigInt[i] < 0) {
                    res.bigInt[i+1]--;
                    res.bigInt[i] += BASE;
                }
            }
        } else {
            for (int i = 0; i < N; i++) {
                res.bigInt[i] += b.bigInt[i] - bigInt[i];
                if (res.bigInt[i] < 0) {
                    res.bigInt[i+1]--;
                    res.bigInt[i] += BASE;
                }
            }
            res.sign = true;
        }
    }
    return res;
}

istream& operator >> (istream &is, BigInt &b) {
    char str[b.N*8+5];
    int num = 0, sz = 0;
    is >> str;
    b = str;
    return is;
}

ostream& operator << (ostream &os, BigInt &b) {
    int i = b.N - 1;
    if (b.sign) os << '-';
    while (i >= 0 && b.bigInt[i] == 0) i--;
    if (i == -1) os << '0';
    else os << b.bigInt[i];
    i--;
    for (; i >= 0; i--) os << setw(8) << setfill('0') << b.bigInt[i];
    return os;
}

void solution(BigInt &tanjiro, BigInt &zenitsu, BigInt &inosuke, int n) {
    while (n--) {
        BigInt mission;
        cin >> mission;
        // deal with the results of add and subtract to avoid negative result
        if (inosuke >= tanjiro && inosuke >= zenitsu) inosuke = inosuke - mission;
        else if (tanjiro >= zenitsu && tanjiro >= inosuke) tanjiro = tanjiro - mission;
        else if (zenitsu >= tanjiro && zenitsu >= inosuke) zenitsu = zenitsu - mission;
    }
}