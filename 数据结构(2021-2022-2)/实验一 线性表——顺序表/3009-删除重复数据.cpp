int myFind(SeqList *L, int pos, ElementType x) {
  //pos是偏移量 0坐标开始 从>=pos开始查找
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
