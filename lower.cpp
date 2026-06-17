#include<bits/stdc++.h>
using namespace std;
int main(){
    vector<int> a ={1,2,3,4,5,6,7,8,9,10};
    int lower;
    cout<<"Enter Upper bound :";
    cin>>lower;
    int low = 0,high = a.size()-1;
    int answer = high;
     while(high>=low){
        int mid = (high+low)/2;
        if(a[mid]>=lower){
            answer = mid;
            high = mid-1;
        }
        else{
            low = mid+1;
        }
     }
     cout<<"Lower bound is"<<answer;
}