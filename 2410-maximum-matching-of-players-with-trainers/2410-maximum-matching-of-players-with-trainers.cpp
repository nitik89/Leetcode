class Solution {
public:
    int matchPlayersAndTrainers(vector<int>& pl, vector<int>& tr) {
        priority_queue<pair<int,int>>pq;
        sort(pl.begin(),pl.end());
        // unordered_map<int,int>mp;
        int i=0;
        for(auto x:tr){
            pq.push({x,i});
            i++;
        }
        int cnt=0;
        for(int i=pl.size()-1;i>=0;i--){
            if(!pq.empty()&&pq.top().first>=pl[i]){
                cnt++;
                pq.pop();
            }
        }
        return cnt;
        
    }
};