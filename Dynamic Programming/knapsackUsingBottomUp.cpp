#include<bits/stdc++.h>
using namespace std;

//bottom up approach

int dp[1001][1001];

int main(){
	int n=3;
	int val[] = { 60, 100, 120 };
    int wt[] = { 10, 20, 30 };
    int w = 50;
    
	int dp[w+1][n+1];
	//we are doing 1 based indexing in bottom up approach so size is w+1 and n+1
	 //here we are filling all the blocks having either w=0 or n=0 with 0....
	for(int i=0; i<=w; i++){
		dp[0][i] = 0;
	}
	for(int i=0; i<=n; i++){
		dp[i][0] = 0;
	}
	
	for(int i=1; i<=w; i++)
	{	
		for(int j=1; j<=n; j++){
			//bag of weight i and jth item
			if(wt[j-1]<=i){
				dp[i][j] = max(val[j-1]+dp[i-wt[j-1]][j-1], dp[i][j-1]);
			}
			else{
				dp[i][j] = dp[i][j-1];
			}
		}
	}
	cout<<dp[w][n];
}
