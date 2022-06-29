class Solution {
public:
    vector<vector<int>> reconstructQueue(vector<vector<int>>& people) {
        sort(people.begin(),people.end(),[](vector<int>a,vector<int>b){
             if(a[0]<b[0]){
                return true;
            }
            else if(a[0]==b[0] && a[1]<b[1]){
                return true;
            }
            else{
                return false;
            }
        });
        vector<vector<int>>ans(people.size(),vector<int>{-1,-1});
        for(int i=0;i<people.size();i++){
            int first=people[i][0];
            int sec=people[i][1];
            int save=sec;
            for(int j=0;j<people.size();j++){
                if(sec==0&&ans[j][0]==-1){
                    
                    ans[j][0]=first;
                    ans[j][1]=save;
                    break;
                }
                if(ans[j][0]>=first||ans[j][0]==-1){
                    sec--;
                }
            }
            
        }
        // for(auto x:people){
        //     cout<<x[0]<<" "<<x[1]<<"\n";
        // }
        return ans;
    }
};