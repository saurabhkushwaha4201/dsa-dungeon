class NumArray {
public:
    int n;
    vector<int>segTree;

    void buildST(int i, int l, int r, vector<int>&segTree, vector<int>&nums)
    {
        if(l==r)
        {
            segTree[i] = nums[l];
            return ;
        }
        int mid = (l+r)/2;
        buildST(2*i+1,l,mid,segTree,nums);
        buildST(2*i+2,mid+1,r,segTree,nums);

        segTree[i] = segTree[2*i+1] + segTree[2*i+2];
    }
    void updateQuery(int index,int i, int l, int r, int val)
    {
        if(l==r)
        {
            segTree[i] = val;
            return;
        }

        int mid = (l+r)/2;
        if(index<=mid)
        {
            updateQuery(index,2*i+1,l,mid,val);
        }
        else
        {
            updateQuery(index,2*i+2,mid+1,r,val);
        }

        segTree[i] = segTree[2*i+1] + segTree[2*i+2];
    }
    int queryResult(int start, int end, int i, int l, int r)
    {
        int mid = (l+r)/2;
        if(l>end || r<start)
        return 0;
        else if(l>=start && r<=end)
        {
            return segTree[i];
        }
        else
        {
            return queryResult(start,end,2*i+1,l,mid) + queryResult(start,end,2*i+2,mid+1,r);
        }
    }
    NumArray(vector<int>& nums) {
        n = nums.size();
        segTree.resize(4*n);
        buildST(0,0,n-1,segTree,nums);
    }
    
    void update(int index, int val) {
        updateQuery(index,0,0,n-1,val);
    }
    
    int sumRange(int left, int right) {
        return queryResult(left,right,0,0,n-1);
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * obj->update(index,val);
 * int param_2 = obj->sumRange(left,right);
 */
