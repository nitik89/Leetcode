typedef pair<long long,int> pp;
class Solution {
public:
    int mostBooked(int n, vector<vector<int>>& mt) {
       priority_queue<int,vector<int>,greater<int>>pq;
       for(int i=0;i<n;i++){
           pq.push(i);
       }
        sort(mt.begin(),mt.end());
        unordered_map<long long,int>mp;
        long long curr=0;
        priority_queue<pp,vector<pp>,greater<pp>>temp;
        for(auto x:mt){
            int s=x[0],e=x[1];
            while(!temp.empty()&&temp.top().first<=s){
                long long x=temp.top().second;
                pq.push(x);
                temp.pop();
                
            }
            if(pq.size()==0){
                curr=temp.top().first;
                long long v=temp.top().second;
                // cout<<curr<<" "<<v<<"\n";
                curr+=(e-s);
                
                temp.pop();
                 mp[v]++;
                temp.push({curr,v});
            }
            else{
                long long v=pq.top();
                mp[v]++;
                
                
                pq.pop();
                temp.push({e,v});
                
                
            }
        }
        int ans=0,r=-1;
        for(auto x:mp){
            // cout<<x.first<<" "<<x.second<<"\n";
            if(x.second>ans){
                r=x.first;
                ans=x.second;
            }
            else if(x.second==ans){
                if(x.first<r){
                    r=x.first;
                }
            }
        }
        return r;
        
        
    }
};



























