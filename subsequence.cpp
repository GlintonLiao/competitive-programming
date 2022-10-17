/*
    Given an array nums, find nums[k] such that
    nums[i] < nums[j] < nums[k], i < j < k

    can use a vector to store each value
*/
int increasingTri(vector<int>& nums) {
    // if asking for n-size combination, just replace 2 with n
    vector<int> q(2, INT_MAX);
    for (auto& x : nums) {
        int j = 2;
        while (j >= 0 && x <= q[j]) j--;
        if (j == 2) return x; // j didn't move, then we already got 2 elements inside
        else q[j] = x;
    }
    return -1;
}
