/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:
    void trav(TreeNode* temp,string &ans){
        if(temp==NULL){
            ans.push_back('N');
            ans.push_back(' ');
            return;
        }
        ans+=to_string(temp->val);
        ans.push_back(' ');
        ans+=to_string(temp->val);
        ans.push_back(' ');
        ans.push_back('L');
        trav(temp->left,ans);
        ans+=to_string(temp->val);
        ans.push_back(' ');
        ans.push_back('R');
        trav(temp->right,ans);
    }
    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        string ans = "";
        trav(root,ans);
        return ans;
    }
    int ge(string &data,int &i){
        int ans = 0;
        int mul = 1;
        if(data[i]=='-'){
            mul = -1;
            i++;    
        }
        while(i<data.size() && data[i]!=' '){
            ans = ans*10;
            ans+=data[i]-'0';
            i++;
        }
        return mul*ans;
    }
    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        if(data=="N ") return NULL;
        int i = 0;
        unordered_map<int,TreeNode*> mpp;
        int pre = ge(data,i);
        TreeNode* root = new TreeNode(pre);
        mpp[pre] = root;
        i++;
        while(i<data.size()){
            if(data[i]=='L'){
                i++;
                if(data[i]!='N'){
                    int val = ge(data,i);
                    mpp[pre]->left = new TreeNode(val);
                    mpp[val] = mpp[pre]->left;
                }
                i++;
            }
            else if(data[i]=='R'){
                i++;
                if(data[i]!='N'){
                    int val = ge(data,i);
                    mpp[pre]->right = new TreeNode(val);
                    mpp[val] = mpp[pre]->right;
                }
                i++;
            }
            else{
                pre = ge(data,i);
                i++;
            }
        }
        return root;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));