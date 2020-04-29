#include <iostream>
#include <string>
int main()
{
    int n,i,j;
    float x[25],f[25],p,factor,s=0;
    std::cout<<"Number of functions = ";
    std::cin>>n;
    std::cout<<"\n X with corresponding f(x) = ";
    for(i=0;i<n;i++)
    std::cin>>x[i]>>f[i];
    std::cout<<"\n Enter value of t ";
    std::cin>>p;

    for(j=0;j<n-1;j++)
    {
        for(i=n-1;i>j;i--)
            f[i]=(f[i]-f[i-1])/(x[i]-x[i-j-1]);
    }
    for(i=n-1;i>=0;i--)
    {
        factor=1;
        for(j=0;j<i;j++)
            factor*=(p-x[j]);
            
        factor*=f[j];
        s+=factor;
    }
    std::cout<<"Value = "<<s;
    return 0;
}
