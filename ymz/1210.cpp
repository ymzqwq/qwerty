#include<bits/stdc++.h>
#define LL long long
using namespace std;
const int N=31;
int n,c[N][N];

void read(int &x){
	char ch=getchar();x=0;int w=1;
	for(;ch<'0'||ch>'9';ch=getchar()) if (ch=='-') w=-1;
	for(;ch>='0'&&ch<='9';ch=getchar()) x=(x<<3)+(x<<1)+ch-'0';
	x*=w;
}

int main(){
	read(n);
	c[0][0]=1;
	for(int i=1;i<N;i++)
	 for(int j=1;j<N;j++)
	  c[i][j]=c[i-1][j-1]+c[i-1][j];
	if (n==0) { printf("(a+b)^0 = 1");return 0; }
	//if (n==1) { printf("(a+b) = a + b");return 0; }
	printf("(a+b)^%d = ",n);
	for(int i=n;i>=0;i--){
		int j=n-i;
		if (c[n+1][i+1]>1) printf("%d*",c[n+1][i+1]);
		if (i>0) printf("a");
		if (i>1) printf("^%d",i);
		if (i>0&&j>0) printf("*");
		if (j>0) printf("b");
		if (j>1) printf("^%d",j);
		if (i==0) break;
		printf(" + ");
	}
	return 0;
}
