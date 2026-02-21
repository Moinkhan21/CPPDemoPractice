#include <iostream>
#include <vector>
using namespace std;

// =====================================================
// FUNCTION: singleNumber
// -----------------------------------------------------
// PURPOSE:
//   Find the element that appears only once,
//   while all other elements appear twice.
//
// APPROACH:
//   Use XOR operation
//
// PROPERTIES OF XOR:
//   • a ^ a = 0
//   • a ^ 0 = a
//   • XOR is commutative & associative
//
// IDEA:
//   Duplicate elements cancel each other,
//   leaving only the unique element.
// =====================================================
int singleNumber(vector<int>& nums) {

    int ans = 0;

    for (int i = 0; i < nums.size(); i++) {
        ans = ans ^ nums[i];   // XOR with current element
    }

    return ans;
}

// =====================================================
// MAIN FUNCTION
// =====================================================
int main() {

    // Example input
    vector<int> nums = {4, 1, 2, 1, 2};

    int result = singleNumber(nums);

    cout << "Single number is: " << result << endl;

    return 0;
}