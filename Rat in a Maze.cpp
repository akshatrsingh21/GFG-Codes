#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<string> ans;
    int n;
    vector<vector<int>> vis;
    vector<int> di{1,0,0,-1};
    vector<int> dj{0,-1,1,0};
    string dir = "DLRU";

    void dfs(int i, int j, vector<vector<int>>& m, string &path) {
        if (i == n - 1 && j == n - 1) {
            ans.push_back(path);
            return;
        }
        for (int k = 0; k < 4; ++k) {
            int ni = i + di[k];
            int nj = j + dj[k];
            if (ni >= 0 && ni < n && nj >= 0 && nj < n && !vis[ni][nj] && m[ni][nj] == 1) {
                vis[ni][nj] = 1;
                path.push_back(dir[k]);
                dfs(ni, nj, m, path);
                path.pop_back();
                vis[ni][nj] = 0;
            }
        }
    }

    // GFG driver expects this signature: vector<string> ratInMaze(vector<vector<int>>& mat)
    vector<string> ratInMaze(vector<vector<int>>& m) {
        ans.clear();
        if (m.empty()) return ans;
        n = m.size();
        vis.assign(n, vector<int>(n, 0));
        if (m[0][0] == 0) return ans; // start is blocked

        string path = "";
        vis[0][0] = 1;
        dfs(0, 0, m, path);

        sort(ans.begin(), ans.end());
        return ans;
    }
};
