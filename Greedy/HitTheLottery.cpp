//problem link: https://codeforces.com/problemset/problem/996/A

#include<iostream>
using namespace std;
int main ()
{
    int n;
    cin>>n;
    int temp=0;
    while(n!=0)
    {
        if(n>=100)
        {
            temp= temp + n/100;
            n=n%100;
        }
        else if(n>=20 && n<100)
        {
            temp= temp + n/20;
            n=n%20;
        }
        else if(n>=10 && n<20)
        {
            temp =temp + n/10;
            n=n%10;
        }
        else if(n>=5 && n<10)
        {
            temp = temp + n/5;
            n=n%5;
        }
        else if(n>=1 && n<5)
        {
            temp = temp + n;
            n=n%1;
        }
    }
    cout<<temp;
    return 0;
}
