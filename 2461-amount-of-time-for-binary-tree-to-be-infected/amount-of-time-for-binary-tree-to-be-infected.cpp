/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
class Solution {
private:
    void f(TreeNode* root, unordered_map<TreeNode*, TreeNode*>& m,
        TreeNode*& startNode, int start) {
        queue<TreeNode*> q;
        q.push(root);

        while (!q.empty()) {
            int size = q.size();
            for (int i = 0; i < size; i++) {
                TreeNode* curr = q.front();
                q.pop();
                if (curr->val == start)
                    startNode = curr;
                if (curr->left) {
                    m[curr->left] = curr;
                    q.push(curr->left);
                }
                if (curr->right) {
                    m[curr->right] = curr;
                    q.push(curr->right);
                }
            }
        }
    }

public:
    int amountOfTime(TreeNode* root, int start) {
        unordered_map<TreeNode*, TreeNode*> m;
        TreeNode* startNode = nullptr;

        f(root, m, startNode, start);
        unordered_set<TreeNode*> vis;
        queue<TreeNode*> q;

        q.push(startNode);
        vis.insert(startNode);
        int time = -1;
        while (!q.empty()) {
            int size = q.size();
            for (int i = 0; i < size; i++) {
                TreeNode* curr = q.front();
                q.pop();

                vector<TreeNode*> n = {curr->left,curr->right,m.count(curr) ? m[curr] : nullptr};
                for(TreeNode* x : n){
                    if(x && !vis.count(x)){
                        vis.insert(x);
                        q.push(x);
                    }
                }
            }
            time++;
        }
        return time;
    }
};