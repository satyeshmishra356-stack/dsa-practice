/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        TreeNode* ans = root;
        TreeNode* cur = root;
        while(cur!=NULL){
            if(cur->val<p->val && cur->val<q->val){
                cur = cur->right;
            }
            else if(cur->val>p->val && cur->val>q->val) cur = cur->left;
            else{
                ans = cur; 
                break;
            }
        }
        return ans;
    }
};