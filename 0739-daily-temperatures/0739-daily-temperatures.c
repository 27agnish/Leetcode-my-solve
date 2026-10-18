/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* dailyTemperatures(int* temperatures, int temperaturesSize, int* returnSize) {
    int* ans = (int*)calloc(temperaturesSize, sizeof(int));

    int* stack = (int*)malloc(temperaturesSize * sizeof(int));

    *returnSize = temperaturesSize;

    int top = -1;

    for (int i = 0; i < temperaturesSize; i++) {

        while (top != -1 &&

               temperatures[i] > temperatures[stack[top]]) {

            int prev = stack[top--];

            ans[prev] = i - prev;

        }

        stack[++top] = i;

    }

    free(stack);

    return ans;
    
}