/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <iostream>

using namespace std;

int unset(unsigned int n)
{
    int k= n & (n - 1);
    cout<<k;
}
 

int main()
{
    int n;
    cin>>n;
    unset(n);
    return 0;
}
