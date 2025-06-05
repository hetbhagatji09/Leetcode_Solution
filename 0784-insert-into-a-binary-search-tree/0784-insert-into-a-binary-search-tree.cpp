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
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        TreeNode *node=new TreeNode(val);
        if(root==nullptr){
            root=node;
            return root;
        }
        TreeNode *roott=root;
        while(roott!=nullptr){
            if(roott->val > val){
                if(roott->left==nullptr){
                    roott->left=node;
                    break;
                }
                else
                roott=roott->left;
            }
            else{
                if(roott->right==nullptr){
                    roott->right=node;
                    break;
                }
                else roott=roott->right;

            }
           
        }
        return root;
    }
};