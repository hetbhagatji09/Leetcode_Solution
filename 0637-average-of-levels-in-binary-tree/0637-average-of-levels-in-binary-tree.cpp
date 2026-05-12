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
    vector<double> averageOfLevels(TreeNode* root) {
        queue<TreeNode*>q;
        q.push(root);
        vector<double>ans;
        while(!q.empty()){
            
          
            double sum = 0;
            int size = q.size();
            for(int i=0;i<size;i++){
                TreeNode *current = q.front();
                 q.pop();
                sum += current->val;
                if(current->left) q.push(current->left);
                if(current->right) q.push(current->right);
            }
            if(size>0)
            ans.push_back(sum/size);
             
        }
        return ans;
    }
};