typedef struct {
    int stackIn[100];
    int stackOut[100];

    int topIn;
    int topOut;
} MyQueue;


MyQueue* myQueueCreate() {
    MyQueue* q = malloc(sizeof(MyQueue));

    q->topIn = -1;
    q->topOut = -1;

    return q;
}


void myQueuePush(MyQueue* obj, int x) {
    obj->stackIn[++obj->topIn] = x;
}


int myQueuePop(MyQueue* obj) {

    // Move elements only when stackOut is empty
    if (obj->topOut == -1) {
        while (obj->topIn >= 0) {
            obj->stackOut[++obj->topOut] =
                obj->stackIn[obj->topIn--];
        }
    }

    return obj->stackOut[obj->topOut--];
}


int myQueuePeek(MyQueue* obj) {

    if (obj->topOut == -1) {
        while (obj->topIn >= 0) {
            obj->stackOut[++obj->topOut] =
                obj->stackIn[obj->topIn--];
        }
    }

    return obj->stackOut[obj->topOut];
}


bool myQueueEmpty(MyQueue* obj) {
    return obj->topIn == -1 && obj->topOut == -1;
}


void myQueueFree(MyQueue* obj) {
    free(obj);
}