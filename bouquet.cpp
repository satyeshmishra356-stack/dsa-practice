#include<bits/stdc++.h>
using namespace std;
bool check(vector<int> &nums,int m,int k,int day){
    int occurence = 0;
    for(int i = 0;i<nums.size();i++){
        if(nums[i]<=day) occurence++;
        else occurence = 0;
        if(occurence==k){
            m--;
            occurence = 0;
        }
    }
    if(m<=0) return true;
    return false;
}
int main(){
    vector<int> bloomDay = {1,10,3,10,2};
    int m = 3,k = 1;
    auto s = minmax_element(bloomDay.begin(),bloomDay.end());
    int low = *s.first,high = *s.second;
    int answer = high;
    while(low<=high){
        int mid = (low+high)/2;
        if(check(bloomDay,m,k,mid)){
            if(answer>mid) answer = mid;
            high = mid-1;
        }
        else{
            low = mid+1;
        }
    }
    cout<<answer;
}