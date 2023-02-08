
typedef int ElementType;
typedef struct {
  //[front,rear)
  ElementType *array;
  int front;      //队首位置
  int rear;       //尾指下一个位置
  int length;     //长度
  int capacity;   //总容量
} SeqQueue;

void destroyQueue(SeqQueue *Q) {
  free(Q->array);
  free(Q);
}

void clearQueue(SeqQueue *Q) {
  Q->front = Q->rear = 0;
  Q->length = 0;
}

ElementType front(SeqQueue *Q) {
  return Q->array[Q->front];
}

int empty(SeqQueue *Q) {
  return Q->length == 0;
}

SeqQueue *createQueue(int capacity) {
  SeqQueue *queue = (SeqQueue *) malloc(sizeof(SeqQueue));
  queue->array = (ElementType *) malloc(capacity * sizeof(ElementType));
  queue->capacity = capacity;
  queue->front = queue->rear = 0;
  queue->length = 0;
  return queue;
}

int full(SeqQueue *Q) {
  return Q->length == Q->capacity;
}

int push(SeqQueue *Q, ElementType x) {
  if (full(Q)) return 0;
  Q->array[Q->rear] = x;
  Q->rear = (Q->rear + 1) % Q->capacity;
  ++Q->length;
  return 1;
}

int pop(SeqQueue *Q, ElementType *x) {
  if(empty(Q))return 0;
  *x = Q->array[Q->front];
  Q->front =(Q->front + 1) % Q->capacity;
  --Q->length;
  return 1;
}
