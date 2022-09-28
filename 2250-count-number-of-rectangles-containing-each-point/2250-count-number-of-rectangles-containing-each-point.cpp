class Solution {
public:
    vector<int> countRectangles(vector<vector<int>>& rec, vector<vector<int>>& pts) {
       sort(rec.begin(),rec.end());
       vector<pair<vector<int>,int>>vec;
       for(int i=0;i<pts.size();i++){
           vec.push_back({pts[i],i});
       }
       sort(vec.begin(),vec.end(),[&](pair<vector<int>,int>&a,pair<vector<int>,int>&b){
          return a.first[0]>b.first[0]; 
       });
        vector<int>ans(vec.size(),0);
        map<int,int>mp;
        set<int>st;
        int j=rec.size()-1;
        // cout<<vec.size()<<" ";
        for(int i=0;i<vec.size();i++){
            while(j>=0&&rec[j][0]>=vec[i].first[0]){
                mp[rec[j][1]]++;
                st.insert(rec[j][1]);
                j--;
            }
            int x=vec[i].first[1];
            if(st.size()==0){
                continue;
            }
            if(x<=(*st.rbegin())){
           int v=*st.lower_bound(x);
            // cout<<x<<" "<<st.size()<<" "<<v<<"\n";
            int cnt=0;
             // cout<<v<<" ";
            for(int k=v;k<=100;k++){
                cnt+=mp[k];
            }
            ans[vec[i].second]=cnt;
            }
            
        
            
        }
        return ans;
    }
};