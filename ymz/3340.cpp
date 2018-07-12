#include<bits/stdc++.h>
#define LL long long
using namespace std;
const int N=7;
int n,a[N][N],m,w[N],e[N],bw[N],be[N],flag;
string s[N],st;
map<string,int> mp;

void read(int &x){
	char ch=getchar();x=0;int w=1;
	for(;ch<'0'||ch>'9';ch=getchar()) if (ch=='-') w=-1;
	for(;ch>='0'&&ch<='9';ch=getchar()) x=(x<<3)+(x<<1)+ch-'0';
	x*=w;
} 

void dfss(int k){
	if (k>n){
		int p1=1,p2=1;
		while(p1<=n&&p2<=n){
			if (a[e[p2]][w[p1]]) p1++;
			 else p2++;
		}
		if (p1>n) flag=1;
		return;
	}
	for(int i=1;i<=n;i++)
	 if (!be[i]){
	 	be[i]=1;e[k]=i;
	 	dfss(k+1);
	 	be[i]=0;
	 	if (flag) return;
	 }
}

void dfs(int k){
	if (k>n){
		flag=0;
		dfss(1);
		if (!flag){
			printf("Yes\n");
			for(int i=1;i<=n;i++) cout<<s[w[i]]<<' ';
			exit(0);
		}
		return;
	}
	for(int i=1;i<=n;i++)
	 if (!bw[i]){
	 	bw[i]=1;w[k]=i;
	 	dfs(k+1);
	 	bw[i]=0;
	 }
}

int main(){
	std::ios::sync_with_stdio(false);
	cin>>n;
	for(int i=1;i<=n;i++) cin>>s[i];
	sort(s+1,s+1+n);
	for(int i=1;i<=n;i++) mp[s[i]]=i;
	for(int i=1;i<=n;i++){
		cin>>m;
		while(m--){
			cin>>st;
			a[i][mp[st]]=1;
		}
	}
	dfs(1);
	printf("No");
	return 0;
}
