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
    bool isValidBST(TreeNode* root) {
        TreeNode* cur = root;
        TreeNode* pre = NULL;
        int freq = 0;
        int n = INT_MIN;
        bool ans = true;
        while(cur!=NULL){
            if(cur->left==NULL){
                if((n>=cur->val)&&!(n==INT_MIN && freq==0)) ans = false;
                n = cur->val;
                freq++;
                cur = cur->right;
            }
            else{
                pre = cur;
                pre = pre->left;
                while(pre->right && pre->right!=cur) pre = pre->right;
                if(pre->right==NULL){
                    pre->right = cur;
                    cur = cur->left;
                }
                else{
                    pre->right = NULL;
                    if((n>=cur->val)&&!(n==INT_MIN && freq==0)) ans = false;
                    n = cur->val;
                    freq++;
                    cur = cur->right;
                }
            }
        }
        return ans;
    }
};