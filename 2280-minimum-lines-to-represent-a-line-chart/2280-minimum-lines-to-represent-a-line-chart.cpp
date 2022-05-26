class Solution {
public:
    int minimumLines(vector<vector<int>>& stock) {
        sort(stock.begin(),stock.end());
        long double sl=1e10;
        int cnt=0;
        for(int i=1;i<stock.size();i++){
            long double x1=stock[i-1][0],y1=stock[i-1][1];
            long double x2=stock[i][0],y2=stock[i][1];
            long double slope= (y2-y1)/(x2-x1);
            if(slope!=sl){
                cnt++;
                sl=slope;
            }
        }
        return cnt;
    }
};