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
    int maxHeight(TreeNode *root){
        if(root==NULL) return 0;
        return max(maxHeight(root->left),maxHeight(root->right))+1;
    }
    void inorder(TreeNode *root,bool &ans){
        if(root!=nullptr){
            inorder(root->left,ans);
            int leftHeight=maxHeight(root->left);
            int rightHeight=maxHeight(root->right);
            if(abs(leftHeight-rightHeight) > 1) ans=false;
            inorder(root->right,ans);
        }
    }
    bool isBalanced(TreeNode* root) {
        bool ans=true;
        inorder(root,ans);
        return ans;
    }
};