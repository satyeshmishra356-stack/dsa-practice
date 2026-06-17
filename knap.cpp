#include<bits/stdc++.h>
using namespace std;
bool camp(pair<int,int> a, pair<int,int> b){
    return 1LL*a.first*b.second >
           1LL*b.first*a.second;
}
int main(){
    vector<pair<int,int>> nums ={{100,20},{60,10},{100,50},{200,50}};
    int w = 90;
    double ans = 0;
    sort(nums.begin(),nums.end(),camp);
    for(int i = 0;i<nums.size();i++){
        if(nums[i].second<=w){
            ans+=nums[i].first;
            w-=nums[i].second;
        }
        else{
            double unit = (double)nums[i].first/nums[i].second;
            ans+=unit*w;
            break;
        }
    }
    cout<<ans;
}