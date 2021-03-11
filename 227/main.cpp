class Solution {
public:
    stack<int> nums;
    stack<char> exp;

    int isdigit(char c) {
        return c >= '0' && c <= '9';
    }

    void calc() {
        int u2 = nums.top(); nums.pop();
        int u1 = nums.top(); nums.pop();
        //cout << "calc " << exp.top() << ' ' << u1 << ' ' << u2 << endl;
        if (exp.top() == '+') nums.push(u1 + u2);
        else if (exp.top() == '-') nums.push(u1 - u2);
        else if (exp.top() == '*') nums.push(u1 * u2);
        else if (exp.top() == '/') nums.push(u1 / u2);
        exp.pop();
    }

    int calculate(string s) {
        if (s[0] == '-') s = "0" + s;
        string temp;
        for (char c : s) if (c != ' ') temp += c;
        s = temp;
        int p = 0;
        while (p < s.size()) {
            char c = s[p];
            if (isdigit(c)) {
                string buffer;
                for ( ; isdigit(s[p]); ++p) buffer += s[p];
                p--;
                istringstream iss(buffer);
                int num; iss >> num;
                nums.push(num);
            } else if (s[p] == '(') {
                exp.push(s[p]);
            } else if (s[p] == ')') {
                while (true) {
                    if (exp.top() == '(') {
                        exp.pop();
                        break;
                    } else if (exp.top() == '+' || exp.top() == '-') {
                        calc();
                    } else {
                        return -1; // impossible
                    }
                }
            } else if (s[p] == '+' || s[p] == '-') {
                if (exp.empty()) exp.push(s[p]);
                else {
                    while (exp.size())
                        calc();
                    exp.push(s[p]);
                }

            } else if (s[p] == '*' || s[p] == '/') {
                if (exp.empty()) exp.push(s[p]);
                else if (exp.top() == '*' || exp.top() == '/') {
                    while (exp.size() && (exp.top() == '*' || exp.top() == '/'))
                        calc();
                    exp.push(s[p]);
                } else if (exp.top() == '+' || exp.top() == '-') {
                    exp.push(s[p]);
                }
            }
            p++;
        }

        while (!exp.empty()) {
            calc();
        }

        if (nums.size() != 1) return -1;

        return nums.top();
    }
};
