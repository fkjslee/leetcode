#include <iostream>
#include <vector>
#include <map>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    map<TreeNode*, TreeNode*> pa;
    map<TreeNode*, int> level;

    void dfs(TreeNode* root, TreeNode* f, int dep) {
        if (!root) return;
        if (f) pa[root] = f;
        level[root] = dep;
        dfs(root->left, root, dep + 1);
        dfs(root->right, root, dep + 1);
    }

    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        dfs(root, 0, 0);
        while (level[p] != level[q]) {
            if (level[p] > level[q]) p = pa[p];
            else q = pa[q];
        }
        while (p != q) {
            p = pa[p];
            q = pa[q];
        }
        return p;
    }
};
