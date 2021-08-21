#include <iostream>
#include <fstream>
#define FIN "hamilton.in"
#define FOUT "hamilton.out"
 
using namespace std;
 
const int INF = 100000000;
const int MAXN = 20;
 
int n, m, sol;
int Cost[ MAXN ][ MAXN ],
    P[ MAXN ],
    Used[ MAXN ];
 
void back(int level) {
 
     if(level > n) {
 
           int summa = Cost[P[n]][P[1]];
 
           for(int i = 1; i < n; ++i) {
 
               summa += Cost[ P[i] ][ P[i+1] ];
           }
 
           sol = min(sol, summa);
 
           return;
 
     }
 
          for(int i = 0; i < n; ++i) {
 
              if( !Used[i] ) {
                   P[ level ] = i;
                   Used[i] = 1;
                   back(level + 1);
                   Used[i] = 0;
              }
          }
 
}
 
int main(int argc, char const *argv[]) {
 
    int x,
        y;
 
    ifstream fin(FIN);
 
    ofstream fout(FOUT);
 
    fin>>n>>m;
 
    sol = INF;
    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; ++j)
            Cost[i][j] = INF;
 
    while( m-- ){
        fin>>x>>y;
        fin>>Cost[x][y];
    }
 
    back(1);
 
    if(sol == INF) {
      fout<<"Nu exista solutie";
    } else {
      fout<<sol;
    }
 
  return 0;
}
