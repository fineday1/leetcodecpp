class Solution {
public:
    void dfs(vector<vector<char>>& grid, size_t i, size_t j) {
        if (i < 0 || i >= grid.size() || j < 0 || j >= grid[0].size() || grid[i][j] != '1') {
            return;
        }
        grid[i][j] = 'S';
        dfs(grid, i + 1, j);    // vector<pair<int, int>> d = {{0,1},{1,0},{0,-1},{-1,)}};
        dfs(grid, i - 1, j);    //
        dfs(grid, i, j + 1);    // for (auto [dx, dy] : d) dfs(grid, i + dx, j + dy);
        dfs(grid, i, j - 1);
    }

    int numIslands(vector<vector<char>>& grid) {
        if (grid.empty()) return 0;

        size_t count = 0;

        for (size_t i = 0; i < grid.size(); i++) {
            for (size_t j = 0; j < grid[0].size(); j++) {
                if (grid[i][j] == '1') {
                    count++;
                    dfs(grid, i, j);
                }
            }
        }
        return count;
    }
};
