typedef struct {
    int data[100];
    int front;
    int rear;
} Queue;

typedef struct {
    Queue *q1;
    Queue *q2;
} MyStack;


void enqueue(Queue *q, int x) {
    q->data[q->rear++] = x;
}

int dequeue(Queue *q) {
    return q->data[q->front++];
}

bool isEmpty(Queue *q) {
    return q->front == q->rear;
}


MyStack* myStackCreate() {
    MyStack* obj = malloc(sizeof(MyStack));

    obj->q1 = malloc(sizeof(Queue));
    obj->q2 = malloc(sizeof(Queue));

    obj->q1->front = 0;
    obj->q1->rear = 0;

    obj->q2->front = 0;
    obj->q2->rear = 0;

    return obj;
}


void myStackPush(MyStack* obj, int x) {

    // Put new element into q2
    enqueue(obj->q2, x);

    // Move all elements from q1 to q2
    while (!isEmpty(obj->q1)) {
        enqueue(obj->q2, dequeue(obj->q1));
    }

    // q1 is now empty, so reset it
    obj->q1->front = 0;
    obj->q1->rear = 0;

    // Swap q1 and q2
    Queue *temp = obj->q1;
    obj->q1 = obj->q2;
    obj->q2 = temp;
}


int myStackPop(MyStack* obj) {
    return dequeue(obj->q1);
}


int myStackTop(MyStack* obj) {
    return obj->q1->data[obj->q1->front];
}


bool myStackEmpty(MyStack* obj) {
    return isEmpty(obj->q1);
}


void myStackFree(MyStack* obj) {
    free(obj->q1);
    free(obj->q2);
    free(obj);
}