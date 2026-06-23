//here we have to return the meetings possible not the count .
class Solution {
public:
    static bool cmp(pair<pair<int,int>,int> a,
                    pair<pair<int,int>,int> b) {
        if(a.first.second == b.first.second)
            return a.second < b.second;
        return a.first.second < b.first.second;
    }

    vector<int> maxMeetings(vector<int> &s, vector<int> &f) {

        int n = s.size();

        vector<pair<pair<int,int>,int>> v;

        for(int i = 0; i < n; i++) {
            v.push_back({{s[i], f[i]}, i + 1});
        }

        sort(v.begin(), v.end(), cmp);

        vector<int> ans;

        ans.push_back(v[0].second);
        int ansEnd = v[0].first.second;

        for(int i = 1; i < n; i++) {
            if(v[i].first.first > ansEnd) {
                ans.push_back(v[i].second);
                ansEnd = v[i].first.second;
            }
        }

        sort(ans.begin(), ans.end()); 

        return ans;
    }
}; 