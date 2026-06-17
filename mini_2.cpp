#include<bits/stdc++.h>
using namespace std;
bool check(vector<int> &arr,double divi,int k){
    int num = 0;
    for(int i = 1;i<arr.size();i++){
        int inbetween = (arr[i]-arr[i-1])/divi;
        if(inbetween*divi==arr[i]-arr[i-1]) inbetween--;
        num+=inbetween;
    }
    if(num<=k) return true;
    return false;
}
double max_diff(vector<int> &arr){
    double diff = arr[1]-arr[0];
    for(int i =1;i<arr.size();i++){
        double temp_diff = arr[i]-arr[i-1];
        if(diff>temp_diff) diff = temp_diff;
    }
    return diff;
}
int main(){
    vector<int> arr = {1,7};
    int k = 3;
    double low = 0;
    double high = max_diff(arr);
    double answer = high;
    while(high-low>=0.000001){
        double mid = (low+high)/2;
        if(check(arr,mid,k)){
            high = mid;
            if(answer>mid) answer = mid;
        }
        else low = mid;
    }
    cout<<answer;
}