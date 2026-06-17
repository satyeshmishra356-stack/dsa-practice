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
    bool check(TreeNode* a,TreeNode* b){
        if(a==NULL && b==NULL) return true;
        if(a==NULL || b==NULL) return false;
        if(a->val!=b->val) return false;
        if(!check(a->left,b->right)) return false;
        if(!check(a->right,b->left)) return false;
        return true;
    }
    bool isSymmetric(TreeNode* root) {
        if(root==NULL) return true;
        TreeNode* a = root->left;
        TreeNode* b = root->right;
        if(check(a,b)) return true;
        return false;
    }
};