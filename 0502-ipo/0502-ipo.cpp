class Solution {
public:
    int findMaximizedCapital(int k, int w, vector<int>& p, vector<int>& c) {
        vector<pair<int,int>>vec;
        for(int i=0;i<p.size();i++){
            vec.push_back({p[i],c[i]});
        }
        sort(vec.begin(),vec.end(),[&](pair<int,int>&a,pair<int,int>&b){
            return a.second<b.second;
        });
        int i=0;
        priority_queue<int>pq;
        while(k--){
            while(i<vec.size()&&vec[i].second<=w){
                pq.push(vec[i].first);
                i++;
            }
            if(pq.size()>0){
            w+=pq.top();
            pq.pop();
            }
        }
        return w;
    }
};