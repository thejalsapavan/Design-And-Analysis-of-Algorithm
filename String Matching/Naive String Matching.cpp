#include<iostream>
using namespace std;
class StringMatching{
	public:
		void Naive_String(string S,string P,int &count){
			int m,n;
			n=S.length();
			m=P.length();
			int flag;
			for(int i=0; i<=(n-m);i++){
				flag=0;
				for(int j=0;j<m;j++){
					count++;
					if(P[j]!=S[i+j]){
						flag=1;
						break;
					}
				}
				if(flag==0)
				cout<<"Pattern is Occuring in valid Shifts : "<<i<<endl;
			}
		}
};
int main(){
	cout<<" \t Naive Method "<<endl;
	string s="ABARBDDWEECRWSEDFKADEQ";
	string p="DWE";
	StringMatching f;
	int c;
	f.Naive_String(s,p,c);
	cout<<"Count value : "<<c;
}