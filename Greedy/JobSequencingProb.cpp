class Solution {
  public:

    static bool cmp(pair<int,int> a, pair<int,int> b){
        return a.second > b.second;
    }

    int findParent(int node, vector<int>& parent){
        if(parent[node] == node)
            return node;

        return parent[node] = findParent(parent[node], parent);
    }

    vector<int> jobSequencing(vector<int> &deadline, vector<int> &profit) {

        int n = deadline.size();

        vector<pair<int,int>> arr;

        for(int i = 0; i < n; i++){
            arr.push_back({deadline[i], profit[i]});
        }

        sort(arr.begin(), arr.end(), cmp);

        int maxiDeadline = 0;

        for(int i = 0; i < n; i++){
            maxiDeadline = max(maxiDeadline, arr[i].first);
        }

        vector<int> parent(maxiDeadline + 1);

        for(int i = 0; i <= maxiDeadline; i++){
            parent[i] = i;
        }

        int count = 0;
        int maxProfit = 0;

        for(int i = 0; i < n; i++){

            int currDead = arr[i].first;
            int currProfit = arr[i].second;

            int availableSlot = findParent(currDead, parent);

            if(availableSlot > 0){

                count++;
                maxProfit += currProfit;

                parent[availableSlot] =
                    findParent(availableSlot - 1, parent);
            }
        }

        return {count, maxProfit};
    }
};