//Problem  link: https://practice.geeksforgeeks.org/problems/ishaan-loves-chocolates2156/1/?category[]=Arrays&category[]=Arrays&problemStatus=solved&page=1&query=category[]ArraysproblemStatussolvedpage1category[]Arrays

#include<iostream>
using namespace std;
int main()
 {
	int T, N, max,i;
	cin>>T;
	while(T)
	{
		cin>>N;
		int arr[N];
		max=1000;
		for(i=0;i<N;i++)
		 {
		  cin>>arr[i];
		  if(arr[i]<max)
			max=arr[i];
		 }
			cout<<max<<endl;
			T--;
	}
	return 0;
}
