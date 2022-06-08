class Solution {
public:
    int countLatticePoints(vector<vector<int>>& circles) {
        int cnt=0;
        set<pair<int,int>>mp;
        for(int i=0;i<circles.size();i++){
            int x=circles[i][0];
            int y=circles[i][1];
            double r=circles[i][2];
            for(int j=0;j<=200;j++){
                for(int k=0;k<=200;k++){
                    //point(j,k)
                    double dis=sqrt((x-j)*(x-j)+(y-k)*(y-k));
                   
                    if(dis<=r){
                         if(mp.find({j,k})==mp.end()){
                      cnt++;
                             mp.insert({j,k});
                         }
                    }
                }
            }
        }
        return cnt;
    }
};