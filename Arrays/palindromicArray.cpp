#include <iostream>
#include <string.h>
using namespace std;
int PalinArray(int a[], int n);
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        int a[n];
        for (int i = 0; i < n; i++)
            cin >> a[i];
        cout << PalinArray(a, n) << endl;
    }
} // } Driver Code Ends
int PalinArray(int a[], int n)
{ //add code here.
    for (int i = 0; i < n; i++)
    {
        int rev = 0, c, d = a[i];
        while (a[i] > 0)
        {
            c = a[i] % 10;
            rev = rev * 10 + c;
            a[i] = a[i] / 10;
        }
        if (rev != d)
        {
            return 0;
        }
    }
    return 1;
}