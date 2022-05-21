// { Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
//User function template for C++

class Solution{
public:
	bool recreationalSpot(int nums[], int n){
		 vector<int>leftmin(n);
        leftmin[0]=nums[0];
        for(int i=1;i<n;i++){
            leftmin[i]=min(leftmin[i-1],nums[i]);
        }
        
        stack<int>stk;
        
        stk.push(nums[n-1]);
        for(int i=n-2;i>=0;i--){
            // stack<int>temp=stk;
            if(nums[i]>leftmin[i]){
                while(!stk.empty()&&(stk.top()<=leftmin[i])){
                    stk.pop();
                }
                
                if(!stk.empty()){
                    // cout<<temp.top()<<" "<<nums[i]<<" "<<leftmin[i]<<"\n";
                    if(stk.top()<nums[i]&&leftmin[i]<stk.top()){
                        return true;
                    }
                }
               stk.push(nums[i]); 
            }
            
            
        }
        return false;
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
		int arr[n];
		for(int i=0;i<n;i++)
		    cin>>arr[i];
		Solution ob;
		if(ob.recreationalSpot(arr, n))
		    cout<<"True"<<endl;
		else
		    cout<<"False"<<endl;
	}
	return 0;
}  // } Driver Code Ends