#include<iostream> 
#include<cmath>
#define EPSILON 0.001 
double f(double x) 
{ 
    return x*x*x*x*x + x*x*x + 3; 
} 
double derivf(double x) 
{ 
    return 5*x*x*x*x + 3*x*x; 
} 
void NR(double x) 
{ 
    double h = f(x) / derivf(x); 
    while (abs(h) >= EPSILON) 
    { 
        h = f(x)/derivf(x); 
        x = x - h; 
    } 
  
    std::cout << "value of root = " << x; 
} 
int main() 
{ 
    double x0 = -2; 
    NR(x0); 
    return 0; 
}

