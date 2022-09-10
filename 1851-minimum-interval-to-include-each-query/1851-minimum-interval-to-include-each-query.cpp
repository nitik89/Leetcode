typedef pair<int,int> p;
class Solution {
public:
    struct cmp {
    bool operator()(p const& p1, p const& p2)
    {
        // return "true" if "p1" is ordered
        // before "p2", for example:
        return p1.second-p1.first > p2.second-p2.first;
    }
};
    vector<int> minInterval(vector<vector<int>>& in, vector<int>& q) {
        map<int,vector<int>>mp;
        for(int i=0;i<q.size();i++){
            mp[q[i]].push_back(i);
        }
        unordered_map<int,int>ans;
        int i=0;
        // sort(q.begin(),q.end());
        sort(in.begin(),in.end());
        priority_queue<p,vector<p>,cmp>pq;
        for(auto x:mp){
            int v=x.first;
            // cout<<v<<" ";
            while(i<in.size()&&v>in[i][1]){
                i++;
            }
            while(i<in.size()&&v>=in[i][0]){
                pq.push({in[i][0],in[i][1]});
                i++;
            }
            // cout<<i<<" ";
            while(!pq.empty()&&(v>pq.top().second)){
                pq.pop();
            }
            // cout<<pq.top().first<<" "<<pq.top().second<<"\n";
            if(pq.empty()){
                ans[v]=-1;
            }
            else{
                int a=pq.top().first;
                int b=pq.top().second;
                // cout<<a<<" "<<b<<"\n";
                ans[v]=(b-a+1);
            }

           //out of range ko nikalo
        }
        vector<int>res(q.size());
        for(auto x:mp){
            int v=x.first;
            for(auto y:x.second){
                res[y]=ans[v];
            }
        }
        return res;
        
    }
};