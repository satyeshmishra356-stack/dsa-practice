#include<bits/stdc++.h>
using namespace std;
int main(){
    vector<vector<int> > matrix;
    int n = matrix.size(),m = matrix[0].size();
    int target;
    if(m>=n){
    int low = 0,high = n;
    while( ((high-low)>0 && matrix[high][high]<=target) || (high-low)>1){
        int mid = (low+high)/2;
        if(matrix[mid][mid]<target) low = mid;
        else if(matrix[mid][mid]>target) high = mid;
        else return true;
        if(((high-low)>0 && matrix[high][high]<=target)){
            low = high;
            break;
        }
    }
    int lowf = low,highf = m-1;
    while(lowf<=highf){
        int midf = (lowf+highf)/2;
        if(matrix[lowf][midf]>target) highf = midf-1;
        else if(matrix[lowf][midf]<target) lowf = midf+1;
        else return true;
    }
    lowf = 0;
    highf = high;
    while(lowf<=highf){
        int midf = (lowf+highf)/2;
        if(matrix[high][midf]>target) highf = midf-1;
        else if(matrix[high][midf]<target) lowf = midf+1;
        else return true;
    }
}
}