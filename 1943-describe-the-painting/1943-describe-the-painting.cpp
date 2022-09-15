class Solution {
public:
    vector<vector<long long>> splitPainting(vector<vector<int>>& seg) {
        vector<long long>vec(1e5+1,0);
        vector<bool>start(1e5+1,false);
        vector<bool>end(1e5+1,false);
        for(auto &x:seg){
            vec[x[0]]+=x[2];
            vec[x[1]]-=x[2];
            start[x[0]]=true;
            end[x[1]]=true;
            
            
        }
        for(int i=1;i<vec.size();i++){
            vec[i]+=vec[i-1];
        }
        long long s=0,e=1e9+7,prev=-1;
        // for(int i=0;i<=9;i++){
        //     cout<<vec[i]<<" ";
        // }
        vector<vector<long long>>ans;
        for(int i=0;i<vec.size();i++){
            
            
                
                if(end[i]||start[i]){
                    if(s!=0&&vec[i-1]!=0){
                    ans.push_back({s,i,vec[i-1]});
                    }
                    s=i;
                }
                
            
        }
        // ans.push_back({start,end+1,prev});
        
        return ans;
        
        
        
    }
};