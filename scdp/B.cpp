#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
const int N=20;
int T,n,d[N],a[N],f[1<<N],pre[1<<N],t[1<<N];
char c[N][111];

void read(int &x){scanf("%d",&x);
	/*char ch=getchar();x=0;
	for(;ch<'0'||ch>'9';ch=getchar());
	for(;ch>='0'&&ch<='9';ch=getchar()) x=(x<<3)+(x<<1)+ch-'0';*/
}

/*void findpre(int x){
	if (!x) return;
	findpre(x^(1<<pre[x]));
	printf("%s\n",c[pre[x]]);
}*/

int main(){
	read(T);
	while(T--){
		read(n);
		memset(t,0,sizeof t);
		memset(pre,0,sizeof pre);
		for(int i=0;i<n;i++){
			scanf("%s",c[i]);
			read(d[i]);read(a[i]);
			t[(1<<n)-1]+=a[i];
		}
		memset(f,0x3f,sizeof f);
		f[(1<<n)-1]=0;
		for(int i=(1<<n)-2;i>=0;i--)
		 for(int j=0;j<n;j++)
		  if ((i&(1<<j))==0){
		  	t[i]=t[i|(1<<j)]-a[j];
		  	if (f[i|(1<<j)]+max(0,t[i|(1<<j)]-d[j])<f[i]){
		  		f[i]=f[i|(1<<j)]+max(0,t[i|(1<<j)]-d[j]);
		  		pre[i]=j;
		  	}
		  }
		printf("%d\n",f[0]);
		for(int i=0;i!=(1<<n)-1;i^=(1<<pre[i])) printf("%s\n",c[pre[i]]);
	}
	return 0;
}
