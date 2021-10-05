// largest element-O(N)
#include <bits/stdc++.h>
using namespace std;

int largestElement(vector<int> A)
{
    int n = A.size();
    int x;
    for (int i = 0; i < n; i++)
    {
        x = A[0];
        if (A[i] > x)
        {
            x = A[i];
        }
    }
    return x;
}