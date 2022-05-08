class Solution {
public:
    int search(vector<pair<int,int>>&vec,int diff){
        int i=0,j=vec.size()-1;
        int ans=-1;
        while(i<=j){
            int mid=(i+j)>>1;
            if(vec[mid].first>diff){
                j=mid-1;
            }
            else{
                ans=mid;
                i=mid+1;
            }
        }
        return ans;
    }
    int maxProfitAssignment(vector<int>& difficulty, vector<int>& profit, vector<int>& worker) {
        vector<pair<int,int>>vec;
        for(int i=0;i<profit.size();i++){
            vec.push_back({difficulty[i],profit[i]});
        }
        sort(vec.begin(),vec.end());
        int mx=vec[0].second;
        for(int i=1;i<vec.size();i++){
            mx=max(mx,vec[i].second);
            vec[i].second=mx;
        }
        
        int ans=0;
        for(int i=0;i<worker.size();i++){
            int a=search(vec,worker[i]);
            // cout<<i<<" "<<a<<"\n";
             ans+=(a==-1?0:vec[a].second);
        }
        return ans;
    }
};