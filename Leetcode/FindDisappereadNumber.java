import java.*;
import java.util.*;

class FindDisappereadNumber {
    public static void swap(int[] arr, int index1, int index2) {
        int temp = arr[index2];
        arr[index2] = arr[index1];
        arr[index1] = temp;
    }

    public static List<Integer> findDisappearedNumbers(int[] nums) {
        List<Integer> disappearNums = new ArrayList<Integer>();
        int i = 0;
        while (i < nums.length) {
            int correct = nums[i] - 1;
            if (nums[i] != nums[correct]) {
                swap(nums, i, correct);
            } else
                i++;
        }

        for (int j = 0; j < nums.length; j++) {
                if (nums[j] != j + 1)
                    disappearNums.add(j + 1);
        }
        return disappearNums;
    }

    public static void main(String[] args) {
        int[] nums = { 1,2,2,4};
        System.out.println(findDisappearedNumbers(nums));
    }
}