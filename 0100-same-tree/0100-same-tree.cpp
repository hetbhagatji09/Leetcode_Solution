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
    void inorder(TreeNode *root,vector<int>&ans){
        if(root!=nullptr){
            inorder(root->left,ans);
            ans.push_back(root->val);
            inorder(root->right,ans);
        }
        else{
            ans.push_back(10000);
        }
    }
    void preorder(TreeNode *root,vector<int>&ans){
        if(root!=nullptr){
            ans.push_back(root->val);
            preorder(root->left,ans);
            preorder(root->right,ans);
        }
        else{
            ans.push_back(10000);
        }
    }
    bool isSameTree(TreeNode* p, TreeNode* q) {
        vector<int>v1,v2,v3,v4;
        inorder(p,v1);
        inorder(q,v2);
        preorder(p,v3);
        preorder(q,v4);
        if(v1==v2 && v3==v4){
            return true;
        }
        return false;
    }
};