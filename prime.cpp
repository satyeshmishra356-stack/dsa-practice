#include<bits/stdc++.h>
using namespace std;
int main(){
    int n = 60;
    vector<int> a;
    for(int i = 2;i*i<=n;i++){
        if(n%i==0){
            a.push_back(i);
            while(n%i==0) n = n/i;
        }
    }
    for(auto i : a){
        cout<<i<<" ";
    }
}