// Core Idea

// For 3 sides a, b, c (with a ≤ b ≤ c) to form a triangle with non-zero area, the triangle inequality must hold:
// 👉 a + b > c

// If this fails, the sides cannot form a triangle.

// Step-by-step logic in code (without giving actual code)

// Sort the array

// Sorting makes it easy to check the triangle condition because the largest side will always be at the end.

// After sorting, you can just check consecutive triplets.

// Check from largest to smallest

// Start from the end of the array (the largest numbers).

// Pick three numbers nums[i], nums[i-1], nums[i-2].

// If they satisfy nums[i-2] + nums[i-1] > nums[i], then these three sides form a valid triangle.

// Return the perimeter

// If valid, return their sum (since larger sides give larger perimeter).

// This will be the maximum perimeter possible because we are checking from largest downward.

// If no valid triplet is found

// That means no triangle can be formed with non-zero area.

// Return 0.

// Example Walkthrough
// Example 1: nums = [2,1,2]

// Sorted → [1,2,2]

// Check last 3: 1 + 2 > 2 ✅ (valid)

// Perimeter = 1+2+2 = 5.

// Example 2: nums = [1,2,1,10]

// Sorted → [1,1,2,10]

// Check last 3: 1+2 > 10 ❌

// Next 3: 1+1 > 2 ❌

// No valid triplet → return 0.

#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class Solution {
public:
    int largestPerimeter(vector<int>& nums) {
        int n=nums.size();
        sort(nums.begin(),nums.end());
        for(int i=n-1;i>=2;i--){
            if(nums[i-1]+nums[i-2]>nums[i]){
                return nums[i]+nums[i-1]+nums[i-2];
            }
        }
        return 0;
    }
};
