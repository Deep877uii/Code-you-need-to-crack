class Solution {
public:

    TreeNode* cap(TreeNode* root, vector<int>& preorder) {
        int n = preorder.size();

        for(int i = 1; i < n; i++) {

            TreeNode* temp = root;

            while(true) {

                if(preorder[i] < temp->val) {

                    if(temp->left == NULL) {
                        temp->left = new TreeNode(preorder[i]);
                        break;
                    }
                    else {
                        temp = temp->left;
                    }
                }

                else {

                    if(temp->right == NULL) {
                        temp->right = new TreeNode(preorder[i]);
                        break;
                    }
                    else {
                        temp = temp->right;
                    }
                }
            }
        }

        return root;
    }

    TreeNode* bstFromPreorder(vector<int>& preorder) {

        TreeNode* root = new TreeNode(preorder[0]);

        return cap(root, preorder);
    }
};