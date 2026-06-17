#include<bits/stdc++.h>
using namespace std;
int main(){
    vector<int> arr = {1,2,3,4,5};
    int k = 4;
    vector<int> num(arr.size()-1,1);
    priority_queue<pair<double,int> > pq;
    for(int i = 1;i<arr.size();i++){
        pq.push({(double)(arr[i]-arr[i-1]),i-1});
    }
    for(int i = 0;i<k;i++){
        int val = pq.top().first;
        int index = pq.top().second;
        num[index]++;
        pq.pop();
        pq.push({(double)(arr[index+1]-arr[index])/num[index],index});
    }
    cout<<pq.top().first;
}