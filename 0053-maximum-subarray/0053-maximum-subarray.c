int maxSubArray(int* nums, int numsSize) {
    int maxSum=INT_MIN;
    int currSum=0;
    for(int i=0;i<numsSize;i++){
        currSum=currSum+nums[i];
        if(maxSum<currSum) maxSum=currSum;
        if(currSum<0) currSum=0;
    }
    return maxSum;
}