//top down +memoisation approach
#include<iostream>
#include<vector>
using namespace std;

int fib(int n, vector<int>& dp) {

    // base case
    if(n <= 1) {
        return n;
    }

    if(dp[n] != -1) {
        return dp[n];
    }

    dp[n] = fib(n-1, dp) + fib(n-2, dp);

    return dp[n];
}

int main() {

    int n;
    cin >> n;

    vector<int> dp(n+1, -1);

    cout << fib(n, dp) << endl;

    return 0;
}
//tc is o(n) sc is o(n)

//Tabulation approach
#include<iostream>
#include<vector>
using namespace std;
int main(){
    int n;
    cin>>n;
    //step 1
    vector<int>dp(n+1);
    //step 2
    dp[1]=1;
    dp[0]=0;
    //step 3
    for(int i=2;i<=n;i++){
        dp[i]=dp[i-1]+dp[i-2];
    }
    cout<<dp[n]<<endl;
}
//tc is o(n) sc is o(n)
//space optimisation
#include<iostream>
#include<vector>
using namespace std;
int main(){
    int n;
    cin>>n;
    int prev1=1;
    int prev2=0;
    if(n==0){
        return prev2;
    }
    for(int i=2;i<=n;i++){
        int curr=prev1+prev2;
        //shift logic
        prev2=prev1;
        prev1=curr;
    }
    cout<<prev1<<endl;
    return 0;
}//here sc is o(1)and time is o(n)