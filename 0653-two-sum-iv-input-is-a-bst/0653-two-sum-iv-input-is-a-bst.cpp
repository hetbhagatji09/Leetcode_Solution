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
    bool ans=false;
    unordered_set<int>set;
    void inorder(TreeNode *root,int k){
        if(root!=NULL){
            inorder(root->left,k);
            if(set.find(k-(root->val))!=set.end()){
                ans=true;
                return ;
            }
            set.insert(root->val);
            inorder(root->right,k);
        }
    }
    bool findTarget(TreeNode* root, int k) {
        inorder(root,k);
        return ans;
    }
};