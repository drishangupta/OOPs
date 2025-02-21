#include <iostream>
using namespace std;

template <typename T>
T fun(T a, T b)
{
    return a+b;
}
int main()
{
    cout<<fun<double>('a','b')<<endl;
    cout<<(char)fun(1,2);
}