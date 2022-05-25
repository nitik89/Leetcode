class Solution {
public:
    int maxPoints(vector<vector<int>>& points) {
        int mx=INT_MIN;
        if(points.size()==1){
            return 1;
        }
        for(int i=0;i<points.size();i++){
            unordered_map<long double,int>mp;
            for(int j=0;j<points.size();j++){
                if(i==j){
                    continue;
                }
                long double x1=points[i][0],x2=points[j][0];
                // cout<<x1<<" "<<x2<<"\n";
                long double y1=points[i][1],y2=points[j][1];
                // cout<<y1<<" "<<y2<<"\n";
                long double slope;
                if(x2-x1==0){
                    slope=INT_MAX;
                }
                else{
                slope=((y2-y1)/(x2-x1));
                }
                mp[slope]++;
                mx=max(mx,mp[slope]);
            }
        
        }
        return mx+1;
    }
};