int trap(int* height, int heightSize) {
    int n=heightSize;
    int *Lmax=(int*)malloc(n*sizeof(int));
    int *Rmax=(int*)malloc(n*sizeof(int));
    Lmax[0]=height[0];
    for(int i=1;i<n;i++){
        if(height[i]<Lmax[i-1]) Lmax[i]=Lmax[i-1];
        else Lmax[i]=height[i];
    }
    Rmax[n-1]=height[n-1];
    for(int i=n-2;i>=0;i--){
        if(height[i]<Rmax[i+1]) Rmax[i]=Rmax[i+1];
        else Rmax[i]=height[i];
    }
    int contain=0;
    for(int i=0;i<n;i++){
        int waterStore=0;
        if(Lmax[i]<Rmax[i]) waterStore=Lmax[i]-height[i];
        else waterStore=Rmax[i]-height[i];
        contain=contain+waterStore;
    }
    return contain;
}