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
    int ct=0;
    int result=-1;
    void inorder(TreeNode *root,int k){
        if(root!=NULL){
            inorder(root->left,k);
            ct++;
            if(ct==k){
                result=root->val;
                return ;
            }
            inorder(root->right,k);
        }
        
    }
        
    
    
    int kthSmallest(TreeNode* root, int k) {
        inorder(root,k);
        return result;
    }
};