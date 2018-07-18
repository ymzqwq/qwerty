#include<bits/stdc++.h>
#define LL long long
using namespace std;
const int N=60001;
const double EPS=1e-7;
struct data{
	double x,y;
	
	data operator - (const data &q) const{
		return (data){x-q.x,y-q.y};
	}
	
	data operator + (const data &q) const{
		return (data){x+q.x,y+q.y};
	}
	
	/*data& operator = (data &q){
		x=q.x;y=q.y;
		return *this;
	}*/
	
	data mul(double v){
		return (data){x*v,y*v};
	}
	
	void read(){
		cin>>x>>y;
	}
	
}a,b,c,d,ab,cd;
double L=0,r=1;
 
void read(int &x){
    char ch=getchar();x=0;int w=1;
    for(;ch<'0'||ch>'9';ch=getchar()) if (ch=='-') w=-1;
    for(;ch>='0'&&ch<='9';ch=getchar()) x=(x<<3)+(x<<1)+ch-'0';
    x*=w;
}

inline double sqr(double x) { return x*x; }

inline double check(double x){
	data q=a+ab.mul(x),p=c+cd.mul(x);
	double ans=sqr(q.x-p.x)+sqr(q.y-p.y);
	return sqrt(ans);
}
 
int main(){
    a.read();b.read();c.read();d.read();
    ab=b-a;cd=d-c;
    while(r-L>=EPS){
    	double mid1=(L*2+r)/3,mid2=(L+r*2)/3;
    	if (check(mid1)>check(mid2)) L=mid1;
    	 else r=mid2;
    }
    printf("%.5lf",check(L));
    return 0;
}
