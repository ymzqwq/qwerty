#include<bits/stdc++.h>
#define LL long long
using namespace std;
const int N=1001;
int T,s,t,f[N];
vector<int> a[N];

void read(int &x){
	char ch=getchar();x=0;int w=1;
	for(;ch<'0'||ch>'9';ch=getchar()) if (ch=='-') w=-1;
	for(;ch>='0'&&ch<='9';ch=getchar()) x=(x<<3)+(x<<1)+ch-'0';
	x*=w;
}

int main(){
	read(T);
	for(int i=4;i<N;i++){
		int x=i;
		for(int j=2;j<=i/2;j++)
		 if (x%j==0){
		 	a[i].push_back(j);
		 	while(x%j==0) x/=j;
		 }
	}
	for(int o=1;o<=T;o++){
		read(s);read(t);
		memset(f,0x3f,sizeof f);
		f[s]=0;
		for(int i=s;i<t;i++)
		 for(int j=0;j<a[i].size();j++){
		 	if (a[i][j]+i>t) break;
		 	f[i+a[i][j]]=min(f[i+a[i][j]],f[i]+1);
		 }
		if (f[t]>N) f[t]=-1;
		printf("Case %d: %d\n",o,f[t]);
	}
	return 0;
}
