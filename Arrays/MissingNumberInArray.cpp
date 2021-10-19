#include <bits/stdc++.h>
using namespace std;

int getMissingNo(int a[], int n)
{
	int x1 = a[0];

	int x2 = 1;

	for (int i = 1; i < n; i++)
		x1 = x1 ^ a[i];

	for (int i = 2; i <= n + 1; i++)
		x2 = x2 ^ i;

	return (x1 ^ x2);
}

