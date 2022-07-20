class Solution {
public:
    int isPos(vector<vector<int>>&tas,int val){
        
        int t=val;
        for(int i=tas.size()-1;i>=0;i--){
            if(val>=tas[i][1]){
            val=val-tas[i][0];
                if(t==32){
                    cout<<val<<" ";
                }
            if(val<0){
                return false;
            }
            }
            else{
                return false;
            }
        }
        return val>=0;
    }
    int minimumEffort(vector<vector<int>>& tasks) {
        int mx=-1;
        sort(tasks.begin(),tasks.end(),[](vector<int>&a,vector<int>&b){
            return a[1]-a[0]<b[1]-b[0];
        });
        
        int i=0,j=1e9,ans=-1;
        // cout<<i<<" "<<j<<"\n";
        while(i<=j){
            int mid=(i+j)/2;
            // cout<<mid<<" ";
            if(isPos(tasks,mid)){
                ans=mid;
                j=mid-1;
            }
            else{
                i=mid+1;
            }
        }
        

        return ans;
    }
};