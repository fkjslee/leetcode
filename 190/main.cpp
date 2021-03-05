#include <iostream>

class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        uint32_t digit[100], p = 0;
        while (n) {
            digit[p++] = n % 10;
            n /= 10;
        }
        uint32_t u = 0;
        for (int i = p-1; i >= 0; --i)
            u = u * 10 + digit[i];
        return u;
    }
};

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}