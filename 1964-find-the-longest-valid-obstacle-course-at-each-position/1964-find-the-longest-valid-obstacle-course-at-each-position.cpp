class Solution {
public:
    vector<int> longestObstacleCourseAtEachPosition(vector<int>& obs) {
        vector<int>lis;
        vector<int>ans;
        for(int i=0;i<obs.size();i++){
            auto it=upper_bound(lis.begin(),lis.end(),obs[i]);
            // cout<<it-lis.begin()<<" ";
            if(it==lis.end()){
                lis.push_back(obs[i]);
                ans.push_back(lis.size());
            }
            else{
                int idx=it-lis.begin();
                if(obs[i]==lis[idx]){
                    it++;
                    int idx2=it-lis.begin();
                    if(idx2==lis.size()){
                        lis.push_back(obs[i]);
                    }
                    else{
                        lis[idx2]=obs[i];
                    }
                }
                else{
                    lis[idx]=obs[i];
                }
                ans.push_back(it-lis.begin()+1);
            }
            
        }
        return ans;
    }
};