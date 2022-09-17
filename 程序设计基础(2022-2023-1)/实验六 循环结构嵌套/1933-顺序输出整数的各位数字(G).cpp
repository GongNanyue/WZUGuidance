#include <bits/stdc++.h>

using namespace std;
int a[100];

int main() {
	int n, val;
	scanf("%d", &n);
	while (n--) {
		int i = 0;
		scanf("%d", &val);
		if(val==0){
			printf("0 \n");
			continue;
		}
		while (val) {
			a[i] = val % 10;
			i++;
			val = val / 10;
		}
		for (int j = i - 1; j >= 0; j--) {
			printf("%d ",a[j]);
		}
		
		printf("\n");
	}
	return 0;
}
