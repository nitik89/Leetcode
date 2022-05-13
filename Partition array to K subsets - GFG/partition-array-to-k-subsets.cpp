// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
/*You are required to complete this method */

class Solution{
  public:
  vector<int>sm;
    bool getAns(int finalbit,int currbit,int nums[],int k,int target,int idx,int n){
       
        if(finalbit==currbit){
            return true;
        }
         if(idx>=n){
            return false;
        }
        for(int i=0;i<sm.size();i++){
            if(sm[i]+nums[idx]==target){
                sm[i]+=nums[idx];
                if(getAns(finalbit,currbit|(1<<i),nums,k,target,idx+1,n)){
                    return true;
                }
                sm[i]-=nums[idx];
            }
            else if(sm[i]+nums[idx]<target){
                sm[i]+=nums[idx];
                if(getAns(finalbit,currbit,nums,k,target,idx+1,n)){
                    return true;
                }
                sm[i]-=nums[idx];
            }
            
           
                
        }
        return false;
       
    }
    bool isKPartitionPossible(int a[], int n, int k)
    {
                int sum=0;
       
        for(int i=0;i<n;i++){
            sum+=a[i];
        }
        int finalbit=(1<<k)-1;
        sm.resize(k,0);
        int target=sum/k;
        sort(a,a+n);
        reverse(a,a+n);
        if(sum%k!=0){
            return false;
        }
        return getAns(finalbit,0,a,k,target,0,n);
    }
};

// { Driver Code Starts.
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
    	int n;
    	
    	cin>>n;
    	int a[n];
    	for(int i=0;i<n;i++)
    	cin>>a[i];
    	int k;
    	cin>>k;
    	Solution obj;
    	cout<<obj.isKPartitionPossible(a, n, k)<<endl;
    }
}  // } Driver Code Ends