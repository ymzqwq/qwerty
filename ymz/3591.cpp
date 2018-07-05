#include<bits/stdc++.h>
#define LL long long
using namespace std;
const int N=201;
char c[N],s[N];
int f[N][N],n;

void read(int &x){
	char ch=getchar();x=0;int w=1;
	for(;ch<'0'||ch>'9';ch=getchar()) if (ch=='-') w=-1;
	for(;ch>='0'&&ch<='9';ch=getchar()) x=(x<<3)+(x<<1)+ch-'0';
	x*=w;
}

int pd(char a,char b){
	if (a=='('&&b==')') return 1;
	if (a=='['&&b==']') return 1;
	return 0;
}

void dfs(int L,int r){
	if (f[L][r]!=-1) return;
	if (L==r) { f[L][r]=1;return; }
	if (r-L==1){
		if (pd(c[L],c[r])) f[L][r]=0;
		 else f[L][r]=2;
		return; 
	}
	f[L][r]=n+1;
	if (pd(c[L],c[r])){
		dfs(L+1,r-1);
		f[L][r]=min(f[L][r],f[L+1][r-1]);
	}
	for(int i=L;i<r;i++){
		dfs(L,i);dfs(i+1,r);
		f[L][r]=min(f[L][i]+f[i+1][r],f[L][r]);
	}
}

int main(){
	memset(f,-1,sizeof f);
	scanf("%s",c);
	n=strlen(c)-1;
	dfs(0,n);
	cout<<f[0][n];
	return 0;
}
