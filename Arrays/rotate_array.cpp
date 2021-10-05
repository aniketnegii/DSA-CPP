// k rotate -- rotate an array k times clockwise

#include <bits/stdc++.h>
using namespace std;
void reverse(vector<int> &a, int l, int h)
{
    while (l < h)
    {
        swap(a[l], a[h]);
        l += 1;
        h -= 1;
    }
}
vector<int> kRotate(vector<int> a, int k)
{
    int n = a.size();
    reverse(a, 0, n - k - 1);
    reverse(a, n - k, n - 1);
    reverse(a, 0, n - 1);
    return a;
}