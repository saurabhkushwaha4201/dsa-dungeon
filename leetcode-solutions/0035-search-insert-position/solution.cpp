#include <vector>
using namespace std;

class Solution {
public:
    int searchInsert(vector<int>& nums, int target) 
    {
        int start = 0;
        int end = nums.size() - 1;

        while (start <= end) 
        {
            int mid = start + (end - start) / 2;
            
            if (nums[mid] == target) 
            {
                return mid;  // Target found at mid
            }
            else if (nums[mid] < target) 
            {
                start = mid + 1;  // Search in the right half
            }
            else 
            {
                end = mid - 1;  // Search in the left half
            }
        }
        
        // If target is not found, start will be the index where it should be inserted.
        return start;
    }
};

