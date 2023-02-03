SeqQueue *createQueue(int capacity) {
  SeqQueue *queue = (SeqQueue *) malloc(sizeof(SeqQueue));
  queue->array = (ElementType *) malloc(capacity * sizeof(ElementType));
  queue->capacity = capacity;
  queue->front = queue->rear = 0;
  queue->length = 0;
  return queue;
}
