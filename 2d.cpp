#include<bits/stdc++.h>
using namespace std;
int main(){
    vector<vector<int> > arr = {{0,0,1,1,1},{0,0,0,0,0},{1,1,1,1,1},{0,0,0,0,0},{0,1,1,1,1}};
    int maxt = 0;
    for(int i = 0;i<arr.size();i++){
        int low = 0;
        int high = arr[i].size()-1;
        int min_index = arr[i].size();
        while(low<=high){
            int mid = (low+high)/2;
            if(arr[i][mid]>0){
                high = mid-1;
                min_index = min(mid,min_index);
            }
            else low = mid+1;
        }
        maxt = max(maxt,(int)arr[i].size()-min_index);
    }
    cout<<maxt;
}