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
    bool is_match(TreeNode *rootLeft,TreeNode* rootRight){
        if(rootLeft!=nullptr && rootRight!=nullptr){
            bool a=is_match(rootLeft->left,rootRight->right);
            bool b=is_match(rootLeft->right,rootRight->left);
            if((a && b) && rootLeft->val==rootRight->val) return true;

        }
        else if(rootLeft==nullptr && rootRight==nullptr) return true;
        return false;
    }
    bool isSymmetric(TreeNode* root) {
        if(root==nullptr) return true;
        return is_match(root->left,root->right);
    }
};