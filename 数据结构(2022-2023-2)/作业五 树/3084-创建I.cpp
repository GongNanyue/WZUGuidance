CSTree createTree(char s[])
{
    CSTree T = NULL;
    CSTree p = NULL;
    CSTree q = NULL;
    int top = -1;
    int k = 0;
    int i = 0;
    CSTree stack[100];
    while(s[i])
    {
        switch(s[i])
        {
            case '(':
                top++;
                stack[top] = p;
                k = 1;
                break;
            case ')':
                top--;
                break;
            case ',':
                k = 2;
                break;
            default:
                p = (CSTree)malloc(sizeof(CSTNode));
                p->data = s[i];
                p->child = p->sibling = NULL;
                if(T == NULL)
                    T = p;
                else
                {
                    switch(k)
                    {
                        case 1:
                            stack[top]->child = p;
                            break;
                        case 2:
                            q = stack[top]->child;
                            while(q->sibling)
                                q = q->sibling;
                            q->sibling = p;
                            break;
                    }
                }
        }
        i++;
    }
    return T;
}
