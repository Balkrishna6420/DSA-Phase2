class Solution {
  public:
  bool solve(int index,vector<int>&arr,int n,int target){
      //base case
      if(index>=n){
          return false;
      }
      if(target<0){
          return false;
      }
      if(target==0){
          return true;
      }
      bool include=solve(index+1,arr,n,target-arr[index]);
      bool exclude=solve(index+1,arr,n,target-0);
      return include or exclude;
      
      
  }
    bool equalPartition(vector<int>& arr) {
        // code here
        int n=arr.size();
        int total=0;
        for(int i=0;i<n;i++){
            total=total+arr[i];
        }
        if(total & 1){//if total is a odd number ,return 0
            return 0;
        }
        int target=total/2;
        return solve(0,arr,n,target);
    }
};
//using dp
class Solution {
  public:
  bool solve(int index,vector<int>&arr,int n,int target,vector<vector<int>>&dp){
      //base case
      if(index>=n){
          return false;
      }
      if(target<0){
          return false;
      }
      if(target==0){
          return true;
      }
      if(dp[index][target]!=-1){
          return dp[index][target];
      }
      bool include=solve(index+1,arr,n,target-arr[index],dp);
      bool exclude=solve(index+1,arr,n,target-0,dp);
      return dp[index][target]=include or exclude;
      
      
  }
    bool equalPartition(vector<int>& arr) {
        // code here
        int n=arr.size();
        int total=0;
        for(int i=0;i<n;i++){
            total=total+arr[i];
        }
        if(total & 1){//if total is a odd number ,return 0
            return 0;
        }
        int target=total/2;
        vector<vector<int>>dp(n,vector<int>(target+1,-1));
        return solve(0,arr,n,target,dp);
    }
};
//using tabulation
class Solution {
  public:
  bool solve(int n,vector<int>&arr,int total){
      vector<vector<int>>dp(n+1,vector<int>(total+1,0));
      for(int i=0;i<=n;i++){
          dp[i][0]=1;
      }
      for(int index=n-1;index>=0;index--){
          for(int target=0;target<=total/2;target++){
              bool include=0;
              if(target-arr[index]>=0)
                 include=dp[index+1][target-arr[index]];
              bool exclude=dp[index+1][target-0];
              dp[index][target]=include or exclude;
          }
      }
      return dp[0][total/2];
  }
    bool equalPartition(vector<int>& arr) {
        // code here
        int n=arr.size();
        int total=0;
        for(int i=0;i<n;i++){
            total=total+arr[i];
        }
        if(total & 1){//if total is a odd number ,return 0
            return 0;
        }
        int target=total/2;
        return solve(n,arr,total);
    }
};
//space optimised
class Solution {
  public:
  bool solve(int n,vector<int>&arr,int total){
      vector<int>curr(total/2+1,0);
      vector<int>next(total/2+1,0);
      curr[0]=1;
      next[0]=1;
      for(int index=n-1;index>=0;index--){
          for(int target=0;target<=total/2;target++){
              bool include=0;
              if(target-arr[index]>=0)
                 include=next[target-arr[index]];
              bool exclude=next[target-0];
              curr[target]=include or exclude;
          }
          next=curr;
      }
      return next[total/2];
  }
    bool equalPartition(vector<int>& arr) {
        // code here
        int n=arr.size();
        int total=0;
        for(int i=0;i<n;i++){
            total=total+arr[i];
        }
        if(total & 1){//if total is a odd number ,return 0
            return 0;
        }
        int target=total/2;
        return solve(n,arr,total);
    }
};