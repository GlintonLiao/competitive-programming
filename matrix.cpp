/*
    Given n elements
    make it into a row * col matrix
*/
vector<int> traverseMatrix(vector<int>& nums, int row, int col) {
    int n = nums.size();
    vector<vector<int>> res(row, vector<int>(col));
    // also a good way to traverse through matrix
    for (int i = 0; i < n; i++) {
        res[i / row][i % col] = nums[i];
    }
    return res;
}
