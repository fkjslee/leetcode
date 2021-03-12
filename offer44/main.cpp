class Solution {
public:

    long long int nine(int p) {
        if (p == 0) return 1;
        --p;
        long long int ten = 1;
        for (int i = 0; i < p; ++i) ten = ten * 10;
        return 9 * ten;
    }

    long long int ten(int p) {
        long long int ten = 1;
        p--;
        for (int i = 0; i < p; ++i) ten = ten * 10;
        return ten;
    }

    int core(long long int n) {
        if (n == 0) return 0;
        n--;
        int p = 1;
        for ( ; ; p++) {
            if (n >= nine(p) * p)
                n -= nine(p) * p;
            else break;
        }
        int u = n / p + ten(p);
        int v = n % p;
        //cout << "u = " << u << " v = " << v << " p = " << p << endl;
        int digit[12];
        int d = 0;
        while (u) {
            digit[d++] = u % 10;
            u /= 10;
        }
        d -= v;
        return digit[d-1];
    }

    int findNthDigit(int n) {
        return core(n);
    }
};
