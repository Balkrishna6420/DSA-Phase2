class Solution {
  public:
  int solve(vector<int>& arr,int n,int curr,int prev){
    //base case
    if(curr==n){
        return 0;
    }
    //include
    int take=0;
    if(prev==-1||arr[curr]>arr[prev]){
        take=1+solve(arr,n,curr+1,curr);
    }
    //exclude
    int notTake=0+solve(arr,n,curr+1,prev);
    return max(take,notTake);
}
    int lis(vector<int>& arr) {
        // code here
        int n=arr.size();
        return solve(arr,n,0,-1);
        
    }
};
//using memoisation
class Solution {
  public:
  int solve(vector<int>& arr,int n,int curr,int prev,vector<vector<int>>&dp){
    //base case
    if(curr==n){
        return 0;
    }
    if(dp[curr][prev+1]!=-1){
        return dp[curr][prev+1];
    }
    //include
    int take=0;
    if(prev==-1||arr[curr]>arr[prev]){
        take=1+solve(arr,n,curr+1,curr,dp);
    }
    //exclude
    int notTake=0+solve(arr,n,curr+1,prev,dp);
    return dp[curr][prev+1]= max(take,notTake);
}
    int lis(vector<int>& arr) {
        // code here
        int n=arr.size();
        vector<vector<int>>dp(n,vector<int>(n+1,-1));
        return solve(arr,n,0,-1,dp);
        
    }
};
//using tabulation
class Solution {
  public:
  int solve(vector<int>& arr,int n){
      vector<vector<int>>dp(n+1,vector<int>(n+1,0));
      for(int curr=n-1;curr>=0;curr--){
          for(int prev=curr-1;prev>=-1;prev--){
              //include
              int take=0;
              if(prev==-1||arr[curr]>arr[prev]){
                  take=1+dp[curr+1][curr+1];
              }
              //exclude
              int notTake=0+dp[curr+1][prev+1];
              dp[curr][prev+1]= max(take,notTake);
          }
      }
      return dp[0][-1+1];
    
    
    
    
}
    int lis(vector<int>& arr) {
        // code here
        int n=arr.size();
        return solve(arr,n);
        
    }
};
//using space optimisation
class Solution {
  public:
  int solve(vector<int>& arr,int n){
      vector<int>currRow(n+1,0);
      vector<int>nextRow(n+1,0);
      for(int curr=n-1;curr>=0;curr--){
          for(int prev=curr-1;prev>=-1;prev--){
              //include
              int take=0;
              if(prev==-1||arr[curr]>arr[prev]){
                  take=1+nextRow[curr+1];
              }
              //exclude
              int notTake=0+nextRow[prev+1];
              currRow[prev+1]= max(take,notTake);
          }
          nextRow=currRow;
      }
      return nextRow[0];
    
    
    
    
}
    int lis(vector<int>& arr) {
        // code here
        int n=arr.size();
        return solve(arr,n);
        
    }
};
//tc is o(n2) sc is o(n);
//using tc as o(nlog n) dp using binary search and sc is o(n)
class Solution {
  public:
  int solveOptimal(vector<int>& arr,int n){
      if(n==0){
          return 0;
      }
      vector<int>ans;
      ans.push_back(arr[0]);
      for(int i=1;i<n;i++){
          if(arr[i]>ans.back()){
              ans.push_back(arr[i]);
          }else{
              //find index of greater elementin ans
              int index=lower_bound(ans.begin(),ans.end(),arr[i])-ans.begin();
              ans[index]=arr[i];
          }
      }
      return ans.size();
  }
    int lis(vector<int>& arr) {
        // code here
        int n=arr.size();
        return solveOptimal(arr,n);
        
    }
};