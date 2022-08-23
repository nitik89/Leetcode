class Solution {
public:
    int peakIndexInMountainArray(vector<int>& arr) {
        int i=0,j=arr.size()-1;
        while(i<=j){
            int mid=(i+j)/2;
            // cout<<mid<<" ";
            if((mid==0||arr[mid]>arr[mid-1])&&(mid==arr.size()-1||arr[mid]>arr[mid+1])){
                return mid;
            }
            else if(mid==0||arr[mid]>arr[mid-1]){
                i=mid+1;
            }
            else{
                j=mid-1;
            }
        }
        return -1;
    }
};