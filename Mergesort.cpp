#include<iostream>
#include<fstream>
#include<stdlib.h>
using namespace std;
class sorting{
    private:
    long int A[11000];
    public:
        void input(){
            ifstream f ("input.txt");
            for(int i=0;i<11000;i++){
                f>>A[i];
            }
        }
        void output(){
            ofstream o("output.txt");
             for(int i=0;i<11000;i++){
                o<<A[i]<<"  ";
            }
        }
        void Merge( int p,int q,int r,int &count){
                int n1=q-p+1;
               int n2=r-p;
               int L[n1+1],R[n2+1];
               for(int i=0;i<n1;i++){
                L[i]=A[p+i];

               }
                for(int j=0;j<n2;j++){
                R[j]=A[q+j+1];
                
               }
               L[n1]=99999999;
               R[n2]=99999999;
               int i=0;
               int j=0;
               for(int k=p;k<=r;k++){
                count++;
                if(L[i]<=R[j]){
                    A[k]=L[i];
                    i++;
                }
                else{
                    A[k]=R[j];
                    j++;
                }
               }
        }
        void mergesort(int p,int r,int &count){
            if(p<r){
               int q=(p+r)/2;
                mergesort(p,q,count);
                
                mergesort(q+1,r,count);
                Merge(p,q,r,count);
            }
    }
};
int main(){
    sorting s;
    s.input();
    int c;
    s.mergesort(0,9999,c);
    
    s.output();
    cout<<"No of comparisions"<<c;
}
