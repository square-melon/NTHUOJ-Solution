#ifndef FUNCTION_H_
#define FUNCTION_H_

#include <iostream>
using namespace std;

/*
 * Explanation on variables:
 *   sign - whether the stored number is positive or negative
 *   bigInt - array to store numeric value
 *   WIDTH - number of digits stores in an bigInt entry
 *   BASE - each entry of bigInt stores [0, BASE)
 */
class BigInt
{
private:
    constexpr static int N = 150;
    constexpr static int WIDTH = 8, BASE = 100000000;
    bool sign;
    int bigInt[N];
public:
    // constructor
    BigInt();
    BigInt(char*);
    BigInt(const BigInt&); 
    // copy assignment operator
    BigInt &operator = (const BigInt&);
    // comparison operator
    bool operator < (BigInt);
    bool operator > (BigInt);
    bool operator == (BigInt);
    bool operator >= (BigInt);
    bool operator <= (BigInt);
    // arithmetic operator
    BigInt operator + (BigInt);
    BigInt operator - (BigInt);
    // insertion & extraction operator
    friend istream& operator >> (istream&, BigInt&);
    friend ostream& operator << (ostream&, BigInt&);
};

void solution(BigInt &tanjiro, BigInt &zenitsu, BigInt &inosuke, int n);

/*
 * Suggestions on implemention
 *
 * Try to implement operator >> with the help of BigInt(char *num)
 * For example, 
istream &operator >> (istream &in, BigInt &n)
{
    char str[100]; cin >> str;
    n = BigInt(str);
    // some more necessary codes ...
}
 */

#endif  // FUNCTION_H_
