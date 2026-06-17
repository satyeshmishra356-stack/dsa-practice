#include<bits/stdc++.h>
using namespace std;
int hours(vector<int> &nums,int k){
    int hours = 0;
    for(int i = 0;i<nums.size();i++){
        if(nums[i]%k!=0){
            hours = hours+(nums[i]/k)+1;
        }
        else
            hours = hours+(nums[i]/k);
    }
    return hours;
}
int main(){
    vector<int> nums = {30,11,23,4,20};
    int h;
    cin>>h;
    int high = *max_element(nums.begin(), nums.end());
    int answer = high;
    int low = 1;
    while(low<=high){
        int mid = (low+high)/2;
        if(hours(nums,mid)>h) low = mid+1;
        else if(hours(nums,mid)<h) high = mid-1;
        else{
            if(mid<answer) answer = mid;
            high = mid-1;
        }
    }
    cout<<answer;
}