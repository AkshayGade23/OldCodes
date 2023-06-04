public class SearchInMountain {

    public static void main(String[] args) {
        int arr[] = { 1, 3, 4, 6, 4, 3, 2 };
        int target = 2;
        System.out.println("element is at" + findInMountainArray(arr, target));
    }

    static int findInMountainArray(int[] arr, int target) {

        int peak = peakIndexInMountainArray(arr);

        if (arr[peak] != target) {
            int start = 0;
            int end = peak - 1;
            int ans = binarySearch(arr, target, start, end, true);

            if (ans == -1) {
                start = peak + 1;
                end = arr.length - 1;
                ans = binarySearch(arr, target, start, end, false);
            }
            return ans;
        }
        return peak;
    }

    static int peakIndexInMountainArray(int[] arr) {
        int start = 0;
        int end = arr.length - 1;

        while (start < end) {
            int mid = start + (end - start) / 2;

            if (arr[mid] > arr[mid + 1])
                end = mid;
            else
                start = mid + 1;
        }
        return start;
    }

    static int binarySearch(int[] nums, int target, int start, int end, boolean isAsc) {

        while (start <= end) {
            int mid = start + (end - start) / 2;

            if (target < nums[mid]) {
                if (isAsc)
                    end = mid - 1;
                else
                    start = mid + 1;

            } else if (target > nums[mid]) {
                if (isAsc)
                    start = mid + 1;
                else
                    end = mid - 1;
            } else {
                return mid;
            }

        }
        return -1;

    }
}
