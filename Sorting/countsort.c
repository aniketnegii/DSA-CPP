#include<stdio.h>
int max1(int a[],int n)
{
    int l=a[0];
    for(int i=0;i<n;i++)
    {
        if(a[i]>l)
            l=a[i];
    }
    return l;
}
void countsort(int a[],int n)
{
    int k=max1(a,n);
    int count[k+1];
    for(int i=0;i<=k;i++)
    {
        count[i]=0;
    }
    int b[100];
    for(int i=0;i<n;i++)
    {
        count[a[i]]++;
    }
    for(int i=1;i<=k;i++)
    {
        count[i]=count[i]+count[i-1];
    }
    for(int i=n-1;i>=0;i--)
    {
        b[--count[a[i]]]=a[i];
    }
    for(int i=0;i<n;i++)
    {
        a[i]=b[i];
    }
    for (int i=0; i<n; i++) 
        {
        	printf("%d ",a[i]); 
        }
}

int main(void) 
{ 
    int t=3;
    while(t--)
    {
    int n;
    printf("Enter size\n");
    scanf("%d",&n);
    int a[n];
    printf("Enter array elements\n");
    for(int i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
    }
    printf("Sorted array:-\n"); 
    countsort(a,n); 
    printf("\n");
    }
}
 