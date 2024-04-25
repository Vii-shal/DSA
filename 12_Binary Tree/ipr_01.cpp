// leetcode 889

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
    TreeNode* constructFromPrePostHelper(vector<int>& preorder,int prestart,int preend, vector<int>& postorder,int poststart,int postend,unordered_map<int,int> postmap) {

        if (prestart > preend || poststart > postend){
            return NULL;
        }

        TreeNode* root = new TreeNode(preorder[prestart]);
        if (prestart==preend){
            return root;
        }

        int leftChildVal = preorder[prestart+1];
        int leftChildIdx = postmap[leftChildVal];
        int leftSubtreeSize = leftChildIdx-poststart +1;

        root->left = constructFromPrePostHelper(preorder,prestart+1,prestart + leftSubtreeSize,postorder,poststart,leftChildIdx , postmap);

        root->right = constructFromPrePostHelper(preorder,prestart + leftSubtreeSize +1,preend,postorder,leftChildIdx+1 , postend-1 , postmap);

        return root;

    }
    TreeNode* constructFromPrePost(vector<int>& preorder, vector<int>& postorder) {
        unordered_map <int,int> postmap;
        for (int i=0;i<postorder.size();i++){
            postmap[postorder[i]] = i;
        }
        return constructFromPrePostHelper(preorder,0,preorder.size()-1,postorder,0,postorder.size()-1,postmap);
    }
};



// ---------------------------------------------------------------------------------------------------------

class Solution {
public:
    unordered_map<int, int> m; // value->index
    TreeNode* constructFromPrePost(vector<int>& pre, vector<int>& post) {
        int len = post.size();
        for (int i = 0; i < len; i++) m[post[i]] = i;
        return construct(pre, post, 0, len - 1, 0, len - 1);
    }
    
    TreeNode* construct(vector<int>& pre, vector<int>& post, int a, int b, int c, int d) {
        TreeNode* n = new TreeNode(pre[a]);
        if (a == b) return n;
        int t = pre[a + 1];
        int idx = m[t];
        int len = idx - c + 1;
        n->left = construct(pre, post, a + 1, a + len, c, c + len - 1);
        if (idx + 1 == d) return n;
        n->right = construct(pre, post, a + len + 1, b, idx + 1, d - 1);
        return n;
    }
};