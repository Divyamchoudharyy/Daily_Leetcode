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
private:
    void f(TreeNode* root , int lvl , int ver , vector<tuple<int,int,int>>& ans){
        if(!root) return;

        ans.push_back({ver,lvl,root->val});
        f(root->left,lvl+1,ver-1,ans);
        f(root->right,lvl+1,ver+1,ans);
    }

public:
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        vector<tuple<int,int,int>> node;
        f(root,0,0,node);
        sort(node.begin(),node.end());

        int prev = -1e9;
        vector<vector<int>> ans;
        for(auto &[l,v,data] : node){
            if(l != prev){
                ans.push_back({});
                prev = l;
            }
            ans.back().push_back(data);
        }
        return ans;
    }
};