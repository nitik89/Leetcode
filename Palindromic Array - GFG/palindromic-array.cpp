// { Driver Code Starts
#include<iostream>
#include<string.h>
using namespace std;


 // } Driver Code Ends
/*Complete the function below*/

class Solution {
public:
   int PalinArray(int a[], int n)
   
   {
    int i;
       for(i=0;i<n;i++)
       {
           int ans=0;
           int temp=a[i];
           while(a[i])
            {
                int n=a[i]%10;
                ans=ans*10+n;
                a[i]=a[i]/10;
            }
            if(ans==temp)
            continue;
            else
             return 0;
       }
       if(i==n)
        return 1;
    // code here
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
		for(int i = 0; i < n; i++)
			cin>>a[i];
		Solution obj;
		cout<<obj.PalinArray(a,n)<<endl;
	}
}  // } Driver Code Ends