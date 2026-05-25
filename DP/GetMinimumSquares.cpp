//we have to get total no minimum squares  possibilities to get square
//using recursion
class Solution {
  public:
  int solve(int n){
      //base case
      if(n==0)
        return 0;
      int ans=n;
      for(int i=1;i*i<=n;i++){
          int temp=i*i;
          ans=min(ans,1+solve(n-temp));
      }
      return ans;
  }
    int minSquares(int n) {
        // Code here
        return solve(n);
    }
};
//using memoisation dp

class Solution {
  public:
  int solve(int n,vector<int>&dp){
      //base case
      if(n==0)
        return 0;
      if
      (dp[n]!=-1)
        return dp[n];
      int ans=n;
      for(int i=1;i*i<=n;i++){
          int temp=i*i;
          ans=min(ans,1+solve(n-temp,dp));
      }
      dp[n]=ans;
      return dp[n];
  }
    int minSquares(int n) {
        // Code here
        vector<int>dp(n+1,-1);
        return solve(n,dp);
    }
};
//using tabulation
class Solution {
  public:
  int solve(int n){
      vector<int>dp(n+1,INT_MAX);
      dp[0]=0;
      for(int i=1;i<=n;i++){
          for(int j=1;j*j<=n;j++){
              int temp=j*j;
              if(i-temp>=0)
              dp[i]=min(dp[i],1+dp[i-temp]);
          }
      }
      return dp[n];
  }
    int minSquares(int n) {
        // Code here
        return solve(n);
    }
};