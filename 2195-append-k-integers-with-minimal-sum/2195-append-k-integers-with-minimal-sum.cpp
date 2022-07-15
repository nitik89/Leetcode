class Solution {
public:
    long long minimalKSum(vector<int>& nums, int k) {
       sort(nums.begin(),nums.end());
        // for(auto x:nums){
        //     cout<<x<<" ";
        // }
        long long sum=0;
        if(nums[0]-1>=k){
            long long sm=nums[0]-1;
            sum=(long long)(k*((long long) k+1))/2;
            return sum;
        }
        else if(nums[0]-1<k){
            long long sm=nums[0]-1;
            sum=(sm*(sm+1))/2;
            k-=sm;
        }
        // cout<<k<<"\n";
        
    for(int i=1;i<nums.size();i++){
        long long v1=nums[i-1];
        long long v2=nums[i]-1;
        
        if(v2-v1>=k){
          long long v1=nums[i-1];
          long long v2=nums[i-1]+k;
        long long sum1=(v1*(v1+1))/2;
        long long sum2=(v2*(v2+1))/2;
            sum+=(sum2-sum1);
            return sum;
        }
        else if(v2-v1>0){
            
             long long sum1=(v1*(v1+1))/2;
        long long sum2=(v2*(v2+1))/2;
            // cout<<sum1<<" "<<sum2<<"\n";
            sum+=(sum2-sum1);
            k-=((nums[i]-nums[i-1]-1));
            
            
            
        }
        // cout<<k<<" "<<sum<<"\n";
          
    }
        // cout<<sum<<" ";
        if(k>0){
            long long v1=nums[nums.size()-1];
        long long v2=nums[nums.size()-1]+k;
            long long sum1=(v1*(v1+1))/2;
        long long sum2=(v2*(v2+1))/2;
            sum+=(sum2-sum1);
        }
        return sum;
    }
};