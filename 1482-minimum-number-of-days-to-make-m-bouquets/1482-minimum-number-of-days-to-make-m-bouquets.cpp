class Solution {
public:
    bool isPossible(vector<int>&day,int val,int m,int k){
        int curr=0,count=0;
        for(auto x:day){
            if(val>=x){
                curr++;
                if(curr==k){
                    count++;
                    curr=0;
                }
            }
            else{
                curr=0;
                //reset it
            }
            if(count>=m){
                return true;
            }
        }
        return false;
    }
    int minDays(vector<int>& day, int m, int k) {
        int mn=INT_MAX,mx=INT_MIN;
        for(auto x:day){
            mn=min(mn,x);
            mx=max(mx,x);
        }
        int s=mn,e=mx,ans=-1;
        
        while(s<=e){
            int mid=(s+e)>>1;
            if(isPossible(day,mid,m,k)){
                // cout<<ans<<" "<<mid<<"\n";
                ans=mid;
                e=mid-1;
            }
            else{
                s=mid+1;
            }
        }
        return ans;
    }
};