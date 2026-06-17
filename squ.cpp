#include<bits/stdc++.h>
using namespace std;
int powern(int x,int n){
    int answer = 1;
    for(int i = 1;i<=n;i++) answer = answer*x;
    return answer;
}
int main(){
    int n;
    cout<<"Enter a interger number";
    cin>>n;
    cout<<"Enter value of n";
    int s;
    cin>>s;
    int answer = 1;
    int low = 1,high = n;
    while(low<=high){
        int mid = (low+high)/2;
        if(powern(mid,s)>n) high = mid-1;
        else if(n>powern(mid,s)){
            low = mid+1;
            answer = mid;
        }
        else{
            answer = mid ;
            break;
        }
    }
    cout<<answer;
}