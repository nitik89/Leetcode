class Solution {
public:
    int threeSumMulti(vector<int>& arr, int target) {
        sort(arr.begin(),arr.end());
        int mod=1e9+7;
        int n=arr.size();
        long long res=0;
        for(int i=0;i<n-2;i++){
            int k=i+1;
            int j=n-1;
        
            while(k<j){
            int sum=arr[k]+arr[j]+arr[i];

                if(sum>target){
                    j--;
                }
                else if(sum<target){
                    k++;
                }
                else{
                    int cnt1=1,cnt2=1;
                    while(k<j&&arr[k]==arr[k+1]){
                        k++;
                        cnt1++;
                    }
                    while(k<j&&arr[j]==arr[j-1]){
                        j--;
                        cnt2++;
                    }
                    if(k!=j){
                         res+=((cnt1%mod *cnt2%mod))%mod;
                    }
                    else{
                        res+=((cnt1%mod*(cnt1-1)%mod)/2)%mod;
                    }
                    k++;
                    j--;
                    
                   
                }
            }
        }
            return res%mod;
        
    }
};