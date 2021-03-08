#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    struct Node {
        int val;
        int pos;
        Node(int val, int pos): val(val), pos(pos) {}
    };

    static bool cmp(const Node& a, const Node& b) {
        return a.pos < b.pos;
    }

    int N = 500;
    void inorder(TreeNode* root, vector<vector<Node>>& order, int pos, int dep) {
        order[pos + N / 2].push_back({root->val, dep});
        if (root->left) inorder(root->left, order, pos-1, dep+1);
        if (root->right) inorder(root->right, order, pos+1, dep+1);
    }

    vector<vector<int>> verticalOrder(TreeNode* root) {
        vector<vector<Node>> order;
        if (!root) return vector<vector<int>>();
        order.resize(N);
        inorder(root, order, 0, 0);
        while (order[0].empty()) {
            order.erase(order.begin());
        }
        while (order[order.size() - 1].empty()) {
            order.pop_back();
        }
        for (int i = 0; i < order.size(); ++i) {
            sort(order[i].begin(), order[i].end(), cmp);
        }
        vector<vector<int>> ans;
        ans.resize(order.size());
        for (int i = 0; i < order.size(); ++i) {
            for (const Node& node : order[i])
                ans[i].push_back(node.val);
        }
        return ans;
    }
};

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}