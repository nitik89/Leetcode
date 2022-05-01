class Solution {
public:
    int cnt;
    void count(vector<int>&nums,int i,int mid,int j){
        int k=i,m=mid+1;
        while(k<=mid&&m<=j){
            if((long long)nums[k]>(long long)2*nums[m]){
                //count the elements which are from the curr elemet to the last
                cnt+=(mid+1-k);
                m++;
            }
            else{
                k++;
            }
        }
        //merge and sort
        sort(nums.begin()+i,nums.begin()+j+1);
        
    }
    void mergeSort(vector<int>&nums,int i,int j){
        if(i>=j){
            return;
        }
        else if(j>i){
        int mid=(i+j)/2;
        mergeSort(nums,i,mid);
        mergeSort(nums,mid+1,j);
        count(nums,i,mid,j);
        }
    }
    int reversePairs(vector<int>& nums) {
        cnt=0;
        mergeSort(nums,0,nums.size()-1);
        return cnt;
    }
};