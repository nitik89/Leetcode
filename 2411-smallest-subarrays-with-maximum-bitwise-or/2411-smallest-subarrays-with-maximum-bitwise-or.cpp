class Solution {
public:
    void addIt(vector<int>&vec,int val){
        for(int i=0;i<31;i++){
            if((1<<i)&val){
                vec[i]++;
            }
        }
    }
    int getCurr(vector<int>&vec){
        int curr=0;
        for(int i=0;i<31;i++){
            if(vec[i]){
                curr+=(1<<i);
            }
        }
        return curr;
    }
    void removeit(vector<int>&vec,int val){
        for(int i=0;i<31;i++){
            // cout<<vec[i]<<" ";
            if(((1<<i)&val)){
                vec[i]--;
            }
        }
    }
    vector<int> smallestSubarrays(vector<int>& nums) {
      
        int n=nums.size();
        vector<int>ans(n,INT_MAX);
        vector<int>vec(32,0);
        addIt(vec,nums[n-1]);
        ans[n-1]=1;
        int j=n-1;
        for(int i=n-2;i>=0;i--){
            
            addIt(vec,nums[i]);
            int c=getCurr(vec);
            // cout<<c<<" ";
            while(j>i){
                
                removeit(vec,nums[j]);
                // for(int k=0;k<31;k++){
                //     cout<<vec[k]<<" ";
                // }
                // cout<<"\n";
                if(getCurr(vec)==c){
                    // cout<<getCurr(vec)<<" "<<nums[j]<<" "<<c<<"\n";

                    j--;
                }
                else{
                    addIt(vec,nums[j]);
                    
                    break;
                }
            }
            ans[i]=min(ans[i],j-i+1);
        }
        return ans;
    }
};