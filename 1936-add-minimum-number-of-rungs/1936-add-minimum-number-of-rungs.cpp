class Solution {
public:
    int addRungs(vector<int>& rungs, int dist) {
       int prev=0,cnt=0;
        for(int i=0;i<rungs.size();i++){
            int diff=rungs[i]-prev;
            if(diff>dist){
                cnt+=diff/dist;
                if(diff%dist==0){
                    cnt--;
                }
            }
            prev=rungs[i];
        }
        return cnt;
    }
};