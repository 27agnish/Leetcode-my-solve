int majorityElement(int* nums, int numsSize) {
    int n = numsSize;
    int candidate=0;
    int vote=0;
    for(int i=0;i<n;i++){
        if(vote==0){
            candidate=nums[i];
        }
        if(nums[i]==candidate){
            vote++;
        }
        else{
            vote--;
        }
    }
    return candidate;
}