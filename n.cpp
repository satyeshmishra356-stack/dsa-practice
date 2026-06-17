#include<bits/stdc++.h>
using namespace std;
class train{
public:
    int data ;
    char s;
};
bool cmp(train a, train b){
    if(a.data == b.data)
        return a.s < b.s;  // 'A' before 'D'
    return a.data < b.data;
}
int main(){
    vector<int> start  = {900,945,955,1100,1500,1800};
    vector<int> end = {920,1200,1130,1150,1900,2000};
    vector<train> nums;
    for(int i = 0;i<start.size();i++){
        train temp;
        temp.data = start[i];
        temp.s = 'A';
        nums.push_back(temp);
        temp.data = end[i];
        temp.s = 'D';
        nums.push_back(temp);
    }
    sort(nums.begin(),nums.end(),cmp);
    int ans = 0;int count=0;
    for(int i = 0;i<nums.size();i++){
        if(nums[i].s=='A') count++;
        else count--;
        ans = max(count,ans);
    }
    cout<<ans;
}