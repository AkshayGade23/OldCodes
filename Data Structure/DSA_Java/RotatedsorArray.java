
// rotationcount method 
// find pivot method
// search method

public class RotatedsorArray {
    public static void main(String[] args) {
        int arr[] = { 1, 2, 3 };
        int target = 1;
        System.out.println("element at " + countRotation(arr));
    }

    static int countRotation(int arr[]) {

        return findPivot(arr) + 1;

    }

    static int search(int arr[], int target) {

        int pivot = findPivot(arr);
        // if pivot is not found, then array is not rotated, then do normal binary
        // search
        if (pivot == -1) {
            return binarySearch(arr, target, 0, arr.length - 1);
        }

        // if pivot is found ,
        if (arr[pivot] == target) {
            return pivot;
        }

        // then search in first half
        int ans = binarySearch(arr, target, 0, pivot - 1);
        // else search is another half
        if (ans == -1) {
            ans = binarySearch(arr, target, pivot + 1, arr.length - 1);
        }
        return ans;
    }

    // this isnt work for duplicate rotated sorted array.
    static int findPivot(int arr[]) {
        int start = 0;
        int end = arr.length - 1;

        while (start <= end) {
            int mid = start + (end - start) / 2;
            // four cases where pivot can found
            if (mid < end && arr[mid] > arr[mid + 1])
                return mid;

            if (mid > start && arr[mid] < arr[mid - 1])
                return mid - 1;

            if (arr[mid] <= arr[start])
                end = mid - 1;
            else
                start = mid + 1;

        }
        return -1;
    }

    static int findPivotWithDuplicate(int arr[]) {
        int start = 0;
        int end = arr.length - 1;

        while (start <= end) {
            int mid = start + (end - start) / 2;
            // four cases where pivot can found
            if (mid < end && arr[mid] > arr[mid + 1])
                return mid;

            if (mid > start && arr[mid] < arr[mid - 1])
                return mid - 1;

            if (arr[mid] == arr[start] && arr[mid] == arr[end]) {
                // checking start is pivot or not
                if (arr[start] > arr[start + 1])
                    return start;
                start++;

                if (arr[end] < arr[end - 1])
                    return end - 1;
                end--;
            } else if (arr[start] < arr[mid] || (arr[start] == arr[mid] && arr[mid] > arr[end]))
                start = mid + 1;
            else
                end = mid - 1;

        }
        return -1;
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
