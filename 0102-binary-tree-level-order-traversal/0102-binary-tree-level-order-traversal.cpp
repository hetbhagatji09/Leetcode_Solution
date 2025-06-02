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
    vector<vector<int>> levelOrder(TreeNode* root) {
        queue<TreeNode*>q;
        q.push(root);
        vector<vector<int>>ans;
        if(root==nullptr) return ans;
        while(!q.empty()){
            int levelSize=q.size();
            vector<int>list;     
            for(int i=0;i<levelSize;i++){
                TreeNode *front=q.front();
                if(front->left) q.push(front->left);
                if(front->right) q.push(front->right);
                list.push_back(front->val);
                q.pop();   
            }
            ans.push_back(list);
        }
        return ans;
        
    }
};