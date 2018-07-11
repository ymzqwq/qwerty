#include<bits/stdc++.h>
using namespace std;
const int N=101;
int n,x;
char c[N];

inline void read(int &x){
	char ch=getchar();x=0;int w=1;
	for(;ch<'0'||ch>'9';ch=getchar()) if (ch=='-') w=-1;
	for(;ch>='0'&&ch<='9';ch=getchar()) x=(x<<3)+(x<<1)+ch-'0';
	x*=w;
}

int main(){
	scanf("%s",c+1);
	n=strlen(c+1);
	for(int i=1;i<=n;i++) c[i]-='0';
	for(int i=1;i<=n;i++)
	 if (c[i]==0||c[i]==8){
	 	printf("YES\n%d",c[i]);
	 	return 0;
	 }
	for(int i=1;i<=n-1;i++)
	 for(int j=i+1;j<=n;j++)
	  if ((c[i]*10+c[j])%8==0){
	  	printf("YES\n%d%d",c[i],c[j]);
	  	return 0;
	  }
	for(int i=1;i<=n-2;i++)
	 for(int j=i+1;j<=n-1;j++)
	  for(int k=j+1;k<=n;k++)
	   if ((c[i]*100+c[j]*10+c[k])%8==0){
	  	 printf("YES\n%d%d%d",c[i],c[j],c[k]);
	  	 return 0;
	   }
	printf("NO");
	return 0;
}
