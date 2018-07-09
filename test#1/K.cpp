#include<bits/stdc++.h>
using namespace std;
const int N=111;
const int M=26;
int n,a[M][M],rd[M],len[N],b[M],ans[M],flag;
char c[N][N];

inline void read(int &x){
	char ch=getchar();x=0;
	for(;ch<'0'||ch>'9';ch=getchar());
	for(;ch>='0'&&ch<='9';ch=getchar()) x=(x<<3)+(x<<1)+ch-'0';
}

void make(int x,int y){
	for(int i=1;i<=min(len[x],len[y]);i++)
	 if (c[x][i]!=c[y][i]){
	 	a[c[x][i]-'a'][c[y][i]-'a']=1;
	 	rd[c[y][i]-'a']++;
	 	return;
	 }
	if (len[x]>len[y]) flag=1;
}

int main(){
	read(n);
	for(int i=1;i<=n;i++) gets(c[i]+1),len[i]=strlen(c[i]+1);
	for(int i=1;i<n;i++) make(i,i+1);
	if (flag){ printf("Impossible");return 0; }
	for(int i=0;i<M;i++){
		int k=-1;
		for(int j=0;j<M;j++)
		 if (b[j]==0&&rd[j]==0){
		 	k=j;break;
		 }
		if (k==-1){ printf("Impossible");return 0; }
		ans[i]=k;b[k]=1;
		for(int j=0;j<M;j++)
		 if (b[j]==0&&a[k][j]){
		 	a[k][j]=0;
		 	rd[j]--;
		 }
	}
	for(int i=0;i<M;i++) printf("%c",ans[i]+'a');
	return 0;
}
