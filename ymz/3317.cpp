#include<bits/stdc++.h>
#define LL long long
using namespace std;
const int N=71;
int n,ans,L,fr;
char c[N],d[1001][N];

void read(int &x){
	char ch=getchar();x=0;int w=1;
	for(;ch<'0'||ch>'9';ch=getchar()) if (ch=='-') w=-1;
	for(;ch>='0'&&ch<='9';ch=getchar()) x=(x<<3)+(x<<1)+ch-'0';
	x*=w;
}

int main(){
	L=1;strcpy(d[1],"http://www.hzxjhs.com/");
	while(scanf("%s",c)>0){
		if (c[0]=='V'){
			L++;fr=L;
			scanf("%s",d[L]);
			printf("%s\n",d[L]);
		}
		if (c[0]=='B'){
			if (L==1){
				printf("Ignored\n");
				continue;
			}
			L--;printf("%s\n",d[L]);
		}
		if (c[0]=='F'){
			if (L==fr){
				printf("Ignored\n");
				continue;
			}
			L++;printf("%s\n",d[L]);
		}
	}
	return 0;
}
