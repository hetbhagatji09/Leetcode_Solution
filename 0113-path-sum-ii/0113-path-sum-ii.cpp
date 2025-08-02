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
    void dfs(TreeNode *root,int targetSum,vector<int>&list,vector<vector<int>>&ans){
        if(root==nullptr) return;
        list.push_back(root->val);
        targetSum-=root->val;
        if(root->left==nullptr && root->right== nullptr && targetSum==0){
           ans.push_back(list);
        }
        else{
            dfs(root->left,targetSum,list,ans);
            dfs(root->right,targetSum,list,ans);
        }
        
        list.pop_back();

    }
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<vector<int>>ans;
        vector<int>list;
        dfs(root,targetSum,list,ans);
        return ans;
    }
};