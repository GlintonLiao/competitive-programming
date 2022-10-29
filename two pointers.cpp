/*
    Before doing two pointers algorithm
    we need to ensure there is monotonicity
*/

/*
    Given an array nums, and a minK, maxK
    find how many sub-array contains at least one minK and one maxK
*/
long long countSubarrays(vector<int>& nums, int minK, int maxK) {
    long long res = 0;
    int smin = 0, smax = 0;
    for (int i = 0, last = 0, j = 0; i < nums.size(); i ++ ) {
        if (nums[i] < minK || nums[i] > maxK) {
            j = last = i + 1;
            smin = smax = 0;
            continue;
        }

        if (nums[i] == minK) smin ++ ;
        if (nums[i] == maxK) smax ++ ;

        while (j <= i) {
            if (nums[j] == minK) smin -- ;
            if (nums[j] == maxK) smax -- ;
            if (!smin || !smax) {
                if (nums[j] == minK) smin ++ ;
                if (nums[j] == maxK) smax ++ ;
                break;
            }--
            j ++ ;
        }

        if (smin && smax) {
            res += j - last + 1;
        }
    }

    return res;
}


/*
    odd and even pointer
    [1, 2, 2, 3, 4, 5, 6, 7]
    odd pointer: 0 -> 3 -> 5 -> 7
    even pointer: 1 -> 2 -> 4 -> 6
*/
void oddEvenPointer(vector<int>& nums, vector<int>& arr) {
    int jArr[2]{};
    for (auto& x : nums) {
        int p = x % 2;    // 0 or 1
        int &j = jArr[p]; // j will be first element when x is even
        while (arr[j] % 2 != p) j++; // j will traverse through each group
        cout << arr[j] << endl;
    }
}


/*
    sort an array according to something
    without modifing the original array
*/
void sortArr(vector<int>& arr) {
    vector<int> idx(arr.size());
    iota(idx.begin(), idx.end(), 0);  // fill the vector from 0 to n - 1
    sort(idx.begin(), idx.end(), [&](int a, int b) { return arr[i] > arr[j] });
}
