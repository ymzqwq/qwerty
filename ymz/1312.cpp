#include<bits/stdc++.h>
using namespace std;
const int N=30001;
const int M=100001;
int x,a[N],b[N];
char s[M];

void read(int &x){
	char ch=getchar();x=0;
	for(;ch<'0'||ch>'9';ch=getchar());
	for(;ch>='0'&&ch<='9';ch=getchar()) x=(x<<3)+(x<<1)+ch-'0';
}

int main(){
	fgets(s,M,stdin);
	int i=0;
	while(i<strlen(s)){
		x=0;
		for(;(s[i]<'0'||s[i]>'9')&&i<strlen(s);i++);
		for(;s[i]>='0'&&s[i]<='9'&&i<strlen(s);i++)
		 x=(x<<3)+(x<<1)+s[i]-'0';
		a[x]=1;
	}
	fgets(s,M,stdin);
	i=0;
	while(i<strlen(s)){
		x=0;
		for(;(s[i]<'0'||s[i]>'9')&&i<strlen(s);i++);
		for(;s[i]>='0'&&s[i]<='9'&&i<strlen(s);i++)
		 x=(x<<3)+(x<<1)+s[i]-'0';
		b[x]=1;
	}
	for(int i=1;i<N;i++) if (a[i]||b[i]) printf("%d ",i);
	printf("\n");
	for(int i=1;i<N;i++) if (a[i]&&b[i]==0) printf("%d ",i);
	printf("\n");
	for(int i=1;i<N;i++) if (a[i]&&b[i]) printf("%d ",i);
	printf("\n");
	for(int i=1;i<N;i++) if (a[i]^b[i]) printf("%d ",i);
	printf("\n");
	return 0;
}
