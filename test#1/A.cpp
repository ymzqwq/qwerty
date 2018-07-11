#include<bits/stdc++.h>
using namespace std;
const int N=10001;
const int M=10005;
int n,a[N],c[N],pm[N],b[M],L,num[N],dc[N],mp[N],cur;

inline void read(int &x){
	char ch=getchar();x=0;int w=1;
	for(;ch<'0'||ch>'9';ch=getchar()) if (ch=='-') w=-1;
	for(;ch>='0'&&ch<='9';ch=getchar()) x=(x<<3)+(x<<1)+ch-'0';
	x*=w;
}

int cmp(const int &q,const int &w){
	return a[q]<a[w];
}

int main(){
	read(n);
	for(int i=2;i<M;i++){
		if (!b[i]) pm[++L]=i;
		for(int j=1;j<=L&&i*pm[j]<M;j++){
			b[i*pm[j]]=1;
			if (i%pm[j]==0) break;
		}
	}
	for(int i=1;i<=n;i++){
		int x;read(x);
		for(int j=1;j<=L;j++){
			if (x==0) break;
			while(x%(pm[j]*pm[j])==0) x/=pm[j]*pm[j];
		//	if (x<pm[j]*pm[j]) break;
		}
		a[i]=x;num[i]=i;
	}
	//c[1]=n;
	sort(num+1,num+1+n,cmp);
	for(int i=1;i<=n;i++)
	 if (a[num[i]]==a[num[i-1]]&&i>1) dc[num[i]]=dc[num[i-1]];
	  else dc[num[i]]=i;
	for(int i=1;i<=n;i++){
	/*	if (a[i]){
			if (mp[dc[i]]==0) cur++;
			mp[dc[i]]++;
		}*/
		for(int j=i;j<=n;j++){
			if (a[j]) if (mp[dc[j]]==0) cur++;
			mp[dc[j]]++;
			if (cur) c[cur]++;
			 else c[1]++;
		}
		memset(mp,0,sizeof mp);cur=0;
	}
	for(int i=1;i<=n;i++) printf("%d ",c[i]);
	return 0;
}
