#include<iostream>
#include<iomanip>
#include<limits.h>
using namespace std;

class FloydWarshall{
    int w[10][10],d[10][10],pi[10][10];
    int e,v;
    public:
        void initialize(int M[][5]){
            for(int i=0;i<5;i++){
                for(int j=0;j<5;j++){
                    w[i][j]=M[i][j];
                    d[i][j]=M[i][j];
                }
            }
        }
        void getdata(){
            cout<<"Enter the no of Vertices : "<<endl;
            cin>>v;
            for(int i=0;i<v;i++){
                for(int j=0;j<v;j++){
                    if(i==j || w[i][j]==INT_MAX){
                        pi[i][j]=INT_MAX;
                    }
                    else{
                        pi[i][j]=i;
                    }
                }
            }
        }
        void display(){
            cout<<"\n Weight Matrix "<<endl;
            setiosflags(ios::right);
            for(int j=0;j<v;j++){
                for(int i=0;i<v;i++){
                    cout<<setw(15)<<w[j][i];
                }
                cout<<endl;
            }
            cout<<endl<<"Pi Matrix : "<<endl;
            for(int i=0;i<v;i++){
                for(int j=0;j<v;j++){
                    cout<<setw(15)<<pi[i][j];
                }
                cout<<endl;
            }
        }
        void Floyd_Warshall(){
            for(int k=0;k<v;k++){
                for(int i=0;i<v;i++){
                    for(int j=0;j<v;j++){
                        if(d[i][k]!=INT_MAX && d[k][j]!=INT_MAX && d[i][j]>d[i][k]+d[k][j]){
                            d[i][j]=d[i][k]+d[k][j];
                            pi[i][j]=pi[k][j];
                        }
                    }
                }
            }
        }
        void Print_Shortest_Path(int i,int j){
            if(i==j){
                cout<<i;
            }
            else if(pi[i][j]==INT_MAX){
                cout<<"No Path exist from "<<i<<" to "<<j<<endl;
            }
            else{
                Print_Shortest_Path(i,pi[i][j]);
                cout<<" --> "<<j;
            }
        }
        void Print_All_ShortestPaths(){
            for(int i=0;i<v;i++){
                for(int j=0;j<v;j++){
                    Print_Shortest_Path(i,j);
                    cout<<endl;    
                }
                cout<<endl;
            }
        }
};

int main(){
    FloydWarshall G;
    int w[][5]={{0,3,9,INT_MAX,-4},{INT_MAX,0,INT_MAX,1,7},{INT_MAX,4,0,INT_MAX,INT_MAX},{2,INT_MAX,-5,0,INT_MAX},{INT_MAX,INT_MAX,INT_MAX,6,0}};
    G.initialize(w);
    G.getdata();
    G.display();
    G.Floyd_Warshall();
    G.display();
    G.Print_All_ShortestPaths();
    return 0;
}
