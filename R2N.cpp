#include<bits/stdc++.h>
using namespace std;
class node{
public:
    int val;
    node* left;
    node* right;
    node(int v){
        val = v;
        left = NULL;
        right = NULL;
    }
};
bool find(node* root,vector<int> & ans,int key){
    if(root==NULL) return false;
    ans.push_back(root->val);
    if(ans.back()==key) return true;
    if(find(root->left,ans,key)||find(root->right,ans,key)) return true;
    ans.pop_back();
    return false;
}
int main(){
    node *root = new node(1);
    root->left = new node(2);root->right = new node(3);
    root->left->left = new node(4); root->left->right = new node(5);root->left->right->left = new node(6);root->left->right->right = new node(7);
    vector<int> ans;
    if(!find(root,ans,7)) cout<<"Doesn't Found";
    else{
        for(auto it :  ans){
            cout<<it<<" ";
        }
    }
    return 0;
}