#include <bits/stdc++.h>

using namespace std;
bool isPrimer(int y){
	if(y%4 == 0&& y %100 !=  0|| y %400 == 0){
		return true;
	}else{
		return false;
	}
}
int day[12]={0,31,28,31,30,31,30,31,31,30,31,30};
int main() {
	int n;
	scanf("%d",&n);
	while(n--){
		int y,m,d;
		scanf("%d/%d/%d",&y,&m,&d);
		int sum = 0;
		for(int i=0;i<m;i++){
			sum += day[i];
		}
		sum += d;
		if(m > 2&& isPrimer(y))++sum;
		printf("%d\n",sum);
	}

	return 0;
}
