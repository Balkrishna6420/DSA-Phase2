//unlimited transacation but after each transactio pay certain fee

class Solution {
public:
int solve(int index,int buy,vector<int>&prices,int fee){
    //base case
    if(index==prices.size()){
        return 0;
    }
    int profit=0;
    if(buy){
        int buyKaro=-prices[index]+solve(index+1,0,prices,fee);
        int skipKaro=0+solve(index+1,1,prices,fee);
        profit=max(buyKaro,skipKaro);
    }else{
        int sellKaro=prices[index]-fee+solve(index+1,1,prices,fee);
        int skipKaro=0+solve(index+1,0,prices,fee);
        profit=max(sellKaro,skipKaro);
    }
    return profit;
}
    int maxProfit(vector<int>& prices, int fee) {
        return solve(0,1,prices,fee);
    }
};
//using memoisation
class Solution {
public:
    int solve(int index, int buy,
              vector<int>& prices, int fee,
              vector<vector<int>>& dp) {

        if(index == prices.size())
            return 0;

        if(dp[index][buy] != -1)
            return dp[index][buy];

        int profit;

        if(buy) {
            profit = max(
                -prices[index] +
                solve(index+1,0,prices,fee,dp),

                solve(index+1,1,prices,fee,dp)
            );
        }
        else {
            profit = max(
                prices[index] - fee +
                solve(index+1,1,prices,fee,dp),

                solve(index+1,0,prices,fee,dp)
            );
        }

        return dp[index][buy] = profit;
    }

    int maxProfit(vector<int>& prices, int fee) {
        int n = prices.size();

        vector<vector<int>> dp(
            n, vector<int>(2, -1)
        );

        return solve(0,1,prices,fee,dp);
    }
};
//using tabulation
class Solution {
public:
    int solve(vector<int>& prices, int fee) {
        int n = prices.size();

        vector<vector<int>> dp(n + 1, vector<int>(2, 0));

        for(int index = n - 1; index >= 0; index--) {
            for(int buy = 0; buy <= 1; buy++) {

                int profit = 0;

                if(buy) {
                    int buyKaro = -prices[index] + dp[index + 1][0];
                    int skipKaro = dp[index + 1][1];

                    profit = max(buyKaro, skipKaro);
                }
                else {
                    int sellKaro = prices[index] + dp[index + 1][1] - fee;
                    int skipKaro = dp[index + 1][0];

                    profit = max(sellKaro, skipKaro);
                }

                dp[index][buy] = profit;
            }
        }

        return dp[0][1];
    }

    int maxProfit(vector<int>& prices, int fee) {
        return solve(prices, fee);
    }
};
//so
class Solution {
public:
    int solve(vector<int>&prices,int fee){
    int n=prices.size();
    vector<int>curr(2,0);
    vector<int>next(2,0);

    for(int index=n-1;index>=0;index--){
        for(int buy=0;buy<=1;buy++){
            
                int profit=0;
                if(buy){
                    int buyKaro=-prices[index]+next[0];
                    int skipKaro=0+next[1];
                    profit=max(buyKaro,skipKaro);
                }else{
                    int sellKaro=prices[index]+next[1]-fee;
                    int skipKaro=0+next[0];
                    profit=max(sellKaro,skipKaro);
                }
                curr[buy]=profit;
        }
        next=curr;
    }
    return next[1];
}


    int maxProfit(vector<int>& prices, int fee) {
        return solve(prices, fee);
    }
};