#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

void bucketSort(float arr[], int n)
{

	vector<float> b[n];


	for (int i = 0; i < n; i++) {
		int bi = n * arr[i]; // Index in bucket
		b[bi].push_back(arr[i]);
	}

  
	for (int i = 0; i < n; i++)
		sort(b[i].begin(), b[i].end());


	int index = 0;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < b[i].size(); j++)
			arr[index++] = b[i][j];
}

void main()
{
	float arr[]
		= { 0.8347, 0.52365, 0.416, 0.132, 0.3333 };
	int n = sizeof(arr) / sizeof(arr[0]);
	bucketSort(arr, n);

	for (int i = 0; i < n; i++)
		cout << arr[i] << " ";
	return 0;
}
