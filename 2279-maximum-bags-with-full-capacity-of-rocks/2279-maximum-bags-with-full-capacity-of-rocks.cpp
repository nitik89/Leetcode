class Solution {
public:
    int maximumBags(vector<int>& cap, vector<int>& rocks, int addt) {
        int n=rocks.size();
        vector<int>req(n);
        
        for(int i=0;i<n;i++){
            req[i]=cap[i]-rocks[i];
        }
        sort(req.begin(),req.end());
        int cnt=0;
        for(int i=0;i<n;i++){
            if(req[i]==0){
                cnt++;
            }
            else{
                if(addt>=req[i]){
                    addt-=req[i];
                    cnt++;
                }
                else{
                    break;
                }
            }
        }
        return cnt;
    }
};