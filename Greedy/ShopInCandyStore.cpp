class Solution {
  public:
    vector<int> minMaxCandy(vector<int>& prices, int k) {
        // Code here
        int N=prices.size();
        sort(prices.begin(),prices.end());
        int mini=0;
        int buy=0;
        int free=N-1;
        while(buy<=free){
            mini=mini+prices[buy];
            buy++;
            free=free-k;
        }
        int maxi=0;
        buy=N-1;
        free=0;
        while(buy>=free){
            maxi=maxi+prices[buy];
            buy--;
            free=free+k;
        }
        vector<int>ans;
        ans.push_back(mini);
        ans.push_back(maxi);
        return ans;
    }
};
//tc onlogn and sc is o(n)
