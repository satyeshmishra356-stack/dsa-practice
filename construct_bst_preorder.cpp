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
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        TreeNode* root = NULL,*pre = NULL;
        stack<TreeNode*> st;
        int i = 0;
        while(i<preorder.size()){
            while(!st.empty() && st.top()->val<preorder[i]){
                pre = st.top();
                st.pop();
            }
            TreeNode* node = new TreeNode(preorder[i++]);
            if(pre==NULL){
                if(st.empty()){
                    root = node;
                }
                else{
                    st.top()->left = node;
                }
                st.push(node);
                pre = NULL;
            }
            else{
                pre->right = node;
                st.push(node);
                pre = NULL;
            }
        }
        return root;
    }
};