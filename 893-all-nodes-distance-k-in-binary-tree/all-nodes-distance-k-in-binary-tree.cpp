/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        vector<int> ans;
        if (!root)
            return ans;
        unordered_map<int, TreeNode*> m;
        queue<TreeNode*> q;
        q.push(root);

        while (!q.empty()) {
            int size = q.size();
            for (int i = 0; i < size; i++) {
                TreeNode* curr = q.front();
                q.pop();

                if (curr->left) {
                    m[curr->left->val] = curr;
                    q.push(curr->left);
                }
                if (curr->right) {
                    m[curr->right->val] = curr;
                    q.push(curr->right);
                }
            }
        }
        unordered_map<int, int> vis;
        q.push(target);
        while (k-- && !q.empty()) {
            int n = q.size();
            for (int i = 0; i < n; i++) {
                TreeNode* p = q.front();
                q.pop();

                vis[p->val] = 1;

                if (p->left && !vis[p->left->val])
                    q.push(p->left);

                if (p->right && !vis[p->right->val])
                    q.push(p->right);

                if (m[p->val] && !vis[m[p->val]->val])
                    q.push(m[p->val]);
            }
        }
        while(!q.empty()){
            ans.push_back(q.front()->val);
            q.pop();
        }
        return ans;
    }
};