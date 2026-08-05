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
    int d = 0;
private:
    int f(TreeNode* root){
        if(!root) return 0;

        int l = f(root->left);
        int r = f(root->right);

        d = max(d,l+r);

        return 1 + max(l,r);
    }
public:
    int diameterOfBinaryTree(TreeNode* root) {
        f(root);
        return d;
    }
};