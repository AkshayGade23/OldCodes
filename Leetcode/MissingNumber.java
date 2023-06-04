import java.*;
// https://leetcode.com/problems/missing-number/

public class MissingNumber {
    public static int missingNumber(int[] nums) {
        int i = 0;
        while (i < nums.length) {
            if (nums[i] < nums.length && nums[i] != i) {
                int temp = nums[nums[i]];
                nums[nums[i]] = nums[i];
                nums[i] = temp;

            } else
                i++;
        }

        for (int j = 0; j < nums.length; j++) {
            if (nums[j] != j)
                return j;
        }
        return nums.length;
    }

    public static void main(String[] args) {
        int[] nums = { 9, 6, 4, 2, 3, 5, 7, 0, 1 };
        System.out.println(missingNumber(nums));
    }
}