class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        vector<int> left(n,0);
        vector<int> right(n,0);
        stack<int> s;

        for(int i=0;i<n;i++){
            while(!s.empty() && heights[s.top()]>=heights[i]){
                s.pop();
            }
            if(s.empty()) left[i]=-1;
            else left[i]=s.top();
            s.push(i);
        }

        while(!s.empty()) s.pop();

        for(int i=n-1;i>=0;i--){
            while(!s.empty() && heights[s.top()]>=heights[i]){
                s.pop();
            }
            if(s.empty()) right[i]=n;
            else right[i]=s.top();
            s.push(i);
        }
        int max=0;
        for(int i=0;i<n;i++){
            int curr=0;
            int bredth=right[i]-left[i]-1;
            curr=heights[i]*bredth;
            if(max<curr) max=curr;
        }
        return max;
    }
};