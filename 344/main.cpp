#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    void reverseString(vector<char>& s) {
        for (int i = 0, j = s.size() - 1; i < j; ++i, --j)
            swap(s[i], s[j]);
    }
};

int main() {
    Solution sol;
    vector<char> vec;
    vec.push_back('1');
    vec.push_back('2');
    sol.reverseString(vec);
    for (char c : vec)
        cout << c << endl;
    std::cout << "Hello, World!" << std::endl;
    return 0;
}