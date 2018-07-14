#include<bits/stdc++.h>
using namespace std;
const int N=101;
int k;

inline void read(int &x){
	char ch=getchar();x=0;int w=1;
	for(;ch<'0'||ch>'9';ch=getchar()) if (ch=='-') w=-1;
	for(;ch>='0'&&ch<='9';ch=getchar()) x=(x<<3)+(x<<1)+ch-'0';
	x*=w;
}

int main(){
	cin>>k;
	if (k%2==0){
		printf("NO\n");
		return 0;
	}
	k--;
	printf("YES\n");
	printf("%d %d\n",4*k+2,2*k*k+3*k+1);
	for(int i=1;i<=k;i++)
	 for(int j=k+1;j<=k<<1;j++)
	  printf("%d %d\n",i,j);
	for(int i=1;i<=k>>1;i++)
	 printf("%d %d\n",i*2-1,i*2);
	for(int i=k+1;i<=k<<1;i++)
	 printf("%d %d\n",4*k+1,i);
	 
	for(int i=2*k+1;i<=3*k;i++)
	 for(int j=3*k+1;j<=k<<2;j++)
	  printf("%d %d\n",i,j);
	for(int i=1;i<=k/2;i++)
	 printf("%d %d\n",2*k+i*2-1,2*k+i*2);
	for(int i=3*k+1;i<=k<<2;i++)
	 printf("%d %d\n",4*k+2,i);
	 
	printf("%d %d\n",4*k+1,4*k+2);
	return 0;
}
