#include<bits/stdc++.h>
using namespace std;
string addBinary(string a, string b) {

    string ans = "";

    for(int i = 0; i < a.size(); i++) {

        int sum = (a[i] - '0') + (b[i] - '0');

        ans += (sum + '0');
    }

    return ans;
}
string getstr(int i,int val,bool ans){
    if(i==0){
        return "0";
    }
    string s(val+1,'0');
    if(i>=pow(2,val)){
        if(ans==true) s[s.size()-1] = '-1';
        s[0]='1';
        i = i-pow(2,val);
        ans = true;
    }
    else ans = false;
    return addBinary(s,getstr(i,val-1,true))
}
int main(){
    int number = 3;
    vector<string> num;
    for(int i = 0;i<pow(2,number);i++){
        string a = getstr(i,number-1,false);
        if(a[a.size()-1]=='-1') continue;
        num.emplace_back(a);
    }
}
