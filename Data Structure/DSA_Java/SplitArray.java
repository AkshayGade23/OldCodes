public class SplitArray {
    public static void main(String[] args) {
        int nums[] = { 7, 2, 5, 10, 8 };
        int m = 2;
        System.out.println(splitArray(nums, m));
    }

    // Splite Array largest Sum
    static int splitArray(int[] nums, int m) {
        int start = 0;
        int end = 0;

        for (int i = 0; i < nums.length; i++) {
            if (start < nums[i])
                start = nums[i];
            end += nums[i];
        }
        // bianry search
        while (start < end) {

            // try middle as potential answer
            int mid = start + (end - start) / 2;

            // calculate how many pieces you can divide this in with this is max sum
            int sum = 0;
            int pieces = 1;

            for (int num : nums) {
                if (sum + num > mid) {
                    // you cannot add int this array, make new one
                    // say you add num in new array, then sum = num

                    sum = num;
                    // new array created
                    pieces++;
                } else
                    sum += num;
            }

            System.out.println("p " + pieces);
            if (pieces > m)
                start = mid + 1;
            else
                end = mid;
            System.out.println("s " + start + " end " + end);
        }
        return start;
    }

}
