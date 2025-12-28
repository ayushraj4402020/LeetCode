class Solution {
public:
    int countNegatives(vector<vector<int>>& grid) {
    int m = grid.size();
    int n = grid[0].size();
    int r = m - 1, c = 0, cnt = 0;

    while (r >= 0 && c < n) {
        if (grid[r][c] < 0) {
            cnt += n - c;   
            --r;          
        } else {
            ++c;           
        }
    }

    return cnt;
}
};