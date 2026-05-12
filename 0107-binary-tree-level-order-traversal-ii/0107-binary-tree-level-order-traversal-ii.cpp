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
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        queue<TreeNode*>q;
        if(root==nullptr) return {};
        q.push(root);
        vector<vector<int>>ans;
        while(!q.empty()){
            vector<int>sum;
            int size = q.size();
            for(int i=0;i<size;i++){
                TreeNode *current = q.front();
                 q.pop();
                 if(current!=nullptr)
                sum.push_back(current->val);
                if(current->left!=nullptr) q.push(current->left);
                if(current->right!=nullptr) q.push(current->right);
            }
            ans.push_back(sum);
             
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};