public class InfiniteArray {
    public static void main(String[] args) {
        int[] infiniteArr = { 2, 3, 4, 6, 7, 8, 9, 10, 11, 13, 15, 20, 23, 27, 30 };
        int target = 15;
        System.out.println(ans(infiniteArr, target));
    }

    static int ans(int arr[], int target) {
        int start = 0;
        int end = 1;

        while (target > arr[end]) {
            int newStart = end + 1;
            end = end + (end - start + 1) * 2;
            start = newStart;
            System.out.println(start  + "  " + end +  "   "+arr[end]);

        }
        return binarySearch(arr, target, start, end);
    }

    static int binarySearch(int[] arr, int target, int start, int end) {

        while (start <= end) {
            int mid = start + (end - start) / 2;
            if (target < arr[mid]) {
                end = mid - 1;
            } else if (target > arr[mid]) {
                start = mid + 1;
            } else {
                return mid;
            }
        }
        return -1;

    }
}