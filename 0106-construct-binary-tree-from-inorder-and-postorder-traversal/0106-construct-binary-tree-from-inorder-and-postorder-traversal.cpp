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
    TreeNode *buildHelperTree(vector<int>&inorder,vector<int>&postorder,int start,int end,unordered_map<int,int>&umap,int &ct){
        if(start > end) return nullptr;
        int rootValue=postorder[ct--];
        int rootIndex=umap[rootValue];

        TreeNode *newNode=new TreeNode(rootValue);
        newNode->right=buildHelperTree(inorder,postorder,rootIndex+1,end,umap,ct);
        newNode->left=buildHelperTree(inorder,postorder,start,rootIndex-1,umap,ct);
        return newNode;

    }
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        unordered_map<int,int>umap;
        for(int i=0;i<inorder.size();i++){
            umap[inorder[i]]=i;
        }
        int ct=inorder.size()-1;
        return buildHelperTree(inorder,postorder,0,inorder.size()-1,umap,ct);
    }
};