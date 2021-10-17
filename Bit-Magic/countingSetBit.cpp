#include <bits/stdc++.h>
using namespace std;

int count_set_bit(uint32_t n) {
        int cnt = 0,f = 1;
        // Method - 1
        // while(n>0){
        //     if(n & f == 1){
        //         cnt++;
        //     }
        //     n = n>>1;
        // }
        // Method - 2
        while(n>0){
            cnt++;
            n = n & (n-1);
        }
        return cnt;
    } 


int main()   
{    
    int t;
    cin >> t;
    while (t--)
    {
        int n,cnt=0;
        cin >>n;
        cout<<count_set_bit(n)<<endl;
        
    }
    return 0;
}
