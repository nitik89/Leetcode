class Solution {
public:
    int fillCups(vector<int>& am) {
        sort(am.begin(),am.end());
        int time=0;
        int i=0,j=2;
       if(am[0]==0&&am[1]==0){
           return am[2];
       }
        if(am[0]==0){
            return am[2];
        }
        while(true){
            sort(am.begin(),am.end());
            if(i==1){
                return am[2]+time;
            }
            if(am[i]>0){
                am[i]--;
            }
            if(am[j]>0){
                am[j]--;
            }
            if(am[i]==0){
                i++;
                
            }
            
            time++;
            int br=0;
            for(auto x:am){
                if(x!=0){
                    br=1;
                    break;
                }
            }
            if(br==0){
                return time;
            }
        }
        return time;
    }
};