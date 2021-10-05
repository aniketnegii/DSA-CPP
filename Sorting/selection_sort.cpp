#include <bits/stdc++.h>

using namespace std;
void selectionsort(int a[], int n)
{
    for (int i = 0; i < n - 1; i++)
    {

        int min_index = i;
        for (int j = i; j < n; j++)
        {
            if (a[j] < a[min_index])
            {
                min_index = j;
            }
        }
        swap(a[min_index], a[i]);
    }
}
int main()
{
    int a[] = {1, 8, 5, 2, 4};
    int n = sizeof(a) / sizeof(int);
    selectionsort(a, n);
    for (int i = 0; i < n; i++)
    {
        cout << a[i] << " ";
    }

    return 0;
}
