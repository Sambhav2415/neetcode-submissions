class Solution {
public:
    int binarySearchAsc(MountainArray &arr, int target, int l, int r) {
        while (l <= r) {
            int mid = l + (r - l) / 2;

            int val = arr.get(mid);

            if (val == target) return mid;

            if (val < target)
                l = mid + 1;
            else
                r = mid - 1;
        }

        return -1;
    }

    int binarySearchDesc(MountainArray &arr, int target, int l, int r) {
        while (l <= r) {
            int mid = l + (r - l) / 2;

            int val = arr.get(mid);

            if (val == target) return mid;

            if (val > target)
                l = mid + 1;
            else
                r = mid - 1;
        }

        return -1;
    }

    int findInMountainArray(int target, MountainArray &mountainArr) {
        int n = mountainArr.length();

        // Find peak
        int low = 0, high = n - 1;

        while (low < high) {
            int mid = low + (high - low) / 2;

            if (mountainArr.get(mid) < mountainArr.get(mid + 1))
                low = mid + 1;
            else
                high = mid;
        }

        int peak = low;

        // Search left (ascending part)
        int ans = binarySearchAsc(mountainArr, target, 0, peak);
        if (ans != -1) return ans;

        // Search right (descending part)
        return binarySearchDesc(mountainArr, target, peak + 1, n - 1);
    }
};