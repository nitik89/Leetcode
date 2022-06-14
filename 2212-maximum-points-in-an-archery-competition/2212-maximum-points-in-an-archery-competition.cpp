class Solution {
public:
    vector<int>finalans;
    int mx=INT_MIN;
    vector<int>an;
    void getAns(int arr,vector<int>&alice,int idx,int sum){
        if(arr<0){
            return;
        }
        if(idx<0){
            // cout<<arr<<" ";
            if(mx<sum&&arr>=0){
                
                // cout<<sum<<" "<<arr<<"\n";
                mx=sum;
               
                finalans=an;
                finalans[0]+=arr;
            }
            return;
        }
        if(alice[idx]+1<=arr){
            int curr=alice[idx]+1;
            an.push_back(curr);
            getAns(arr-(alice[idx]+1),alice,idx-1,sum+idx);
            an.pop_back();
        }
        an.push_back(0);
        getAns(arr,alice,idx-1,sum);
        an.pop_back();
    }
    vector<int> maximumBobPoints(int arr, vector<int>& alice) {
        getAns(arr,alice,alice.size()-1,0);
        // vector<int>an;
        reverse(finalans.begin(),finalans.end());
         // cout<<mx<<" ";
        return finalans;
        
    }
};