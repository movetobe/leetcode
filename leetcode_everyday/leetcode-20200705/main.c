/**
 * repeat number in the array
 * https://leetcode-cn.com/problems/shu-zu-zhong-zhong-fu-de-shu-zi-lcof/
 */
#include <stdio.h>

int find_repeat_number(int *nums, int numsSize)
{
    int i = 0;
    int exchange = 0;

    for (i = 0; i < numsSize; i++) {
        while (nums[i] != i) {
            if (nums[nums[i]] == nums[i]) {
                return nums[i];
            }
            exchange = nums[nums[i]];
            nums[nums[i]] = nums[i];
            nums[i] = exchange;
        }
    }
}

int main(void)
{

}