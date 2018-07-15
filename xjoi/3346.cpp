#include<bits/stdc++.h>
#define LL long long
using namespace std;
const int N=301;
const int p1=3e7+7;
const int p2=2e7+19;
const int p3=1e7+11;
LL n,a[6][N],x,flag;
bool tot1[p1<<1],tot2[p2<<1],tot3[p3<<1];

void read(LL &x){
	char ch=getchar();x=0;int w=1;
	for(;ch<'0'||ch>'9';ch=getchar()) if (ch=='-') w=-1;
	for(;ch>='0'&&ch<='9';ch=getchar()) x=(x<<3)+(x<<1)+ch-'0';
	x*=w;
}

int main(){
	read(n);
	for(int i=1;i<=5;i++)
	 for(int j=1;j<=n;j++)
	  read(a[i][j]);
	for(int i=1;i<=n;i++)
	 for(int j=1;j<=n;j++){
	 	x=a[1][i]+a[2][j];
	 	tot1[x%p1+p1]=1;
	 	tot2[x%p2+p2]=1;
	 	tot3[x%p3+p3]=1;
	 }
	for(int i=1;i<=n;i++)
	 for(int j=1;j<=n;j++)
	  for(int k=1;k<=n;k++){
	  	x=-a[3][i]-a[4][j]-a[5][k];
	  	if (tot1[x%p1+p1]&&tot2[x%p2+p2]&&tot3[x%p3+p3]) flag=1;
	  }
	if (flag) printf("Yes");else printf("No");
	return 0;
}
