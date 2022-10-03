class Solution {
public:
    void find(int i,int n,int count,int sum,vector<int>& nums,vector<vector<int>>& a)
	{
		if(i==n)
		{
			a[count].push_back(sum);
			return;
		}
		find(i+1,n,count,sum,nums,a);
		find(i+1,n,count+1,sum+nums[i],nums,a);
	}
    int minimumDifference(vector<int>& nums) {
        vector<int> nums1,nums2;
		int n = nums.size()/2;
		long long sum=0;
		for(int i=0;i<n;i++)
		{
			nums1.push_back(nums[i]);
			nums2.push_back(nums[i+n]);
			sum+=nums1.back()+nums2.back();
		}
        
		vector<vector<int>> a(n+1,vector<int>());
		vector<vector<int>> b(n+1,vector<int>());

		find(0,n,0,0,nums1,a);
		find(0,n,0,0,nums2,b);
        
        for(int i=0;i<=n;i++)
		{
			sort(a[i].begin(),a[i].end());
			sort(b[i].begin(),b[i].end());
		}
        int s=sum/2;
        int ans=INT_MAX;
        for(int i=0;i<=n;i++){
            for(auto x:a[i]){
                //apply binary search for the other part
                auto it=lower_bound(b[n-i].begin(),b[n-i].end(),s-x);
                if(it!=b[n-i].end()){
                    //calc
                    int ts=*it+x;
                    int an=abs(sum-2*ts);
                    ans=min(ans,an);
                }
                
            }
        }
        
        return ans;
    }
};