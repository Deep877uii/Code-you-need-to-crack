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

    void inorder(TreeNode* root, vector<int>& arr) {
        if(root == NULL) return;

        inorder(root->left, arr);

        arr.push_back(root->val);

        inorder(root->right, arr);
    }

    bool findTarget(TreeNode* root, int k) {

        if(root == NULL) return false;

        vector<int> arr;

        inorder(root, arr);

        for(int i=0; i<arr.size(); i++) {
            for(int j=i+1; j<arr.size(); j++) {

                if(arr[i] + arr[j] == k) {
                    return true;
                }
            }
        }

        return false;
    }
};