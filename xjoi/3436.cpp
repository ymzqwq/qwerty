#include<bits/stdc++.h>
#define LL long long
using namespace std;
const int N=41;
int n,la[N],ans;
char c[N][N],ch;

void read(int &x){
	char ch=getchar();x=0;int w=1;
	for(;ch<'0'||ch>'9';ch=getchar()) if (ch=='-') w=-1;
	for(;ch>='0'&&ch<='9';ch=getchar()) x=(x<<3)+(x<<1)+ch-'0';
	x*=w;
}

int main(){
	read(n);
	for(int i=1;i<=n;i++){
		scanf("%s",c[i]+1);
		for(int j=n;j;j--)
		 if (c[i][j]=='1'){
		 	la[i]=j;break;
		 }
	}
	for(int i=1;i<=n;i++){
		int j;
		for(j=i;j<=n;j++)
		 if (la[j]<=i) break;
		ans+=j-i;
		for(;j>i;j--){
			for(int k=1;k<=n;k++) ch=c[j][k],c[j][k]=c[j-1][k],c[j-1][k]=ch;
			la[j]^=la[j-1]^=la[j]^=la[j-1];
		}
	}
	cout<<ans;
	return 0;
}
