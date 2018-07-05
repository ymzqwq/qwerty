#include<bits/stdc++.h>
#define LL long long
using namespace std;
const int N=100001;
int n,ans;
char c[N],d[N];

void read(int &x){
	char ch=getchar();x=0;int w=1;
	for(;ch<'0'||ch>'9';ch=getchar()) if (ch=='-') w=-1;
	for(;ch>='0'&&ch<='9';ch=getchar()) x=(x<<3)+(x<<1)+ch-'0';
	x*=w;
}

int main(){
	read(n);
	for(int i=1;i<=n;i++){
		scanf("%s",c);
		int sum0=0,sum1=0,ot=0;
		for(int j=0;j<strlen(c);j++)
		 if (c[j]=='0') ++sum0;
		  else if (c[j]=='1') ++sum1;
		   else ++ot;
		if (ot==0&&sum0==1&&sum1==0){
			printf("0");return 0;
		}
		if (ot==0&&sum1==1) ans+=sum0;
		 else strcpy(d,c);
	}
	if (strlen(d)) printf("%s",d); else printf("1");
	for(int i=1;i<=ans;i++) printf("0");
	return 0;
}
