#include <bits/stdc++.h>
using namespace std;
int main()
{
    int arr[100], i, s, n;
    cout << "enter the size of array" << endl;
    cin >> n;
    cout << "enter the elements of array" << endl;
    for (i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    cout << "enter the element you want to search" << endl;
    cin >> s;
    cout << linearsearch(arr, n, s) << endl;
    cout << binarysearch(arr, n, s) << endl;
}
/**********************LINEAR SEARCH******************/
int linearsearch(int arr[], int n, int s)
{
    for (int i = 0; i < n; i++)
    {
        if (arr[i] == s)
        {
            return i;
        }
    }
}
/*******************8BINARY SEARCH********************/
int binarysearch(int arr[], int n, int s)
{
    int low = 0, mid, high = n, i;
    while (low <= high)
    {
        mid = (low + high) / 2;
        if (arr[mid] == s)
        {
            return mid;
        }
        else if (arr[mid] > s)
        {
            high = mid - 1;
        }
        else
        {
            low = mid + 1;
        }
    }
}