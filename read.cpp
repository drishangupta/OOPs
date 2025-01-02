#include <iostream>
#include <fstream>
#include <string>
using namespace std;
int main() 
{
    fstream file1("abc.txt",ios::in|ios::out|ios::app);
    int num;
    int i=0;
    int sum=0;
    while(i<9)
    {file1>>num;
    cout<<num<<endl;
    sum=sum+num;
    i++;}
    file1.close();
    fstream file2("abc.txt",ios::in|ios::app);
    string sc = "drishan";
    file2<<sc<<sum<<endl;
    file2.close();
}