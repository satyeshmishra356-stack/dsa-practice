/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    void level(vector<int> &ans,int l,queue<TreeNode*> q){
        if(q.empty()) return;
        ans.push_back(-1);
        queue<TreeNode*> temp;
        while(!q.empty()){
            ans[l] = q.front()->val;
            if(q.front()->left!=NULL) temp.push(q.front()->left);
            if(q.front()->right!=NULL) temp.push(q.front()->right);
            q.pop();
        }
        l++;
        level(ans,l,temp);
    }
    vector<int> rightSideView(TreeNode* root) {
        if(root==NULL) return {};
        vector<int> ans;
        queue<TreeNode*> q;
        q.push(root);
        int l = 0;
        level(ans,l,q);
        return ans;
    }
};