class Solution {
public:
    int ans=INT_MIN;
    void getAns(vector<int>&tc,int cost,int idx,int tr){
        if(idx==tc.size()){
            // cout<<cost<<" ";
            
                if(ans==INT_MIN){
                    ans=cost;
                }
                else{
                    if(abs(ans-tr)>abs(cost-tr)){
                        ans=cost;
                    }
                    else if(abs(ans-tr)==abs(cost-tr)){
                        ans=min(ans,cost);
                    }
                }
            return;
        }
        getAns(tc,cost,idx+1,tr);
        getAns(tc,cost+tc[idx],idx+1,tr);
        getAns(tc,cost+2*tc[idx],idx+1,tr);
    }
    int closestCost(vector<int>& bc, vector<int>& tc, int tr) {
        for(auto x:bc){
            getAns(tc,x,0,tr);
        }
        return ans;
    }
};