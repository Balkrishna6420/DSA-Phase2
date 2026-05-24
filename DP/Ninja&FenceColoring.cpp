//using recursion
#define MOD 1000000007
#include<vector>
long long int solve(int n){
  long long prev2=0;
  long long prev1=1;
  for(int i=3;i<=n;i++){
    long long int first=prev1%MOD;
    long long int second=prev2%MOD;
    long long int sum=(first+second)%MOD;
    long long int ans=((i-1)*sum)%MOD;
    prev2=prev1;
    prev1=ans;
  }
  return prev1;
}
long long int countDerangements(int n) {
     return solve(n);
}
//using memoisation
#include <bits/stdc++.h> 
#define MOD 1000000007
int add(int a,int b){
    return(a%MOD +b%MOD)%MOD;
}
int mul(int a,int b){
    return ((a%MOD)*1LL*(b%MOD))%MOD;
}
int solve(int n,int k,vector<int>&dp){
    if(n==1){
        return k;
    }
    if(n==2){
        return add(k,mul(k,k-1));
    }
    if(dp[n]!=-1){
        return dp[n];
    }
    dp[n]=add(mul(solve(n-2,k,dp),k-1),mul(solve(n-1,k,dp),k-1));
    return dp[n];
}
int numberOfWays(int n, int k) {
    // Write your code here.
    vector<int>dp(n+1,-1);
    return solve(n,k,dp);
}
//using tabulation
#include <bits/stdc++.h> 
#define MOD 1000000007
int add(int a,int b){
    return(a%MOD +b%MOD)%MOD;
}
int mul(int a,int b){
    return ((a%MOD)*1LL*(b%MOD))%MOD;
}
int solve(int n,int k){
    vector<int>dp(n+1,0);
    dp[1]=k;
    dp[2]=add(k,mul(k,k-1));
    for(int i=3;i<=n;i++){
        dp[i]=add(mul(dp[i-2],k-1),mul(dp[i-1],k-1));
    }
    return dp[n];
    
}
int numberOfWays(int n, int k) {
    // Write your code here.
    return solve(n,k);
}
//using space optimasation 
#include <bits/stdc++.h> 
#define MOD 1000000007
int add(int a,int b){
    return(a%MOD +b%MOD)%MOD;
}
int mul(int a,int b){
    return ((a%MOD)*1LL*(b%MOD))%MOD;
}
int solve(int n,int k){
    int prev2=k;
    int prev1=add(k,mul(k,k-1));
    for(int i=3;i<=n;i++){
        int ans=add(mul(prev2,k-1),mul(prev1,k-1));
        prev2=prev1;
        prev1=ans;
    }
    return prev1;
    
}
int numberOfWays(int n, int k) {
    // Write your code here.
    return solve(n,k);
}
