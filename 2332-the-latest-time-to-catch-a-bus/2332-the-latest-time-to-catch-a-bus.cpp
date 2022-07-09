class Solution {
public:
    int latestTimeCatchTheBus(vector<int>& buses, vector<int>& ps, int capacity) {
        sort(buses.begin(),buses.end());
        sort(ps.begin(),ps.end());
        unordered_map<int,int>mp;
        for(auto x:ps){
            mp[x]=1;
        }
        int j=0,ans=INT_MIN;
        for(int i=0;i<buses.size();i++){
            int val=buses[i];
            int my=0;
            if(mp.count(ps[j]-1)==0){
                my=ps[j]-1;
            }
            int cnt=0;
            while(j<ps.size()&&cnt<capacity&&ps[j]<=val){
                if(mp.count(ps[j]-1)==0){
                my=ps[j]-1;
            }
                cnt++;
                j++;
            }
            // cout<<cnt<<" "<<j<<"\n";
            if(j<ps.size()&&mp.count(ps[j]-1)==0&&(ps[j]-1<=val)&&cnt<capacity){
                my=ps[j]-1;
            }
            if(cnt<capacity&&mp.count(val)==0){
            my=val;
            }
            ans=max(ans,my);
        }
        return ans;
    }
};