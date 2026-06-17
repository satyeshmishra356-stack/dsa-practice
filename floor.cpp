#include<bits/stdc++.h>
using namespace std;
int main(){
    vector<int> arr ={1,2,3,4,5,6,7,9,10,15,17};
    int low = 0,high = arr.size()-1;
    int answer = 0;
    while(low<=high){
        int mid = (low+high)/2;
        if(arr[mid]<=16){
            answer = mid;
            low = mid+1;
        }
        else{
            if(arr[low]>16) break;
            high = mid-1;
        }
    }
    cout<<arr[answer];
}