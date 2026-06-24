class Solution {
  public:
  
    static bool cmp(pair<double, pair<int,int>> a,
                    pair<double, pair<int,int>> b) {
        return a.first > b.first;
    }

    double fractionalKnapsack(vector<int>& val, vector<int>& wt, int capacity) {
        
        int n = val.size();

        vector<pair<double, pair<int,int>>> v;

        for(int i = 0; i < n; i++) {
            double perUnitValue = (1.0 * val[i]) / wt[i];

            pair<double, pair<int,int>> p =
                make_pair(perUnitValue, make_pair(val[i], wt[i]));

            v.push_back(p);
        }

        sort(v.begin(), v.end(), cmp);

        double totalValue = 0.0;

        for(int i = 0; i < n && capacity > 0; i++) {

            if(v[i].second.second > capacity) {
                // take fraction
                totalValue += capacity * v[i].first;
                capacity = 0;
            }
            else {
                totalValue += v[i].second.first;
                capacity -= v[i].second.second;
            }
        }

        return totalValue;
    }
};
//sc ;o(n) t cis o(nlogn)