#include<bits/stdc++.h>
using namespace std;
int main(){
    vector<int> nums = {3,3,3,1,2,1,1,2,3,3,4};
    int k = 1;
    int l = 0,r = 0;
    int ans = 0;
    int cont = -1;
    queue<int> q;
    while(r<nums.size()){
        if(nums[r]==cont) r++;
        else if(k!=0){
            cont = nums[r];
            q.push(r);
            k--;
            r++;
        }
        else{
            ans = max(ans,r-l);
            l = q.front()+1;
            q.pop();
            k++;
            cont = nums[r];
        }
        }
       cout<<max(ans,r-l);
}
