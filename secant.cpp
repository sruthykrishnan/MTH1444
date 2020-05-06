#include <iostream> 
#include<cmath>
float f(float x) 
{ 
    float f = pow(x,5) + pow(x,3) +3; 
    return f; 
} 
  
void sec(float x1, float x2, float E) 
{ 
    float n = 0, xm, x0, c; 
    if (f(x1) * f(x2) < 0) { 
        do
        { 
            x0 = (x1 * f(x2) - x2 * f(x1)) / (f(x2) - f(x1)); 
            c = f(x1) * f(x0);
            x1 = x2; 
            x2 = x0; 
            n++; 
  
            if (c == 0) 
                break; 
            xm = (x1 * f(x2) - x2 * f(x1)) / (f(x2) - f(x1)); 
        } while (fabs(xm - x0) <= E); 
  
        std::cout << "Root = " << x0 << endl; 
        std::cout << "No. of iterations = " << n << endl; 
    } 
    else
        std::cout << "Can't find a root"; 
} 
  
int main() 
{ 
    float x1 = -1, x2 = -1.1, E = 0.001; 
    sec(x1, x2, E); 
    return 0; 
}
