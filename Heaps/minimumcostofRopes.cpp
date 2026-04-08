class Solution {
  public:
    int minCost(vector<int>& arr) {
        // code here
        //create a min heap
        priority_queue<int,vector<int>,greater<int>>pq;
        int n=arr.size();
        for(int i=0;i<n;i++){
            pq.push(arr[i]);
        }
        int cost=0;
        while(pq.size()>1){
            int a=pq.top();
            pq.pop();
            int b=pq.top();
            pq.pop();
            int sum=a+b;
            cost=cost+sum;
            pq.push(sum);
        }
        return cost;
    }
};