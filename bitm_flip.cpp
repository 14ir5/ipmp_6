/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/
//Bit manipulation
//count bits to flipped
//
#include <iostream>

using namespace std;

void printbits(int n){
    
    if(n>1)
    printbits(n>>1);
    
    int k=n&1;
    cout<<k;
}
void nset(int n){
    int cnt=0;
    while(n){
        
        if(n&1==1)
        cnt++;
        n=n>>1;
    }
    cout<<"count="<<cnt;
}

void aflipb(int a,int b){
    int c=a^b;
    nset(c);
}
int main()
{
    int a,b;
    cin>>a;
    cin>>b;
    cout<<"the num in bits are :"<<endl;
    printbits(a);
    cout<<endl;
    printbits(b);
    cout<<endl;
    aflipb(a,b);
    return 0;
}
