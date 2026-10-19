class Solution {
    public int[] nextGreaterElement(int[] nums1, int[] nums2) {
        Stack<Integer> HelperStack = new Stack<>();
        int nextGreater[] = new int[nums2.length]; 
        for(int i=nums2.length-1; i>=0; i--){
            int element = nums2[i];
            if(HelperStack.isEmpty()){
                nextGreater[i]=-1;
                HelperStack.push(element);
                continue;
            }
            if(!HelperStack.isEmpty() && HelperStack.peek()>element){
                nextGreater[i]=HelperStack.peek();
                HelperStack.push(element);
                continue;
            }
            while(!HelperStack.isEmpty() && HelperStack.peek()<=element){
                HelperStack.pop();
            }
            if(HelperStack.isEmpty()){
                nextGreater[i]=-1;
            }
            if(!HelperStack.isEmpty()){
                nextGreater[i]=HelperStack.peek();
            }
            HelperStack.push(element);
        }
        int result[] = new int[nums1.length];
        for(int i=0;i<nums1.length;i++){
            for(int j=0;j<nums2.length;j++){
                if(nums1[i]==nums2[j]){
                    result[i]=nextGreater[j];
                    break;
                }
            }
        } 
        return result;   
    }
}