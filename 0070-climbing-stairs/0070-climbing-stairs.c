int climbStairs(int n) {
    if(n==1) return 1;
    int *arr=(int*)malloc((n+1)*sizeof(int));
    arr[1]=1;
    arr[2]=2;
    for(int i=3;i<=n;i++){
        arr[i]=arr[i-1]+arr[i-2];
    }
    return arr[n];
}