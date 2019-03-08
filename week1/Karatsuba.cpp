#include<bits/stdc++.h>
using namespace std;

int equate(string& a, string& b){
	int n1=a.length();
	int n2=b.length();
	if(n1==n2){
		return n1;
	}
	else if(n1<n2){
		int l=n2-n1;
		string temp="";
		for(int i=0;i<l;i++)
			temp+=to_string(0);
		a=temp+a;
		return n2;
	}
	else{
		int l=n1-n2;
		string temp="";
		for(int i=0;i<l;i++)
			temp+=to_string(0);
		b=temp+b;
		return n1;
	}
}

int single(vector<int> x, vector<int> y){
	return x[0]*y[0];
}

vector<int> sum(vector<int> a, vector<int> b){
	int l1=a.size();
	int l2=b.size();
	vector<int> res;
	int carry=0;
	if(l1>l2)
		res.resize(l1);
	else if(l2>l1)
		res.resize(l2);
	else res.resize(l1);
	if(l1>l2){
		for(int i=l2-1;i>=0;i--){
			res[l1-(l2-i)]=a[l1-(l2-i)]+b[i];
			if(res[l1-(l2-i)]<=9)continue;
			else{
				carry=res[l1-(l2-i)]/10;
				res[l1-(l2-i)]=res[l1-(l2-i)]%10;
			}
		}
		for(int i=l1-l2-1; i>=0;i--)
			res[i]=a[i];
	}
	else if(l2>l1){
		for(int i=l1-1;i>=0;i--){
			res[l2-(l1-i)]=b[l2-(l1-i)]+a[i];
			if(res[l2-(l1-i)]<=9)continue;
			else{
				carry=res[l2-(l1-i)]/10;
				res[l2-(l1-i)]=res[l2-(l1-i)]%10;
			}
		}
		for(int i=l2-l1-1; i>0;i--)
			res[i]=b[i];
	}
	else if(l1==l2){
		for(int i=l1-1;i>=0;i--){
			res[i]=a[i]+b[i]+carry;
			if(res[i]>9){
				carry=res[i]/10;
				res[i]=res[i]%10;
			}
		}
	}
	if(carry==0)return res;
	else {
		int r=res.size();
		vector<int> r1(r+1);
		for(int i=1;i<=r;i++)
			r1[i]=res[i-1];
		r1[0]=carry;
		return r1;
	}
}

vector<int> diff(vector<int> a, vector<int> b){
	int l1=a.size();
	int l2=b.size();
	vector<int> res;
	int carry=0;
	if(l1>l2)
		res.resize(l1);
	else if(l2>l1)
		res.resize(l2);
	else res.resize(l1);
	if(l1==l2){
		if(a[0]>b[0]){
			int carry=0;
			for(int i=l1-1;i>=0;i--){
				res[i]=a[i]-b[i];
				if(carry==0)continue;
				else res[i]-=1;
				if(res[i]<0){
					res[i]+=10;
					carry=1;
				}
				else if(res[i]>=0)carry=0;
			}
		}
		if(a[0]<=b[0]){
			int carry=0;
			for(int i=l1-1;i>=0;i--){
				res[i]=b[i]-a[i];
				if(carry==0)continue;
				else res[i]-=1;
				if(res[i]<0){
					res[i]+=10;
					carry=1;
				}
				else if(res[i]>=0)carry=0;
			}
		}
	}
	else if(l1<l2){
		int carry=0;
		for(int i=l1-1;i>=0;i--){
			res[l2-(l1-i)]=b[l2-(l1-i)]-a[i]-carry;
			if(res[l2-(l1-i)]<0){
				res[l2-(l1-i)]+=10;
				carry=1;
			}
			else carry=0;
		}
		for(int i=l2-l1-1; i>=0; i--){
			if(carry==0)res[i]=b[i];
			else{
				res[i]=b[i]-1;
				carry=0;
				if(res[i]<0){
					res[i]+=10;
					carry=1;
				}
			}
		}
	}
	else if(l2<l1){
		int carry=0;
		for(int i=l2-1;i>=0;i--){
			res[l1-(l2-i)]=a[l1-(l2-i)]-b[i]-carry;
			if(res[l1-(l2-i)]<0){
				res[l1-(l2-i)]+=10;
				carry=1;
			}
			else carry=0;
		}
		for(int i=l1-l2-1; i>=0; i--){
			if(carry==0)res[i]=a[i];
			else{
				res[i]=a[i]-1;
				carry=0;
				if(res[i]<0){
					res[i]+=10;
					carry=1;
				}
			}
		}
	}
	return res;
}

vector<int> product(vector<int> x, vector<int> y){
	int first, second;
	int l=y.size();
	if(l==1){
		vector<int> g;
		int p=single(x, y);
		if(p<=9){
			g.resize(1);
			g[0]=p;
		}
		else{
			g.resize(2);
			g[0]=p/10;
			g[1]=p%10;
		}
		return g;}
	first=l/2;
	second=l-first;
	vector<int> xl(first), xh(second), yl(first), yh(second);
	for(int i=0;i<first;i++){
		xl[i]=x[i];
		yl[i]=y[i];
	}
	for(int i=first;i<l;i++){
		xh[i-first]=x[i];
		yh[i-first]=y[i];
	}
	vector<int> p1, p2, p3;
	p1=product(xl, yl);
	p2=product(xh, yh);
	vector<int>s1, s2;
	s1=sum(xl, xh);
	s2=sum(yl, yh);
	p3=product(s1, s2);
	//p2.resize(l*2);
	p3=diff(p3, p2);
	p3=diff(p3, p1);
	int h=p3.size();
	p3.resize(h+first);
	h=p1.size();
	p1.resize(h+first*2);
	for(int i=0;i<p3.size();i++)
		cout<<p3[i];
	cout<<endl;
	for(int i=0;i<p2.size();i++)
		cout<<p2[i];
	cout<<endl;
	for(int i=0;i<p1.size();i++)
		cout<<p1[i];
	cout<<endl;
	p3=sum(p3, p2);
	return sum(p3,p1);
}

int main(){
	string a, b;
	cin>>a>>b;
	int l=equate(a, b);
	vector<int> x(l), y(l);
	for(int i=0;i<l;i++){
		x[i]=a[i]-'0';
		y[i]=b[i]-'0';
	}
	vector<int> res=product(x, y);
	for(int i=0;i<res.size(); i++)
	cout<<res[i];
	cout<<endl;
	return 0;
}
