class Solution {
public:
    int search(vector<int>& arr, int target) {
        int n = arr.size();
        int low = 0;
        int high = n-1;
        
        while(low<=high)
        {
            int mid = low + (high-low)/2;
            // if mid is target
            if(arr[mid]==target)
            return mid;
            // The left side is sorted
            if(arr[mid]>=arr[low])
            {
                // Target lies in left side
                if(arr[low]<=target && target<=arr[mid])
                high = mid-1;
                else    // target lies in right side
                low = mid+1;
            }
            // Right side is sorted
            else
            {
                // target lies in right side
                if(arr[high]>=target && target>=arr[mid])
                {
                    low = mid+1;
                }
                else    // target lies in left side
                high = mid-1;
            }
        }
        return -1;
    }
};
