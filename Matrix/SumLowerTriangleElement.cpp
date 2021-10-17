#include<iostream>
using namespace std;
int main()
{
        int i, j, arr[10][10], sum, rows, cols;
        cout<<"\n Enter Number of Rows    : ";
        cin>>rows;

        cout<<"\n Enter Number of Columns : ";
        cin>>cols;

        for (i = 0; i < rows; i++)  //Accepting the Elements in Matrix
        {
                for (j = 0; j < cols; j++)
                {
                        cout<<"\n Enter the Elements : ";//<<arr[i]<<arr[j];
                        cin>>arr[i][j];
                }
        }
        cout<<"\n Matrix is : \n";
        for (i = 0; i < rows; i++)  //Displaying the Elements in Matrix
        {
                cout<<" ";
                for (j = 0; j < cols; j++)
                {
                        cout<<" ";
                        cout<<arr[i][j];
                }
                cout<<"\n";
        }
        cout<<"\n Lower Triangle Elements : \n"; //Displaying Lower Triangular Elements
        for (i = 0; i < rows; i++)
        {
                cout<<" ";
                for (j = 0; j < cols; j++)
                {
                        if (i > j)  
                        {
                                cout<<" ";
                                cout<<arr[i][j];  
                        }
                }
                cout<<"\n";
        }
        //Sum of all Lower Triangular Elements
        sum = 0;
        for (i = 0; i < rows; i++)
        for (j = 0; j < cols; j++)
        {
                if (i > j)  
                {
                        sum = sum + arr[i][j];  
                }
        }
        cout<<"\n Sum of Lower Triangle Elements : "<<sum;  //Printing the sum of lower triangular elements
        return (0);
}
