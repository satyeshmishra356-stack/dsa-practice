#include<bits/stdc++.h>
using namespace std;
void insert(int temp,stack<int> & s){
    if(s.empty() || s.top()<=temp){
        s.push(temp);
        return;
    }
    int x = s.top();
    s.pop();
    insert(temp,s);
    s.push(x);
}
void sortstack(stack<int>& s){
    if(s.empty()) return;
    int temp = s.top();
    s.pop();
    sortstack(s);
    insert(temp,s);
}
int main(){
    stack<int> s;
    s.push(4);
    s.push(1);
    s.push(3);
    s.push(2);
    sortstack(s);
    while(!s.empty()){
        cout<<s.top()<<" ";
        s.pop();
    }
    }