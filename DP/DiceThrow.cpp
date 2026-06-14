class Solution {
  public:
  int solve(int dice,int faces,int target){
      //base case
      if(target<0){
          return 0;
      }
      if(dice==0 && target!=0){
          return 0;
      }
      if(target==0 && dice!=0){
          return 0;
      }
      if(dice==0 && target==0){
          return 1;
      }
      int ans=0;
      for(int i=1;i<=faces;i++){
          ans=ans+solve(dice-1,faces,target-i);
      }
      return ans;
  }
    int noOfWays(int m, int n, int x) {
        // code here
        return solve(n,m,x);
    }
};
//using dp
class Solution {
  public:
  int solve(int dice,int faces,int target,vector<vector<int>>&dp){
      //base case
      if(target<0){
          return 0;
      }
      if(dice==0 && target!=0){
          return 0;
      }
      if(target==0 && dice!=0){
          return 0;
      }
      if(dice==0 && target==0){
          return 1;
      }
      if(dp[dice][target]!=-1){
          return dp[dice][target];
      }
      int ans=0;
      for(int i=1;i<=faces;i++){
          ans=ans+solve(dice-1,faces,target-i,dp);
      }
      return dp[dice][target]=ans;
  }
    int noOfWays(int m, int n, int x) {
        // code here
        vector<vector<int>>dp(n+1,vector<int>(x+1,-1));
        return solve(n,m,x,dp);
    }
};
//using bottom up approach 
class Solution {
  public:
  int solve(int d,int f,int t){
      vector<vector<int>>dp(d+1,vector<int>(t+1,0));
      dp[0][0]=1;
      for(int dice=1;dice<=d;dice++){
          for(int target=1;target<=t;target++){
              int ans=0;
              for(int i=1;i<=f;i++){
                  if(target-i>=0){
                      ans=ans+dp[dice-1][target-i];
                  }
              }
              dp[dice][target]=ans;
          }
      }
      return dp[d][t];
  }
    int noOfWays(int m, int n, int x) {
        // code here
        return solve(n,m,x);
    }
};
//space optiisation methid 
class Solution {
  public:
  int solve(int d,int f,int t){
      vector<int>prev(t+1,0);
      vector<int>curr(t+1,0);
     
      prev[0]=1;
      for(int dice=1;dice<=d;dice++){
          for(int target=1;target<=t;target++){
              int ans=0;
              for(int i=1;i<=f;i++){
                  if(target-i>=0){
                      ans=ans+prev[target-i];
                  }
              }
              curr[target]=ans;
          }
          prev=curr;
      }
      return prev[t];
  }
    int noOfWays(int m, int n, int x) {
        // code here
        return solve(n,m,x);
    }
};
//sc is o(t)