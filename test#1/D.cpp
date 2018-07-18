#include<bits/stdc++.h>
#define LL long long
#define lson (node<<1)
#define rson (node<<1|1)
using namespace std;
const int N=200001;
int n,q,x[N],y[N],cnt,num[N],row[N<<2],col[N<<2];
bool d[N],re[N];
map<int,int> mp;
char ch;

inline void read(int &x){
	char ch=getchar();x=0;
	for(;ch<'0'||ch>'9';ch=getchar());
	for(;ch>='0'&&ch<='9';ch=getchar()) x=(x<<3)+(x<<1)+ch-'0';
}

void build(int node,int L,int r,int t[]){
	if (L==r) { t[node]=cnt-L+1;return; }
	int mid=(L+r)>>1;
	build(lson,L,mid,t[]);
	build(rson,mid+1,r,t[]);
	t[node]=min(t[lson],t[rson]);
}

int query(int node,int L,int r,int x,int y,int mx,int t[]){
	if (L==r) return L;
	int mid=(L+r)/2;
	if (t[rson]<=mx&&x<=r&&y>=mid+1) return query(rson,mid+1,r,x,y,mx,t[]);
	 else return query(lson,L,mid,x,y,mx,t[]);
}

int main(){
	read(n);read(q);
	for(int i=1;i<=q;i++){
		read(y[i]);read(x[i]);
		ch=getchar();
		if (ch=='U') b[i]=1;
		if (!mp.count(x[i])) mp[x[i]]=1;
		 else re[i]=1;
	}
	for(map<int,int>::iterator it=mp.begin();it!=mp.end();it++)
	 it->second=++cnt,num[cnt]=it->first;
	build(1,0,cnt,row);
	build(1,0,cnt,col);
	update(1,0,cnt,0,1,row);
	update(1,0,cnt,0,1,col);
	for(int i=1;i<=q;i++){
		if (re[i]){
			printf("0\n");
			continue;
		}
		if (d[i]){
			int mx=mp[x[i]],my=cnt-mx+1;
			int sum=query(1,0,cnt,1,mx-1,my,col);
			printf("%d\n",num[mx]-num[sum]);
			update(1,0,cnt,my,sum+1,row);
		} else{
			int mx=mp[x[i]]+1,my=cnt-mx+1;
			int sum=query(1,0,cnt,1,my-1,mx,row);
			printf("%d\n",num[my]-num[sum]);
			update(1,0,cnt,mx,sum+1,col);
		}
	}
	return 0;
}
