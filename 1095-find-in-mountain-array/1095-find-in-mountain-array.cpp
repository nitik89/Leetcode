class Solution {
public:
    int peakIndex(MountainArray &mountainArr,int lo, int hi)
    {
        while(lo<=hi)
        {
            int mid=lo+(hi-lo)/2;
            if(mountainArr.get(mid)<mountainArr.get(mid+1))
                lo=mid+1;
            else
                hi=mid-1;
        }
        return lo;
    }
    int bs1(MountainArray &mountainArr, int lo, int hi, int target)
    {
        while(lo<=hi)
        {
            int mid=lo+(hi-lo)/2;
            if(mountainArr.get(mid)==target)
                return mid;
            else if(mountainArr.get(mid)<target)
                lo=mid+1;
            else
                hi=mid-1;
        }
        return -1;
    }
    int bs2(MountainArray &mountainArr, int lo, int hi, int target)
    {
        while(lo<=hi)
        {
            int mid=lo+(hi-lo)/2;
            if(mountainArr.get(mid)==target)
                return mid;
            else if(mountainArr.get(mid)>target)
                lo=mid+1;
            else
                hi=mid-1;
        }
        return -1;
    }
    int findInMountainArray(int target, MountainArray &mountainArr) 
    {
        int n=mountainArr.length();
        int peak=peakIndex(mountainArr,0,n-1);
        cout<<peak;
        int idx1=bs1(mountainArr,0,peak,target);
        int idx2=bs2(mountainArr,peak,n-1,target);
        return idx1==-1?idx2:idx1;
    }
};