class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        int n=nums.size();
        vector<int>suffix(n,0);
        suffix[n-1]=nums[n-1];
        for(int i=n-2;i>=0;i--){
            suffix[i]+=nums[i]+suffix[i+1];
        }
        int ans=INT_MAX;
        int sum=0;
        
        for(int i=-1;i<n;i++){
            int s=i+1,e=n-1;
            if(i>=0){
            sum+=nums[i];
            x-=nums[i];
            }
            if(x==0){
                ans=min(ans,i+1);
                break;
            }
            // cout<<s<<" "<<e<<"\n";
            // cout<<sum<<" "<<s<<" "<<e<<"\n";
            while(s<=e){
                int mid=(s+e)/2;
                
                // cout<<suffix[mid]<<"\n";
                if(suffix[mid]==x){
                    // cout<<"aagya";
                    
                    ans=min(i+1+(n-mid),ans);
                    break;
                }
                else if(suffix[mid]>x){
                    s=mid+1;
                }
                else{
                    e=mid-1;
                }
            }
        }
        return ans==INT_MAX?-1:ans;
    }
};