class Solution {
public:
    int maximumUnits(vector<vector<int>>& box, int ts) {
        sort(box.begin(),box.end(),[](vector<int>a,vector<int>b){
            return a[1]>b[1];
        });
    int ans=0;
        for(int i=0;i<box.size();i++){
            if(ts>=box[i][0]){
              ans+=box[i][0]*box[i][1];  
                ts-=box[i][0];
            }
            else{
                ans+=ts*box[i][1];
                break;
            }
        }
        return ans;
        
    }
};