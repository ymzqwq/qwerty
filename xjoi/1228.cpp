#include<bits/stdc++.h>
#define LL long long
using namespace std;
const int N=13;
int n,bl[N],be[N<<1],bt[N<<1],ans;

void read(int &x){
	char ch=getchar();x=0;int w=1;
	for(;ch<'0'||ch>'9';ch=getchar()) if (ch=='-') w=-1;
	for(;ch>='0'&&ch<='9';ch=getchar()) x=(x<<3)+(x<<1)+ch-'0';
	x*=w;
}

void dfs(int k){
	if (k>n) { ans++;return; }
	for(int i=1;i<=n;i++)
	 if (bl[i]==0&&be[k-i+n]==0&&bt[k+i]==0){
	 	bl[i]=1;be[k-i+n]=1;bt[k+i]=1;
	 	dfs(k+1);
	 	bl[i]=0;be[k-i+n]=0;bt[k+i]=0;
	 }
}

int main(){
	cin>>n;
	dfs(1);
	cout<<ans;
	return 0;
}
