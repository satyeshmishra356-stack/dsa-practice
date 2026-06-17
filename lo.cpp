#include<bits/stdc++.h>
using namespace std;
int ns(string &s,int k){
        int l = 0;
        int lon = 0;
        int freq[26];
        int distinct = 0;
        for(int i = 0;i<26;i++) freq[i] = 0;
        for(int i = 0;i<s.size();i++){
            if(freq[s[i]-'a']==0) distinct++;
            freq[s[i]-'a']++;
            while(distinct>2){
                freq[s[l]-'a']--;
                if(freq[s[l-'a']]==0) distinct--;
                l++;
            }  
            lon = max(lon,i-l+1);
        }
        return lon;
    }
int main(){
    string s = "aaabbccd";
    cout<<ns(s,2);
}