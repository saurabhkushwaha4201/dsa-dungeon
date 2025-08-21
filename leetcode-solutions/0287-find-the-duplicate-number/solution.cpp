class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        // -----------------------------
        // Phase 1: Detect intersection point inside the cycle
        // -----------------------------
        // Think of nums as a linked list where:
        // - index = node
        // - nums[i] = next pointer
        // Since we have n+1 numbers in [1..n], pigeonhole principle
        // guarantees at least one duplicate, which creates a cycle.

        int slow = nums[0];        // slow pointer (tortoise) starts at first element
        int fast = nums[0];        // fast pointer (hare) also starts at first element

        // Move slow by 1 step, fast by 2 steps, until they meet
        // Use do-while to ensure they actually move at least once
        do {
            slow = nums[slow];        // move 1 step
            fast = nums[nums[fast]];  // move 2 steps
        } while (slow != fast);

        // -----------------------------
        // Phase 2: Find entrance of the cycle
        // -----------------------------
        // When slow and fast meet, it's somewhere inside the cycle.
        // Reset one pointer to the start, keep the other at meeting point.
        // Move both 1 step at a time. The node where they meet again
        // is the start of the cycle => duplicate number.

        slow = nums[0];   // reset slow to beginning
        while (slow != fast) {
            slow = nums[slow];    // move 1 step
            fast = nums[fast];    // move 1 step
        }

        // Both meet at the duplicate number
        return slow;
    }
};

