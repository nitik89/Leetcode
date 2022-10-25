class LockingTree
{
    public:
        vector<vector < int>> down;
    vector<vector < int>> up;
    vector<int> mp;
    LockingTree(vector<int> &parent)
    {
        int n = parent.size();
        mp.resize(n + 1, 0);
        down.resize(n);
        up.resize(n);
        for (int i = 1; i < parent.size(); i++)
        {
            down[parent[i]].push_back(i);
        }
        for (int i = 1; i < parent.size(); i++)
        {
            up[i].push_back(parent[i]);
        }
    }

    bool lock(int num, int user)
    {
       	// cout<<num<<" "<<mp[num]<<" ";
        if (mp[num] == 0)
        {
           	// cout<<num<<" ";
            mp[num] = user;
            return true;
        }
        return false;
    }

    bool unlock(int num, int user)
    {
        if (mp[num] && mp[num] == user)
        {
            mp[num] = 0;
            return true;
        }
        return false;
    }

    bool upgrade(int num, int user)
    {
        if (mp[num])
        {
            return false;
        }
        if (checkup(num) || !checkdown(num)) return false;
        unlockAll(num);
       	// cout<<num<<" ";
        mp[num] = user;
        return true;
    }
    void unlockAll(int num)
    {

        mp[num] = 0;

        for (auto x: down[num])
        {

            unlockAll(x);
        }
    }
    bool checkup(int num)
    {

        bool ans = false;
        for (auto x: up[num])
        {
            if (mp[x])
            {
                return true;
            }
            ans = ans | checkup(x);
        }
        return ans;
    }
    bool checkdown(int num)
    {
       	// cout<<num<<" ";
        bool ans = false;
        for (auto x: down[num])
        {
            if (mp[x])
            {
                return true;
            }
            ans = ans | checkdown(x);
        }
        return ans;
    }
};

/**
 *Your LockingTree object will be instantiated and called as such:
 *LockingTree* obj = new LockingTree(parent);
 *bool param_1 = obj->lock(num,user);
 *bool param_2 = obj->unlock(num,user);
 *bool param_3 = obj->upgrade(num,user);
 */