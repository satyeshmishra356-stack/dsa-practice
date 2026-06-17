#include<bits/stdc++.h>
using namespace std;
vector<int> dp;
bool check_palindrom(int i,int j,string &s){
    while(i<=j){
        if(s[i]!=s[j]) return false;
        i++;
        j--;
    }
    return true;
}
int cc(string &s,int i){
    if(i==s.size()) return 0;
    if(dp[i]!=-1) return dp[i];
    int partition = s.size()-1;
    for(int j = i;j<s.size();j++){
        if(check_palindrom(i,j,s)){
            partition = min(partition,1+cc(s,j+1));
        }
    }
    dp[i] = partition;
    return partition;
}
int main(){
    string s = "bababcbadcede";
    string st = "";
    int i = 0;
    dp.resize(s.size(),-1);
    cout<<cc(s,i)-1;
}