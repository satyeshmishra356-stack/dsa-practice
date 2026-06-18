#include<bits/stdc++.h>
using namespace std;
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
bool find(TreeNode* root,vector<TreeNode*> & ans,TreeNode* key){
    if(root==NULL) return false;
    ans.push_back(root);
    if(ans.back()==key) return true;
    if(find(root->left,ans,key)||find(root->right,ans,key)) return true;
    ans.pop_back();
    return false;
}
int addm(TreeNode* temp,int distance,TreeNode* nj){
    if(temp==NULL) return distance-1;
    int l = 0,r = 0;
    if(temp->left!=nj) l = addm(temp->left,distance+1,nj);
    if(temp->right!=nj) r = addm(temp->right,distance+1,nj);
    return max(l,r);
}
int add(TreeNode* temp,int distance){
    if(temp==NULL) return distance-1;
    int left = add(temp->left,distance+1);
    int right = add(temp->right,distance+1);
    return max(left,right);
}
int main(){
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);root->left->left = new TreeNode(4);root->left->left->right = new TreeNode(7);
    root->right = new TreeNode(3);root->right->left = new TreeNode(5);root->right->right = new TreeNode(6);
    int mi = 0;
    TreeNode * target = root->left;
    mi = max(add(root,0),mi);
    vector<TreeNode*> temp;
    find(root,temp,target);
    for(int i = temp.size()-2;i>=0;i--){
        mi = max(addm(temp[i],0,temp[i+1]),mi);
    }
    cout<<mi;
}