#include <iostream>
#include <fstream>
#include <cmath>
#include <iomanip>
using namespace std;

long double Nfactorial(long double y)
{
    long double factorial = 1.0;
    if(y == 0.0)
        return factorial;
    else
    {
        for(long double i = y; i > 0.0; --i)
        {
         factorial = factorial * i;
        }
        return factorial;
    }
}

long double M(long double x)
{
    long double partial_sum = 0.0;
    for(long double i = 0.0; i < x; ++i)
    {
        long double x_over_n = (1.0 / Nfactorial(i));
        partial_sum = partial_sum + x_over_n;
    }
    return partial_sum;
}


int main()
{
    long double n = 23.0;
    long double nth_e = M(n);
    ofstream obj("e_expansion.txt",::ios::app);
    if(!obj)
        cout<<"Could not open file for output"<<endl;
    else
        obj<< setprecision(1000) << nth_e <<endl;

    cout<< "The Maclauren expansion of e^1 to n = " << n <<": "<<endl;
    cout<<"\n"<< setprecision(48) << nth_e ;

    cin.sync();
    cin.get();
    return 0;
}

