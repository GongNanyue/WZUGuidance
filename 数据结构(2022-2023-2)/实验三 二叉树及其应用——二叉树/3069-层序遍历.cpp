void layerOrder(BTree bt){
  if (!bt) return;
  queue<Node*> q;
  q.push(bt);
  while (!q.empty()){
    putchar(q.front()->data );
    if(q.front()->lchild)
      q.push(q.front()->lchild);
    if(q.front()->rchild)
      q.push(q.front()->rchild);
    q.pop();
  }
}
