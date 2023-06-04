public class BinarySearch {
    public static void main(String[] args) {

        int arr[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9 };
        int pos = binarySearch(arr, 7);
        System.out.println(pos);
    }

    static int binarySearch(int[] nums, int target) {
        int start = 0;
        int n = nums.length;
        int end = n - 1;

        while (start <= end) {
            int mid = start + (end - start) / 2;
            if (target < nums[mid]) {
                end = mid - 1;
            } else if (target > nums[mid]) {
                start = mid + 1;
            } else {
               return mid;
            }
        }
        return -1;

    }
}