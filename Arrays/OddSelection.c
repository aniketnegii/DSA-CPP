//https://codeforces.com/problemset/problem/1363/A

#include<cstdio>
#include<cstring>
#include<algorithm>
#include<iostream>
#include<cmath>
 
using namespace std;
 
int main()
{
    int t, n, x, i;
    scanf("%d", &t);
    while (t--)
    {
        scanf("%d %d", &n, &x);
        int a[1001], k = 0, l = 0;
        for (i = 0; i<n; i++)
        {
            scanf("%d", &a[i]);
            if (a[i] % 2 == 0)
            {
                k += 1;
            }
            else
            {
                l += 1;
            }
        }
        if (k == 0)
        {
            if (x % 2 != 0)
            {
                printf("Yes\n");
            }
            else
            {
                printf("No\n");
            }
        }
        else if (l == 0)
        {
            printf("No\n");
        }
        else if (l % 2 != 0)
        {
            printf("Yes\n");
        }
        else if (x != n)
        {
            printf("Yes\n");
        }
        else
        {
            printf("No\n");
        }
    }
    return 0;
}
