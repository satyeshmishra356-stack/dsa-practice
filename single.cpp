#include<bits/stdc++.h>
using namespace std;
int main(){
    vector<int> nums = {1,1,2,2,3,4,4,5,5,6,6};
    int low = 0,high = nums.size()-1;
    while(low<high){
        int mid = (low+high)/2;
        if(mid%2==1) mid--;
        if(nums[mid]==nums[mid+1]){
            low = mid;
        }
        else if(mid!=low && nums[mid]==nums[mid-1]){
            high = mid;
        }
        else{
            cout<<nums[mid];
            break;
        }
    }
    if(low==high) cout<<nums[low]; 
}