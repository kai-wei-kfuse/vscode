#include<bits/stdc++.h>

using namespace std;

vector<pair<int, int>> moves = {{0, 1}, {1, 0}, {1, 1}, {2, 0}, {0, 2}}; // 船移动的五种方案

bool is_safe(int m, int c) { // 判断是否符合安全条件
    return (m >= c || m == 0) && (3 - m >= 3 - c || 3 - m == 0);
}

bool dfs(vector<pair<int, int>>& path, int m, int c, int b) { // 深度优先搜索
    if (m == 0 && c == 0 && b == 1) { // 所有人都移动到终点岸边
        for (auto move : path) {
            cout << move.first << " " << move.second << endl;
        }
        return true;
    }

    for (auto move : moves) { // 尝试每一种移动方案
        int nm = m - move.first * (2 * b - 1); // 新的传教士数量
        int nc = c - move.second * (2 * b - 1); // 新的野人数量
        int nb = 1 - b; // 新的船的位置

        if (nm >= 0 && nm <= 3 && nc >= 0 && nc <= 3 && is_safe(nm, nc)) { // 如果移动后的状态符合安全条件
            path.push_back({move.first, move.second});
            if (dfs(path, nm, nc, nb)) { // 继续深度优先搜索
                return true;
            }
            path.pop_back();
        }
    }

    return false;
}

int main() {
    vector<pair<int, int>> path;
    dfs(path, 3, 3, 0);
    return 0;
}
