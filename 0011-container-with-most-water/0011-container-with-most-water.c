int maxArea(int* height, int heightSize) {
    int lp=0;
    int rp=heightSize-1;
    int maxContain = 0;
    while(lp<rp){
        int width=rp-lp;
        int depth=0;
        if(height[lp]<height[rp]) depth = height[lp];
        else if(height[lp]>height[rp]) depth = height[rp];
        else depth = height[lp];
        int contain = width*depth;
        if(maxContain<contain) maxContain=contain;
        if(height[lp]>height[rp]) rp--;
        else lp++; 
    }
    return maxContain;
}