#include<bits/stdc++.h>
using namespace std;
int main(){
    vector<int> nums = {1,2,3,4};
    int k = 2;
    int low = 0,high = nums.size()-1;
    while(low<=high){
        int mid = (low+high)/2;
        if(nums[mid]-mid-1>=k) high = mid-1;
        else low = mid+1;
    }
    cout<<k+high+1;
}