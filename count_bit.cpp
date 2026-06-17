#include<bits/stdc++.h>
using namespace std;
int main(){
    int n = 7;
    int count = 0;
    for(int i = 1;i<n;i=i<<1){
        if(n&i) count++;
    }
    cout<<count;
}