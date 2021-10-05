#include<bits/stdc++.h>
using namespace std;


/*
  Author Lakshay Goel
  Github profile: https://github.com/MrLakshay
  Problem statement : You are going to travel to another city that is located 𝑑 miles away from your home city. Your can can travel
  at most 𝑚 miles on a full tank and you start with a full tank. Along your way, there are gas stations at
  distances stop1, stop2, . . . , stop𝑛 from your home city. What is the minimum number of refills needed?
  
  Exampple:
  Input:
  950
  400
  4
  200 375 550 750
  Output:
  2
*/

int main(){
    long long distance,mileage,count;
    cin>>distance>>mileage>>count;
    count+=2;
    long long stop[count];
    stop[0]=0;
    for (long long i = 1; i < count-1; i++)
    {
        cin>>stop[i];
    }
    stop[count-1]=distance;
    long long reful=0,last=0;
    for(long long i=1;i<count;i++){
        if(stop[i]-stop[i-1]>mileage){
        cout<<-1;
        return 0;}
    }
    for(long long i=0;i<count-1;i++){
        if(stop[i]-stop[last]<mileage && stop[i+1]-stop[last]>mileage){
            last=i;
            reful++;
            //cout<<3;
        }
        else if(stop[i]-stop[last]==mileage){
            last=i;
            reful++;
            //cout<<4;
        }
    }
    if(distance-stop[last]>mileage){
        reful++;
        //cout<<5;
    }
    if(distance-stop[count-1]>mileage ){
        cout<<"-1";}
    cout<<reful<<endl;
    return 0;
}
