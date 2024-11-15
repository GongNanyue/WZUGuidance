#include <stdio.h>
#include <stdlib.h>
int cmp(const void *a,const void *b) 
{
	return *(int*)b-*(int*)a;
}
int main()
{
    int n,m;
    while (scanf("%d %d",&n,&m)!=EOF)
    {
        int arr[20]={0},a[190]={0},k=0;
        for (int i = 0; i < n; i++)
        {
            scanf("%d",&arr[i]);
        }
        for (int i = 0; i < n; i++)
        {
            for (int j = i+1; j < n; j++)
            {
                a[k]=arr[i]+arr[j];
                k++;
            }
        }
        qsort(a,190,sizeof(int),cmp);
        for (int i = 0; i < m; i++)
        {
            printf("%d ",a[i]);
        }
        printf("\n");
    }    
    return 0;
}
