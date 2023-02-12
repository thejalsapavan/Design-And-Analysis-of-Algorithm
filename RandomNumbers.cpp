#include<iostream>
#include<time.h>
#include<fstream>
#include<string.h>
using namespace std;
class random{
    public:
    void randomipfile(){
        srand((long int)clock());
        ofstream in("input.txt");
        for(int i=0;i<11000;i++){
            in<<rand()%3000<<"  ";
        }
    }
        void randomipfileincreasing(){
        srand((long int)clock());
        ofstream in("inputin.txt");
        for(int i=0;i<11000;i++){
            in<<i<<"  ";
        }
    }   
     void randomipfiledec(){
        srand((long int)clock());
        ofstream in("inputdec.txt");
        for(int i=0;i<11000;i++){
            in<<11000-i<<"  ";
        }
    }
};
int main(){
  random r;
  r.randomipfile(); 
  r.randomipfileincreasing();
  r.randomipfiledec();
}