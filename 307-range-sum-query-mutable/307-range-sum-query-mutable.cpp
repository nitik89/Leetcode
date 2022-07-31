class NumArray {
public:
    vector<int> seg; 
    int n; 
    void buildTree(vector<int>& nums, int pos, int left, int right){
        if (left == right){
            seg[pos] = nums[left]; 
            return;
        }
        int mid = (left+right)/2;
        buildTree(nums, 2*pos+1, left, mid);
        buildTree(nums, 2*pos+2, mid+1, right);
        seg[pos]=seg[2*pos+1]+ seg[2*pos+2];
    }
    int getSum(int lf,int rg,int left,int right,int pos){
        if(left>=lf&&rg>=right){
            // cout<<seg[pos]<<" ";
            return seg[pos];
        }
        if(lf>right||rg<left){
            return 0;
        }
        
        int mid=(left+right)/2;
        return getSum(lf,rg,left,mid,2*pos+1)+getSum(lf,rg,mid+1,right,2*pos+2);
    }
    void updateit(int left,int right,int idx,int val,int pos){
        if(left>idx||right<idx){
            return;
        }
        if(left==right){
            if(left==idx){
                seg[pos]=val;
            }
            return;
        }
        int mid=(left)+(right-left)/2;
        updateit(left,mid,idx,val,2*pos+1);
        updateit(mid+1,right,idx,val,2*pos+2);
        seg[pos]=seg[2*pos+1]+seg[2*pos+2];
    }
    NumArray(vector<int>& nums) {
        n=nums.size();
        seg.resize(4*n);
        buildTree(nums,0,0,nums.size()-1);
    }
    
    void update(int index, int val) {
        return updateit(0,n-1,index,val,0);
    }
    
    int sumRange(int left, int right) {
        return getSum(left,right,0,n-1,0);
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * obj->update(index,val);
 * int param_2 = obj->sumRange(left,right);
 */