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
    vector<int> inorderTraversal(TreeNode* root) {
        TreeNode* cur = root;
        TreeNode* pre = NULL;
        vector<int> ans;
        while(cur!=NULL){
            if(cur->left==NULL){
                ans.push_back(cur->val);
                cur = cur->right; 
            }
            else{
                pre = cur->left;
                while(pre->right && pre->right!=cur){
                    pre = pre->right;
                }
                if(pre->right==NULL){
                    pre->right = cur;
                    cur = cur->left;
                }
                else{
                    pre->right = NULL;
                    ans.push_back(cur->val);
                    cur = cur->right;
                }
            }
        }
        return ans;
    }
};


//preorder

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
    vector<int> preorderTraversal(TreeNode* root) {
        TreeNode* cur = root;
        TreeNode* pre = NULL;
        vector<int> ans;
        while(cur!=NULL){
            if(cur->left==NULL){
                ans.push_back(cur->val);
                cur = cur->right; 
            }
            else{
                pre = cur->left;
                while(pre->right && pre->right!=cur){
                    pre = pre->right;
                }
                if(pre->right==NULL){
                    pre->right = cur;
                    ans.push_back(cur->val);
                    cur = cur->left;
                }
                else{
                    pre->right = NULL;
                    cur = cur->right;
                }
            }
        }
        return ans;
    }
