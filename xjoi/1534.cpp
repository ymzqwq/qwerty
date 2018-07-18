#include<bits/stdc++.h>
using namespace std;
const int N=10;
struct data{
	int L,num[N];
	
	data(){
		L=0;
		memset(num,0,sizeof num);
	}
	
	void read(){
		char ch;
		scanf("%c",&ch);
		for(int i=L;i>=0;i--) num[i]=ch-'0',scanf("%c",&ch);
	}
	
	data operator * (data &q) const {
		data ans;
		ans.L=L;
		for(int i=0;i<=L;i++)
		 for(int j=0;j<=q.L;j++)
		  ans.num[i+j]+=num[i]*q.num[j];
		for(int i=0;i<=L;i++) ans.num[i+1]+=ans.num[i]/10,ans.num[i]%=10;
		return ans;
	}
	
}a,b,c,x,y,z;
char ch;
int ans=5,v;

void read(int &x){
	char ch=getchar();x=0;
	for(;ch<'0'||ch>'9';ch=getchar());
	for(;ch>='0'&&ch<='9';ch=getchar()) x=(x<<3)+(x<<1)+ch-'0';
}

void dfsy(int w,int k){
	if (k>=ans) return;
	if (w>a.L){
		z=x*y;
		v=k;
		for(int i=0;i<=a.L;i++)
	 	 if (z.num[i]!=c.num[i]) v++;
		ans=min(ans,v);
		return;
	}
	dfsy(w+1,k);
	for(int i=0;i<=9;i++){
		y.num[w]=i;
		dfsy(w+1,k+1);
		y.num[w]=b.num[w];
	}
}

void dfsx(int w,int k){
	if (k>=ans) return;
	if (w>a.L){
		dfsy(0,k);
		return;
	}
	dfsx(w+1,k);
	for(int i=0;i<=9;i++){
		x.num[w]=i;
		dfsx(w+1,k+1);
		x.num[w]=a.num[w];
	}
}

int main(){
	a.L=b.L=c.L=5;
	a.read();b.read();c.read();
	x=a;y=b;
	dfsx(0,0);
	cout<<ans;
	return 0;
}
