class Solution
{
    public:
        vector<int> par;
    vector<int> rank;
    int find(int x)
    {
        if (par[x] == x)
        {
            return x;
        }
        int y = find(par[x]);
        par[x] = y;
        return y;
    }
    void _union(int x, int y)
    {
        int x1 = find(x);
        int x2 = find(y);
        if (x1 != x2)
        {
            par[x1]=x2;
        }
        else
        {
            return;
        }
    }
    vector<int> findAllPeople(int n, vector<vector < int>> &met, int f) {
        par.resize(n);
        rank.resize(n);
        for(int i=0;i<n;i++){
            par[i]=i;
            rank[i]=1;
        }
        map<int,vector<pair<int,int>>>mp;
        int time=100001;
        for(auto x:met){
            mp[x[2]].push_back({x[0],x[1]});
        }
        for(auto x:mp){
            for(auto &[a,b]:x.second){
                if(a==f||a==0||b==0||b==f){
                    time=x.first;
                    break;
                }
            }
            if(time!=100001){
                break;
            }
        }
        _union(f,0);
       
        int q=find(f);
        int w=find(0);
        unordered_set<int>st;
        st.insert(0);
        st.insert(f);
        for(auto x:mp){
            if(x.first>=time){
            for(auto &[a,b]:x.second){
                
                int t=find(a);
                int c=find(b);
                
                if(t==q||t==w||c==q||c==w){
                _union(a,b);
                st.insert(a);
                st.insert(b);
                }
                q=find(f);
                w=find(0);
            } for(auto &[a,b]:x.second){
                
                int t=find(a);
                int c=find(b);
                
                if(t==q||t==w||c==q||c==w){
                _union(a,b);
                st.insert(a);
                st.insert(b);
                }
                q=find(f);
                w=find(0);
            }
                for(int k=x.second.size()-1;k>=0;k--){
                    int a=x.second[k].first;
                    int b=x.second[k].second;
                     int t=find(a);
                int c=find(b);
                
                if(t==q||t==w||c==q||c==w){
                _union(a,b);
                st.insert(a);
                st.insert(b);
                }
                q=find(f);
                w=find(0);
                }
                
                for(int k=x.second.size()-1;k>=0;k--){
                    int a=x.second[k].first;
                    int b=x.second[k].second;
                     int t=find(a);
                int c=find(b);
                
                if(t==q||t==w||c==q||c==w){
                _union(a,b);
                st.insert(a);
                st.insert(b);
                }
                q=find(f);
                w=find(0);
                }
               
            }
        }
        vector<int>ans;
        
        
        
        for(auto x:st){
            int y=find(x);
            
            
            
                ans.push_back(x);
            
        }
        
        
        return ans;
    }
};


















