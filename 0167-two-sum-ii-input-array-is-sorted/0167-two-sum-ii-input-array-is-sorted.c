/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* twoSum(int* numbers, int numbersSize, int target, int* returnSize) {
    int left = 0;
    int right = numbersSize-1;
    int sum = 0;
    int *temp = (int*)malloc(2*sizeof(int));
    while(left<right){
        sum = numbers[left]+numbers[right];
        if(sum==target){
            temp[0]=left+1;
            temp[1]=right+1;
            *returnSize=2;
            return temp;
        }
        if(sum>target) right--;
        if(sum<target) left++;
    }
    *returnSize=0;
    return NULL;
}