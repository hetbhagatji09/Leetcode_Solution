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
    TreeNode* buildWholeTree(vector<int>&preorder,vector<int>&inorder,int start,int end,unordered_map<int,int>&umap){
        if(start > end) return nullptr;
        int rootValue=preorder[ct];
        TreeNode *root=new TreeNode(rootValue);
        ct++;
        int rootIndex=umap[rootValue];
        root->left=buildWholeTree(preorder,inorder,start,rootIndex-1,umap);
        root->right=buildWholeTree(preorder,inorder,rootIndex+1,end,umap);
        return root;
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        unordered_map<int,int>umap;
        for(int i=0;i<inorder.size();i++){
            umap[inorder[i]]=i;
        }
        return buildWholeTree(preorder,inorder,0,inorder.size()-1,umap);
    }
};