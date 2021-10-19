#include<bits/stdc++.h>
using namespace std;

//meoization is top-bottom approach...

int dp[1001][1001];

int knapsack(int w,int n,int wt[],int val[]){
	if(n==0 || w==0){
		return 0;
	}
	if(dp[w][n]!=-1){
		return dp[w][n];
	}
	if(wt[n-1]<=w){
		return dp[w][n] = max(val[n-1]+knapsack(w-wt[n-1], n-1, wt, val), knapsack(w, n-1, wt, val));
	}
	else{
		return dp[w][n] = knapsack(w, n-1, wt, val);
	}
}

int main(){
	int n=3;
	int val[] = { 60, 100, 120 };
    int wt[] = { 10, 20, 30 };
    int W = 50;
    
    memset(dp, -1, sizeof(dp));
    
    cout<<knapsack(W, n, wt, val);
}
