//in this question transaction is not limited to atmost 2 times only here there is k no of times u can do transaction

class Solution {
public:
int solve(int index,int buy,vector<int>&prices,int k){
    //base case
    if(index==prices.size()){
        return 0;
    }
    if(k==0){
        return 0;
    }
    int profit=0;
    if(buy){
        int buyKaro=-prices[index]+solve(index+1,0,prices,k);
        int skipKaro=0+solve(index+1,1,prices,k);
        profit=max(buyKaro,skipKaro);
    }else{
        int sellKaro=prices[index]+solve(index+1,1,prices,k-1);
        int skipKaro=0+solve(index+1,0,prices,k);
        profit=max(sellKaro,skipKaro);
    }
    return profit;
}
    int maxProfit(int k, vector<int>& prices) {
        return solve(0,1,prices,k);
    }
};
//memoisation
class Solution {
public:
int solve(int index,int buy,vector<int>&prices,int k,vector<vector<vector<int>>>&dp){
    //base case
    if(index==prices.size()){
        return 0;
    }
    if(k==0){
        return 0;
    }
    if(dp[index][buy][k]!=-1){
        return dp[index][buy][k];
    }
    int profit=0;
    if(buy){
        int buyKaro=-prices[index]+solve(index+1,0,prices,k,dp);
        int skipKaro=0+solve(index+1,1,prices,k,dp);
        profit=max(buyKaro,skipKaro);
    }else{
        int sellKaro=prices[index]+solve(index+1,1,prices,k-1,dp);
        int skipKaro=0+solve(index+1,0,prices,k,dp);
        profit=max(sellKaro,skipKaro);
    }
    return dp[index][buy][k]=profit;
}
    int maxProfit(int k, vector<int>& prices) {
        int n=prices.size();
        vector<vector<vector<int>>>dp(n,vector<vector<int>>(2,vector<int>(k+1,-1)));
        return solve(0,1,prices,k,dp);
    }
};
//using tabulation
class Solution {
public:
int solve(int k,vector<int>&prices){
    int n=prices.size();
    vector<vector<vector<int>>>dp(n+1,vector<vector<int>>(2,vector<int>(k+1,0)));

    for(int index=n-1;index>=0;index--){
        for(int buy=0;buy<=1;buy++){
            for(int limit=1;limit<=k;limit++){
                int profit=0;
                if(buy){
                    int buyKaro=-prices[index]+dp[index+1][0][limit];
                    int skipKaro=0+dp[index+1][1][limit];
                    profit=max(buyKaro,skipKaro);
                }else{
                    int sellKaro=prices[index]+dp[index+1][1][limit-1];
                    int skipKaro=0+dp[index+1][0][limit];
                    profit=max(sellKaro,skipKaro);
                }
                dp[index][buy][limit]=profit;
            }
            
        }
    }
    return dp[0][1][k];
}
    int maxProfit(int k, vector<int>& prices) {
        return solve(k,prices);
    }
};
//so
class Solution {
public:
int solve(vector<int>&prices,int k){
    int n=prices.size();
    vector<vector<int>>curr(2,vector<int>(k+1,0));
    vector<vector<int>>next(2,vector<int>(k+1,0));

    for(int index=n-1;index>=0;index--){
        for(int buy=0;buy<=1;buy++){
            for(int limit=1;limit<=k;limit++){
                int profit=0;
                if(buy){
                    int buyKaro=-prices[index]+next[0][limit];
                    int skipKaro=0+next[1][limit];
                    profit=max(buyKaro,skipKaro);
                }else{
                    int sellKaro=prices[index]+next[1][limit-1];
                    int skipKaro=0+next[0][limit];
                    profit=max(sellKaro,skipKaro);
                }
                curr[buy][limit]=profit;
            }  
        }
        next=curr;
    }
    return next[1][k];
}

    int maxProfit(int k, vector<int>& prices) {
        return solve(prices,k);
    }
};
