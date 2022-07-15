#include <iostream>
#include <bits/stdc++.h> //header is used as sort function is used in the program
using namespace std;

int main() {
    //n-number of co-orniates
    //k-number of mice
    //c-cat's position
    //a[k]- array of position of mice in the co-ordinate
    int n,k,c=0,no_of_mice=0,i;
    cin>>n>>k;
    int a[k];
    for(int i=0;i<k;i++){
        cin>>a[i];
    }
    //sorted the array of position of mice,so that the mice nearer to the hole will get into it quickly
    sort(a,a+k,greater<int>());
    //if mice enter a hole by 1 step,the cat shifts by 1 step.Accordingly,if a mice enter a hole by 3 step,the cat shifts by 3 step.
    //check the loop until the cat's position is greater than n
    for(i=0;i<n;i++){
        if(c>=a[i])
            break;
        c=c+n-a[i]; //number of steps moved by cat
        no_of_mice++; //count of number of mice in the hole for instance
    }
    //print the number of mice saved by entering the hole
    cout<<no_of_mice;
}
