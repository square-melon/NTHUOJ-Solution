#ifndef POLYNOMIAL_H
#define POLYNOMIAL_H
#include <iostream>

using namespace std;
class Polynomial
{
    friend std::ostream &operator<<(std::ostream & os, const Polynomial &);
    
public:
    Polynomial(){
        greatestPower=0;
        for(int i =0 ; i< 101 ; i++){
            coefficients[i]=0;
        }
    }
    Polynomial(const int &, const int [51]);
    Polynomial operator+( const Polynomial & ) const; // addition
    Polynomial operator-( const Polynomial & ) const; // subtraction
    Polynomial operator*( const Polynomial & b) const{
        int g = greatestPower+b.greatestPower;
        Polynomial ans ;
        ans.greatestPower=g ;
        for(int i =0 ; i<= g ; i++){
            for(int k =0 ; k<= i ;k++){
                ans.coefficients[i]+=coefficients[k]*b.coefficients[i-k];
            }
        }
        return  ans;
    } // multiplication function
private:
    int coefficients[101];
    int greatestPower;
}; // end class Polynomial

#endif

