#include<bits/stdc++.h>
using namespace std;
int b_s(vector<int> nums,int low,int high,int target){
    while(low<=high){
        int mid = (low+high)/2;
        if(nums[mid]>target){
            high = mid-1;
        }
        else if(nums[mid]<target) low = mid+1;
        else return mid;
    }
    return -1;
}
bool is_sorted(vector<int> nums,int low,int high){
    if(nums[low]<=nums[high]) return true;
    return false;
}
int main(){
    int target,answer = -1;
    cin>>target;
    vector<int> nums = {4,5,6,7,8,0,1,2};
    int low = 0,high = nums.size()-1;
    if(is_sorted(nums,low,high)){
            answer = b_s(nums,low,high,target);
            cout<<answer;
            return 0;
    }
    if(nums.size()==1||nums.size()==0){
        cout<<-1;
        return 0;
    } 
    while(low<=high){
        int mid = (low+high)/2;
        if(is_sorted(nums,low,mid)){
            if(nums[low]<=target && nums[mid]>=target){
            answer = b_s(nums,low,mid,target);
            cout<<answer;
            return 0;
            }
            else{
                low = mid+1;
            }
        }
        else if(is_sorted(nums,mid+1,high)){
            if(nums[mid+1]<=target && nums[high]>=target){
            answer = b_s(nums,mid+1,high,target);
            cout<<answer;
            return 0;
        }
        else high = mid-1;
    }
    }
    cout<<answer;
    return 0;
}