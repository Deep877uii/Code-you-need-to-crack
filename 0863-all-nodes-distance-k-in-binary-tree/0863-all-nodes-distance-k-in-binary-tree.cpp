class Solution {
public:

    void markParent(TreeNode* root,
                    unordered_map<TreeNode*, TreeNode*>& parent_track,
                    TreeNode* target) {

        queue<TreeNode*> q;
        q.push(root);

        while(!q.empty()) {

            TreeNode* cur = q.front();
            q.pop();

            if(cur->left) {
                parent_track[cur->left] = cur;
                q.push(cur->left);
            }

            if(cur->right) {
                parent_track[cur->right] = cur;
                q.push(cur->right);
            }
        }
    }

    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {

        unordered_map<TreeNode*, TreeNode*> parent_track;

        // Store parent of every node
        markParent(root, parent_track, target);

        unordered_map<TreeNode*, bool> visited;

        queue<TreeNode*> q;
        q.push(target);
        visited[target] = true;

        int cur_level = 0;

        while(!q.empty()) {

            int size = q.size();

            // We have reached distance k
            if(cur_level == k)
                break;

            cur_level++;

            for(int i = 0; i < size; i++) {

                TreeNode* curr = q.front();
                q.pop();

                // Go left
                if(curr->left && !visited[curr->left]) {
                    q.push(curr->left);
                    visited[curr->left] = true;
                }

                // Go right
                if(curr->right && !visited[curr->right]) {
                    q.push(curr->right);
                    visited[curr->right] = true;
                }

                // Go to parent
                if(parent_track.find(curr) != parent_track.end()
                   && !visited[parent_track[curr]]) {

                    q.push(parent_track[curr]);
                    visited[parent_track[curr]] = true;
                }
            }
        }

        vector<int> ans;

        while(!q.empty()) {
            ans.push_back(q.front()->val);
            q.pop();
        }

        return ans;
    }
};