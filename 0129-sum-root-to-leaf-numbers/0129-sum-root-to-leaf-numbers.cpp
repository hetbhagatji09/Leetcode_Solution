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
    void inorder(TreeNode* root,string temp,int &sum){
        if(root == nullptr) return ;
        temp += to_string(root->val);
        if(root->left == nullptr && root->right == nullptr){
            sum += stoi(temp);
        }
        inorder(root->left,temp,sum);
        
        inorder(root->right,temp,sum);

    }
    int sumNumbers(TreeNode* root) {
        int sum = 0;
        inorder(root,"",sum);
        return sum;
    }
};