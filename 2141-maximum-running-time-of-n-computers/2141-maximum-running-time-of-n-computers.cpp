class Solution {
public:
    bool isPos(int n,vector<int>&bat,long long val){
        
        long long v=val;
        long long cnt=0;
        long long back=val-min((long long)bat[bat.size()-1],val);
        // back-=val;
        if(back==0){
            cnt++;
        }
        for(int i=bat.size()-2;i>=0;i--){
           long long my=bat[i];
           long long del=min(back,my);
            if(back!=0){
            back-=del;
            if(back==0){
                cnt++;
            }
            else if(back!=0){
                continue;
            }
            }
            v=val;
            my-=del;
            long long v1=min(v,my);
            v-=v1;
            if(v==0){
                cnt++;
            }
            else{
                back=0;
                back+=v;
            }
            
        }
        return cnt>=n;
    }
    long long maxRunTime(int n, vector<int>& bat) {
        sort(bat.begin(),bat.end());
        long long i=0,j=0;
        for(auto x:bat){
            j+=x;
        }
        long long ans=-1;
        while(i<=j){
            long long mid=(i+(j-i)/2);
            if(isPos(n,bat,mid)){
                ans=mid;
                i=mid+1;
            }
            else{
                j=mid-1;
            }
        }
        return ans;
    }
};