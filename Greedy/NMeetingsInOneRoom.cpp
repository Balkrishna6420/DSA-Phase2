//Activity selection problem
class Solution {
  public:
  static bool cmp(pair<int,int>a,pair<int,int>b){
      return a.second<b.second;
  }
    int activitySelection(vector<int> &start, vector<int> &finish) {
        // code here
        int n=start.size();
        vector<pair<int,int>>v;
        for(int i=0;i<n;i++){
            pair<int,int>p=make_pair(start[i],finish[i]);
            v.push_back(p);
        }
        sort(v.begin(),v.end(),cmp);
        int count=1;
        int ansEnd=v[0].second;
        for(int i=1;i<n;i++){
            if(v[i].first>ansEnd){
                count++;
                ansEnd=v[i].second;
            }
        }
        return count;
    }
};
//tc is n+nlogn+n=nlogn
//n is for loop and nlogn is for sort
//sc is o(n) by using vector pair 