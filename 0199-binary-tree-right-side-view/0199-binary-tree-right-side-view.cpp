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
    vector<int> rightSideView(TreeNode* root) {
        vector<int>result;
        if(root==nullptr) return result;
        queue<TreeNode *>q;
        q.push(root);
        vector<vector<int>>ans;
        while(!q.empty()){
            int size=q.size();
            vector<int>list;
            for(int i=0;i<size;i++){
                TreeNode *node=q.front();
                q.pop();
                list.push_back(node->val);
                if(node->left) q.push(node->left);
                if(node->right) q.push(node->right);
            }
            ans.push_back(list);

        }
        for(auto v:ans){
            result.push_back(v.back());
        }
        return result;
       
    }
};