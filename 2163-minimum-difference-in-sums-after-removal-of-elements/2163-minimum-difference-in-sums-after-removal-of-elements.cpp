class Solution {
public:
    long long minimumDifference(vector<int>& nums) {
       priority_queue<long long>pq;
        priority_queue<long long,vector<long long>,greater<long long>>pq1;
        int n=nums.size()/3;
        vector<long long>pre;
        long long sum1=0;
        for(int i=0;i<2*n;i++){
            pq.push(nums[i]);
            sum1+=nums[i];
            if(pq.size()>n){
                sum1-=pq.top();

                pq.pop();
            }
            if(pq.size()==n){
                pre.push_back(sum1);
            }
        }
        
        vector<long long>suff;
        sum1=0;
       
        for(int i=3*n-1;i>=n;i--){
            pq1.push(nums[i]);
            sum1+=nums[i];
            if(pq1.size()>n){
                sum1-=pq1.top();
                pq1.pop();
                
            }
            if(pq1.size()==n){
                suff.push_back(sum1);
            }
        }
        reverse(suff.begin(),suff.end());
        long long ans=LONG_MAX;
        for(int i=0;i<suff.size();i++){
            // cout<<pre[i]<<" "<<suff[i]<<"\n";
            ans=min(pre[i]-suff[i],ans);
        }
        return ans;
    }
    
};