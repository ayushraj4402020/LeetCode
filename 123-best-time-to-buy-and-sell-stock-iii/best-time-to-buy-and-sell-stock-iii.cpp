class Solution {
public:
    int t[100001][5][2];
    int solve(vector<int>& prices, int i, int rem, bool flag) {
        if (rem <= 0 || i >= prices.size()) {
            return 0;
        }
        if (t[i][rem][flag] != -1) {  
            return t[i][rem][flag];
        }
        // skip
        int skip = solve(prices, i + 1, rem, flag);
        int take = 0;


        // buy or sell
        if (flag) {  // can buy
            take = -prices[i] + solve(prices, i + 1, rem, 0);
        } else {  // must sell
            take = prices[i] + solve(prices, i + 1, rem - 1, 1);
        }
        return t[i][rem][flag] = max(skip, take);  
    }

    int maxProfit(vector<int>& prices) {
        memset(t, -1, sizeof(t));
        return solve(prices, 0, 2, 1); 
    }
};
