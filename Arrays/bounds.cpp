//To find upperbound and lowerbound of an element in an array -O(N)

#include <bits/stdc++.h>
using namespace std;

int lowerbound(int A[], int val, int n)
{

    int l = 0, h = n - 1, ans = val;
    while (l <= h)
    {
        int mid = (l + h) / 2;
        if (A[mid] > val)
        {
            h = mid - 1;
        }
        else
        {
            ans = A[mid];
            l = mid + 1;
        }
    }
    return ans;
}
int upperbound(int A[], int val, int n)
{

    int l = 0, h = n - 1, ans = val;
    while (l <= h)
    {
        int mid = (l + h) / 2;
        if (A[mid] < val)
        {
            l = mid + 1;
        }
        else
        {
            ans = A[mid];
            h = mid - 1;
        }
    }
    return ans;
}

int main()
{
    // your code goes here
    int a[] = {-1, 2, 3, 5};
    int n = sizeof(a) / sizeof(int);

    int x = upperbound(a, 4, n);
    int y = lowerbound(a, 4, n);
    cout << x << endl
         << y;

    return 0;
}