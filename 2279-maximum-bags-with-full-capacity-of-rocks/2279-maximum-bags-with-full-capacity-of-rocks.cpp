class Solution {
public:
    int maximumBags(vector<int>& cap, vector<int>& rocks, int addt) {
        int n=rocks.size();
        
        for(int i=0;i<n;i++){
            cap[i]=cap[i]-rocks[i];
        }
        sort(cap.begin(),cap.end());
        int cnt=0;
        for(int i=0;i<n;i++){
            if(cap[i]==0){
                cnt++;
            }
            else{
                if(addt>=cap[i]){
                    addt-=cap[i];
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