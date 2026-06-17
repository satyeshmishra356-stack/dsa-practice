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
    void level(map<int,map<int,multiset<int>>> &mpp,queue<pair<TreeNode*,int>> q,int l){
        if(q.empty()) return;
        queue<pair<TreeNode*,int>> temp;
        while(!q.empty()){
            mpp[q.front().second][l].insert(q.front().first->val);
            if(q.front().first->left!=NULL) temp.push({q.front().first->left,q.front().second-1});
            if(q.front().first->right!=NULL) temp.push({q.front().first->right,q.front().second+1});
            q.pop();
        }
        l++;
        level(mpp,temp,l);
    }
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        map<int,map<int,multiset<int>>> mpp;
        queue<pair<TreeNode*,int> > q;
        if(root!=NULL) q.push({root,0});
        level(mpp,q,0);
        vector<vector<int>> ans;
        for(auto s : mpp){
            vector<int> temp;
            for(auto it : s.second){
                temp.insert(temp.end(),it.second.begin(),it.second.end());
            }
            ans.push_back(temp);
        }
        return ans;
    }
};