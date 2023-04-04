#include<bits/stdc++.h>
using namespace std;
class Lcs{
	private:
	string x;
	string y;
	public:
	void input(){
		cout<<"Enter String  1 : "<<endl;
		getline(cin,x);
		cout<<"Enter String  2 : "<<endl;
		getline(cin,y);
	}
	/// @brief 
	void Length_Lcs(int (&b)[50][50],int &m,int &n)
	{	
		m=x.length();
		n=y.length();
		int c[m+1][n+1];
		for (int i=0;i<=m;i++){
			for(int j=0;j<=n;j++){
				if (i == 0 || j == 0)
              	  c[i][j] = 0;
				else if(x[i-1]==y[j-1]){
					b[i][j]=0;
					c[i][j]=c[i-1][j-1] + 1;
				}
				else if(c[i-1][j]>=c[i][j-1]){
					c[i][j]=c[i-1][j];
					b[i][j]=1;
				}
				else{
					c[i][j]=c[i][j-1];
					b[i][j]=-1;
				}
			}
		}
		cout<<c[m][n]<<endl;
	}
	void print_lcs(int b[50][50],int i,int j){
		if(i==0 || j==0){
			return ;
		}
				if(b[i][j]==0){
					print_lcs(b,i-1,j-1);
					cout<<x[i];
				}
				else if(b[i][j]==1){
					print_lcs(b,i-1,j);
				}
				else{
					print_lcs(b,i,j-1);
				}
	}
};
int main(){
	Lcs s;
	s.input();
	int b[50][50],m,n;
	s.Length_Lcs(b,m,n);
	s.print_lcs(b,m,n);

}
