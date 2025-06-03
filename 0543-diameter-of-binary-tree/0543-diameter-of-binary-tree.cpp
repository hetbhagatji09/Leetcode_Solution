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
    int maxDepth(TreeNode* root) {
        if(root==nullptr) return 0;
        return max((maxDepth(root->left)),(maxDepth(root->right)))+1;
    }
    void inorder(TreeNode *root,int &ans){
        if(root!=nullptr){
            inorder(root->left,ans);
            int leftHeight=maxDepth(root->left);
            int rightHeight=maxDepth(root->right);
            ans=max(ans,abs(leftHeight+rightHeight));
            inorder(root->right,ans);
        }
    }
    int diameterOfBinaryTree(TreeNode* root){
        if(root==nullptr) return 0;
        int ans=0;
        inorder(root,ans);
        return ans;

    }
};