
typedef int ElementType;

typedef struct {
  ElementType *array; //存放数据的指针
  int length;            //已有数据个数
  int capacity;        //容量
} SeqList;

SeqList *createList(int capacity) {
  SeqList *SL = (SeqList *) malloc(sizeof(SeqList));
  SL->array = (ElementType *) malloc(capacity * sizeof(ElementType));
  SL->capacity = capacity;
  SL->length = 0;
  return SL;
}

int getLength(SeqList *L){
  return  L->length;
}

int isEmpty(SeqList *L) {
  return L->length == 0;
}

void printList(SeqList *L) {
  for (int i = 0; i < L->length; ++i) {
    printf("%d ", *(L->array + i));
  }
  printf("\n");
}

int insertList(SeqList *L, int i, ElementType x) {
  if (L->length >= L->capacity || i < 1 || i > L->length + 1)return 0;
  for (ElementType *p = L->array + L->length; p != L->array + i - 1; --p) {
    *p = *(p - 1);
  }
  *(L->array + i - 1) = x;
  ++(L->length);
  return 1;
}

int find(SeqList *L, ElementType x) {
  for (int i = 0; i < L->length; ++i)
    if (L->array[i] == x)return i + 1;
  return -1;
}

int getElement(SeqList *L, int i, ElementType *p) {
  if (i < 1 || i > L->length)return 0;
  *p = L->array[i - 1];
  return 1;

}
int delElement(SeqList *L, int i, ElementType *p) {
  if (i < 1 || i > L->length)return 0;
  *p = L->array[i - 1];
  for (int j = i; j < L->length; ++j)
    L->array[j - 1] = L->array[j];
  --L->length;
  return 1;

}

int myFind(SeqList *L, int pos, ElementType x) {
  //pos是偏移量 从>=pos开始查找
  if (pos < 0 || pos >= L->length)return -1;
  for (; pos < L->length; ++pos)
    if (L->array[pos] == x)return pos;
  return -1;
}//返回偏移量

void delRepeatElement(SeqList *L) {
  for (int i = 0; i < L->length; ++i) {
    int var = L->array[i], delPos = myFind(L, i + 1, var), buff;
    while (delPos != -1) {
      delElement(L, delPos + 1, &buff);
      delPos = myFind(L, i + 1, var);
    }
  }
}
void clearList(SeqList *L) {
  L->length = 0;
}

void mergeList(SeqList *LA, SeqList *LB, SeqList *LC) {
  int i = 0, j = 0, k = 0;
  for (; i < LA->length && j < LB->length;) {
    if (LA->array[i] < LB->array[j])
      LC->array[k++] = LA->array[i++];
    else
      LC->array[k++] = LB->array[j++];
  }
  if (i == LA->length)
    memcpy(&LC->array[k], &LB->array[j], sizeof(int) * (LB->length - j));
  else
    memcpy(&LC->array[k], &LA->array[i], sizeof(int) * (LA->length - i));
  LC->length = LA->length+LB->length;
}

void destroyList(SeqList *L){
  free(L->array);
  free(L);
}
