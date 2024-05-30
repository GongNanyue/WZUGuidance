void printList(PolyList L) {
  if (!L->next) {
    puts("0");
    return;
  }
  char res[100000], tmp[10000];
  memset(res, 0, sizeof res);
  for (PolyNode *np = L->next; np; np = np->next) {
    memset(tmp, 0, sizeof tmp);
    if (np->coef == 1) {
      strcpy(tmp, "+");
      if (np->exp == 0)
        strcat(tmp, "1");
    } else if (np->coef == -1) {
      strcpy(tmp, "-");
      if(np->exp == 0)
        strcat(tmp,"1");
    } else if (np->coef > 0)
      sprintf(tmp, "+%d", np->coef);
    else
      sprintf(tmp, "%d", np->coef);
    strcat(res, tmp);

    memset(tmp, 0, sizeof tmp);
    if (np->exp == 0) {}
    else if (np->exp == 1)
      sprintf(tmp, "x");
    else
      sprintf(tmp, "x^%d", np->exp);
    strcat(res, tmp);
  }
  if (res[0] == '+' || res[0] == '-' && res[1] == '0') printf("%s\n", res + 1);
  else printf("%s\n", res);
}
