
#include<iostream>
#include<math.h>   //for pow() function
using namespace std;

int main()
{

    int x,n,result;

    cout<<"Enter value of X :: ";
    cin>>x;
    cout<<"\nEnter value of N :: ";
    cin>>n;

    result=pow(x,n);

    cout<<"\nThe Power of Number [ "<<x<<" ^ "<<n<<" ] = "<<result<<"\n";

    return 0;
}
