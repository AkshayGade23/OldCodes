public class FindDuplicate {
    public static int findDuplicate(int[] nums) {
        int i = 0;
        while (i < nums.length) {
            if ( nums[i] != nums[nums[i]-1]) {
                int temp = nums[nums[i]-1];
                nums[nums[i]-1] = nums[i];
                nums[i] = temp;

            } else
                i++;
        }
        return nums[nums.length-1];
    }

    public static void main(String[] arg) {
        int[] nums = { 1, 3, 4, 2, 2 };
     
        System.out.println(findDuplicate(nums));
    }
}
