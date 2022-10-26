class Solution
{
    public:
        vector<int> tree;
    void update(int low, int high, int index, int val, int pos)
    {
        if (index < low && index > high)
        {
            return;
        }
        if (low == index && index == high)
        {
            tree[pos] = val;
            return;
        }
        int mid = (low + high) / 2;
        if (index <= mid) update(low, mid, index, val, 2 *pos + 1);
        else update(mid + 1, high, index, val, 2 *pos + 2);
        tree[pos] = tree[2 *pos + 1] &tree[2 *pos + 2];
    }

    int query(int qlow, int qhigh, int low, int high, int pos)
    {
        if (high < qlow || low > qhigh)
        {
            return 33554431;
        }
        if (qlow <= low && qhigh >= high)
        {
            return tree[pos];
        }
        int mid = (low + high) / 2;
       	// cout << pos << endl;
        int s1 = query(qlow, qhigh, low, mid, 2 *pos + 1);
        int s2 = query(qlow, qhigh, mid + 1, high, 2 *pos + 2);
        return s1 &s2;
    }
    int closestToTarget(vector<int> &arr, int target)
    {

        int n = arr.size();
        tree.resize(4 *n);
        for (int i = 0; i < n; i++)
        {
            update(0, n - 1, i, arr[i], 0);
        }
        int ans = INT_MAX;
        for (int i = 0; i < n; i++)
        {
            int left = i, right = n - 1;
            while (left <= right)
            {
                int mid = (left + right) / 2;
                int v = query(i, mid, 0, n - 1, 0);
                if (v < target)
                {
                    right = mid - 1;
                }
                else
                {
                    left = mid + 1;
                }
                ans = min(ans, abs(target - v));
            }
        }
        return ans;
    }
};