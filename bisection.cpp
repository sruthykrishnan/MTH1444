#include<iostream> 
#define EPSILON 0.01
double f(double x) 
{ 
    return x*x*x*x*x + x*x*x + 3; 
} 
void bisec(double a, double b) 
{ 
    if (f(a) * f(b) >= 0) 
    { 
        std::cout << "Assumption wrong\n"; 
        return; 
    } 
  
    double c = a; 
    while ((b-a) >= EPSILON) 
    { 
        c = (a+b)/2; 
        if (f(c) == 0.0) 
            break; 
        else if (f(c)*f(a) < 0) 
            b = c; 
        else
            a = c; 
    } 
    std::cout << "Value of root = " << c; 
} 
int main() 
{ 
    double a =-2, b = 2; 
    bisec(a, b); 
    return 0; 
}
