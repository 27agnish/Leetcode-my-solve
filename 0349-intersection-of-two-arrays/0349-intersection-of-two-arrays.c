/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* intersection(int* nums1, int nums1Size, int* nums2, int nums2Size, int* returnSize) {
    int Maxsize=((nums1Size<nums2Size)?nums1Size:nums2Size);
    int *temp = (int*)malloc(Maxsize*(sizeof(int)));
    int k=0;
    for(int i=0;i<nums1Size;i++){
        int count=0;
        for(int j=0;j<nums2Size;j++){
            if(nums1[i]==nums2[j]){
                count=1;
                break;
            }
        }
        if(count){
            int dup=0;
            for(int x=0;x<k;x++){
                if(temp[x]==nums1[i]){
                    dup=1;
                    break;
                }
            }
            if(!dup){
                temp[k++]=nums1[i];
            }
        }
    }
    *returnSize=k;
    return temp; 
}