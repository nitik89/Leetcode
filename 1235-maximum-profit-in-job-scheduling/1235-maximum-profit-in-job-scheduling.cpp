class Solution {
public:
    class mysol{
        public:
        int a,b,c;
        mysol(int x,int y,int z){
            a=x;
            b=y;
            c=z;
        }
    };
    
    int jobScheduling(vector<int>& startTime, vector<int>& endTime, vector<int>& profit) {
        vector<mysol>vec;
        for(int i=0;i<startTime.size();i++){
           
            vec.push_back( mysol(startTime[i],endTime[i],profit[i]));
        }
        sort(vec.begin(),vec.end(),[](mysol&first,mysol&sec){
        return first.b<=sec.b;
    });
        
        
        int n=startTime.size();
        vector<int>dp(n,0);
        dp[0]=vec[0].c;
        for(int i=1;i<vec.size();i++){
           int last=-1,include=vec[i].c;
            int start=0,end=i-1;
            while(start<=end)
            {
                int mid=start+(end-start)/2;
                if(vec[mid].b<=vec[i].a)
                {
                    last=mid;
                    start=mid+1;
                }
                else
                {
                    end=mid-1;
                }
            }
            if(last!=-1)
            {
                include+=dp[last];
            }
            dp[i]=max(dp[i-1],include);
            }
        
        
        return dp[n-1];
        
    }
};