#include <bits/stdc++.h>
using namespace std;
// cycle sort
void swap(int* a, int* b)
{
    int t=*a;
    *a= *b;
    *b= t;
}

void cycso(int arr[], int n)
{
    for(int i=0;i<n-1;i++)
    {
        int item=arr[i];
        int pos=i;
        for(int j=i+1;j<n;j++)
        if(arr[j]<item)
        pos++;
        if(pos==i)
        continue;
        while(item==arr[pos])
        pos+=1;
        if(pos!=i)
        swap(&item,&arr[pos]);
        while(pos!=i)
        {
            pos=i;
            for(int j=i+1;j<n;j++)
            if(arr[j]<item)
            pos++;
            while(item==arr[pos])
            pos++;
            if(item!=arr[pos])
            {
                swap(item,arr[pos]);
            }
        }
    }
}
int main() {
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++)
    cin>>arr[i];
    cycso(arr,n);
    for(int i=0;i<n;i++)
    cout<<arr[i];
	return 0;
}
