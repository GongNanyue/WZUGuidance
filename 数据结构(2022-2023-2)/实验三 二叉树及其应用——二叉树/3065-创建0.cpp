BTree createTree(char s[]) {
  const int N = 10000;
  BTNode *nodes[strlen(s)], *node;
  int layer = 0;
  int k = 0;//k == 1 左子树 k == 2右子树
  for (int i = 0; s[i]; ++i) {
    if (isalpha(s[i])) {
      node = (BTNode *) malloc(sizeof(BTNode));
      node->data = s[i];
      node->lchild = node->rchild = NULL;
      if (k == 1) {
        nodes[layer]->lchild = node;
      } else if (k == 2) {
        nodes[layer]->rchild = node;
      }
    } else if (s[i] == '(') {
      layer++;
      nodes[layer] = node;
      k = 1;
    } else if (s[i] == ',') {
      k = 2;
    } else if (s[i] == ')') {
      layer--;
    }
  }
  if(!k)return node;
  return nodes[1];
}
