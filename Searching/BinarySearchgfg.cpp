//GFG Binary Search Problem Solution
//https://practice.geeksforgeeks.org/problems/binary-search/1
int binarysearch(int a[], int n, int k)
{
    int l=0,h=n-1;
    while(l<=h)
    {
        int mid=(l+h)/2;
        if(a[mid]==k) return mid;
        if(k<a[mid])
            h=mid-1;
        else
            l=mid+1;
    }
    return -1;
}
