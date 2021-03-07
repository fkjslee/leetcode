class Solution {
public:
    int monotoneIncreasingDigits(int N) {
        if (!N) return 0;
        int digit[20], p = 0;
        while (N) {
            digit[p++] = N % 10;
            N /= 10;
        }
        for (int i = p - 1; i >= 0; --i)
            printf("digit[%d] = %d\n", i, digit[i]);
        for (int i = p - 1; i > 0; --i) {
            if (digit[i] > digit[i+1]) {
                digit[i]--;
                for (int j = 0; j < i; ++j)
                    digit[j] = 9;
            }
        }
        int ans = 0;
        for (int i = 0; i < p; ++i)
            ans = ans * 10 + digit[i];
        return ans;
    }
};
