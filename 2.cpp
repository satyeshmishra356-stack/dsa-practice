#include<bits/stdc++.h>
using namespace std;
int main(){
    vector<int> arr = {1,2,2,1,3,6,9,9};
    int x = 0;
    for(int i = 0;i<arr.size();i++){
        x = x^arr[i];
    }
    int temp = (x & (x-1))^x;
    int xf = 0;
    int xs = 0;
    for(int i = 0;i<arr.size();i++){
        if(arr[i]&temp) xf = xf^arr[i];
        else xs = xs^arr[i];
    }
    cout<<xf<<" "<<xs;
}