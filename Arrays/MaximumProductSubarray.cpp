// { Driver Code Starts
#include <bits/stdc++.h>

using namespace std;

 // } Driver Code Ends
//User function template for C++
class Solution{
public:

	// Function to find maximum product subarray
	long long maxProduct(int *arr, int n) {
	    // code here
	    long long ans=INT_MIN;
	    long long max_prod=1;
	    long long min_prod=1;
	    
	    for(int i=0;i<n;i++){
	        if(arr[i]<0){
	            swap(max_prod,min_prod);
	        }
	        max_prod= max(arr[i]*max_prod,arr[i]+0ll);
	        min_prod= min(arr[i]*min_prod,arr[i]+0ll);
	        if(arr[i]==0){
	            max_prod=1;
	            min_prod=1;
	        }
	        ans=max(ans,max_prod);
	    }
	    return ans;
	}
};

// { Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, i;
        cin >> n;
        int arr[n];
        for (i = 0; i < n; i++) {
            cin >> arr[i];
        }
        Solution ob;
        auto ans = ob.maxProduct(arr, n);
        cout << ans << "\n";
    }
    return 0;
}  // } Driver Code Ends
