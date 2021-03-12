#include <iostream>
#include <queue>
#include <sstream>
#include <map>
#include <vector>

using namespace std;

class Solution {
public:
    struct Pos {
        int row, col;
        Pos() {}
        Pos(int row, int col) : row(row), col(col) {}
        bool operator == (const Pos& rhs) const {
            return row == rhs.row && col == rhs.col;
        }
        bool operator < (const Pos& rhs) const {
            if (row != rhs.row) return row < rhs.row;
            return col < rhs.col;
        }
        friend ostream& operator << (ostream& os, const Pos& rhs) {
            os << "row = " << rhs.row << " col = " << rhs.col;
            return os;
        }
    };

    vector<vector<int>> dp;
    vector<Pos> id2Pos;
    map<Pos, int> pos2ID;
    vector<vector<char>> graph;
    vector<vector<int>> vis;

    int inbound(Pos p) {
        int i = p.row;
        int j = p.col;
        if (i < 0 || i >= graph.size() || j < 0 || j >= graph[0].size()) return false;
        char u = graph[i][j];
        return u == '.' || u == 'S' || u == 'T' || u == 'B';
    }

    void printGraph(int i, int j) {
        auto see = vector<vector<char>>(graph);
        for (int u = 0; u < see.size(); ++u) {
            for (int v = 0; v < see[u].size(); ++v) {
                if (see[u][v] == 'S' || see[u][v] == 'T' || see[u][v] == 'B')
                    see[u][v] = '.';
            }
        }
        see[id2Pos[i].row][id2Pos[i].col] = 'S';
        see[id2Pos[j].row][id2Pos[j].col] = 'B';
        for (int u = 0; u < see.size(); ++u) {
            for (int v = 0; v < see[u].size(); ++v)
                cout << see[u][v];
            cout << endl;
        }
        cout << endl;
    }

    int dfs(int i, int j) {
        if (i == j) return 0x3f3f3f3f;
        if (vis[i][j]) return 0x3f3f3f3f;
        if (dp[i][j] < 0x3f3f3f3f) return dp[i][j];
        vis[i][j] = 1;
        int ans = 0x3f3f3f3f;
        int dx[] = {0, 1, 0, -1};
        int dy[] = {-1, 0, 1, 0};
        for (int k = 0; k < 4; ++k) {
            Pos nowSPos = id2Pos[i];
            Pos nowBPos = id2Pos[j];
            Pos preSPos = Pos(nowSPos.row + dy[k], nowSPos.col + dx[k]);
            if (!inbound(preSPos)) continue;
//            if (nowSPos == Pos(1, 1) && nowBPos == Pos(1, 2)) {
//                cout << "pre2 " << preSPos << endl;
//            }
            if (nowSPos.row - dy[k] == nowBPos.row && nowSPos.col - dx[k] == nowBPos.col) {
                Pos preBPos = nowBPos;
                ans = min(ans, dfs(pos2ID[preSPos], pos2ID[preBPos])); // not push box
                preBPos = nowSPos;
                ans = min(ans, 1 + dfs(pos2ID[preSPos], pos2ID[preBPos])); // push box
//                if (nowSPos == Pos(1, 1) && nowBPos == Pos(1, 2)) {
//                    cout << "pre " << preSPos << endl;
//                    cout << preSPos << ' ' << preBPos << endl;
//                    cout << dfs(pos2ID[preSPos], pos2ID[preBPos]) << endl;
//                    cout << "ans = " << ans << endl;
//                }
            } else {
                ans = min(ans, dfs(pos2ID[preSPos], pos2ID[nowBPos]));
//                if (nowSPos == Pos(0, 2) && nowBPos == Pos(1, 3) && preSPos == Pos(1, 2)) {
//                    cout << "pre = " << preSPos << ' ' << nowBPos << ' '  << dfs(pos2ID[preSPos], pos2ID[nowBPos]) << endl;
//                    cout << "ck : " << dfs(pos2ID[preSPos], pos2ID[nowBPos]) << endl;
//                    cout << "ans : " << id2Pos[i] << ' ' << id2Pos[j] << ' ' << ans << endl;
//                }
            }
        }
//        cout << "res " << id2Pos[i] << ' ' << id2Pos[j] << ' ' << ans << endl;
        vis[i][j] = 0;
        return dp[i][j] = ans;
    }

    bool updateDP(Pos pre_si, Pos pre_bi, Pos now_si, Pos now_bi, int add) {
        if (dp[pos2ID[pre_si]][pos2ID[pre_bi]] > dp[pos2ID[now_si]][pos2ID[now_bi]] + add) {
            dp[pos2ID[pre_si]][pos2ID[pre_bi]] = dp[pos2ID[now_si]][pos2ID[now_bi]] + add;
            return true;
        }
        return false;
    }

    void bfs(Pos ebi) {
        queue<Pos> que;
        for (int i = 0; i < pos2ID.size(); ++i) {
            if (i == pos2ID[ebi]) continue;
            que.push({i, pos2ID[ebi]});
            dp[i][pos2ID[ebi]] = 0;
        }

        while (que.size()) {
            Pos f = que.front(); que.pop();
            int dx[] = {0, 1, 0, -1};
            int dy[] = {-1, 0, 1, 0};
            Pos now_si = id2Pos[f.row];
            Pos now_bi = id2Pos[f.col];
            for (int d = 0; d < 4; ++d) {
                Pos pre_si(now_si.row - dy[d], now_si.col - dx[d]);
                if (!inbound(pre_si)) continue;
                if (pre_si == now_bi) continue;
                //if (now_si == Pos(2, 3) && now_bi == Pos(3, 3) && pre_si == Pos(1, 3)) cout << "www " << endl;
                if (now_si.row + dy[d] == now_bi.row && now_si.col + dx[d] == now_bi.col) {
                    Pos pre_bi = now_si;
                    if (updateDP(pre_si, pre_bi, now_si, now_bi, 1)) que.push(Pos(pos2ID[pre_si], pos2ID[pre_bi]));
                    pre_bi = now_bi;
                    if (updateDP(pre_si, pre_bi, now_si, now_bi, 0)) que.push(Pos(pos2ID[pre_si], pos2ID[pre_bi]));
                } else {
                    if (now_si == Pos(2, 3) && now_bi == Pos(3, 3) && pre_si == Pos(1, 3)) cout << "w2 " << endl;
                    Pos pre_bi = now_bi;
                    if (updateDP(pre_si, pre_bi, now_si, now_bi, 0)) que.push(Pos(pos2ID[pre_si], pos2ID[pre_bi]));
                }
            }
        }
    }

    int minPushBox(vector<vector<char>>& grid) {
        graph = grid;
        int N = 0;
        Pos s, t, b;
        for (int i = 0; i < grid.size(); ++i) for (int j = 0; j < grid[i].size(); ++j) {
            char u = grid[i][j];
            if (u == 'S') s = Pos(i, j);
            if (u == 'T') t = Pos(i, j);
            if (u == 'B') b = Pos(i, j);
            if (u == '.' || u == 'S' || u == 'T' || u == 'B') {
                N++;
                id2Pos.emplace_back(i, j);
                pos2ID[Pos(i, j)] = id2Pos.size() - 1;
            }
        }
        dp.resize(N);
        for (int i = 0; i < N; ++i) dp[i].resize(N);
        for (int i = 0; i < N; ++i) for (int j = 0; j < N; ++j) dp[i][j] = 0x3f3f3f3f;
        bfs(t);
        int ans = dp[pos2ID[s]][pos2ID[b]];
        for (int i = 0; i < N; ++i) {
            int posEnd = pos2ID[Pos(1, 2)];
            //cout << "ans " << id2Pos[i].row << ' ' << id2Pos[i].col << ' ' << dp[i][posEnd] << endl;
        }
        return ans < 0x3f3f3f3f ? ans : -1;
    }
};

int main() {
    int colNum = 4;
    vector<vector<char>> g;
    string data = "[....]"
                  "[.B..]"
                  "[..S.]"
                  "[.#.T]";

//    data = "[..#....#]"
//                  "[.B.....#]"
//                  "[..S.....]"
//                  "[.#......]"
//                  "[........]"
//                  "[...T....]";
    data = data.replace(data.find("["), 1, "");
    string buffer;
    for (char c : data) {
        if (c == '.' || c == '#' || c == 'S' || c == 'T' || c == 'B')
            buffer += c;
    }
    vector<char> temp;
    for (char c : buffer) {
        temp.push_back(c);
        if (temp.size() == colNum) {
            g.push_back(temp);
            temp.clear();
        }
    }
    for (int i = 0; i < g.size(); ++i) {
        for (int j = 0; j < g[i].size(); ++j)
            cout << g[i][j];
        cout << endl;
    }

    Solution sol;
    cout << sol.minPushBox(g) << endl;

    return 0;
}