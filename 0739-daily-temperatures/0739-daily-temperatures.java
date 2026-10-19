class Solution {
    public int[] dailyTemperatures(int[] temperatures) {
        Stack<Integer> HelperStack = new Stack<>();
        int answer[] = new int[temperatures.length];
        for(int idx = temperatures.length-1; idx>=0; idx--){
            while(!HelperStack.isEmpty() && temperatures[idx]>=temperatures[HelperStack.peek()]){
                HelperStack.pop();
            }
            if(!HelperStack.isEmpty()){
                answer[idx] = HelperStack.peek()-idx;
            }
            HelperStack.push(idx);
        } 
        return answer; 
    }
}