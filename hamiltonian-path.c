#include <stdio.h>
#define MAX 10

int stack[ MAX ], //stack of integers 

    n,          //number of elements

    level;      //global level

int mat[ MAX ][ MAX ];

int num_nodes, num_edges;

void read();
void init();
void back();
int have_next();
void print_solution();
int isValid();
int solution();

int main() {

    read(); 

    level = 1;
    stack[ level ] = 1;

    level = 2;
    back();    
  
  //return SUCCESS to the Operating System
  return 0;
}

void read() {

     int i, j;

     freopen("hamiltonian-path.in", "r", stdin);
     freopen("hamiltonian-path.out", "w", stdout);

     scanf("%d", &num_nodes);
     scanf("%d", &num_edges);

     for(; num_edges; num_edges--) {

           scanf("%d %d", &i, &j);
           mat[i][j] = mat[j][i] = 1; 
     }
}

void init() {

     stack[ level ] = 0;
}

void back() {

   int HN;

   init();

   while( level > 0 ) {

     do{}while( (HN = have_next()) && !isValid());

     if( HN ) {

            if(solution()) {

              print_solution();
           
           } else {

              level = level + 1;

              init();
            }

     }  else {

           level = level - 1;
     }
   }
};

int have_next() {

    if(stack[ level ] < n) {

       stack[ level ]++;  

       return 1;

    }

    return 0;
};

void print_solution() {

     int i;

     for(i = 1; i <= n; i++) printf("%d ", stack[ i ]);

     printf("\n");

};

int isValid() {

    int i;    

    if( !mat[ stack[ level - 1 ] ][ stack[ level ] ] ) return 0;

    else { 
   
        for(i = 1; i < level; i++) 

        if(stack[ i ] == stack[ level ]) return 0;

    
        if(level == n && !mat[1][stack[level]]) return 0;
    }

    return 1;  
};

int solution() {

     return level == n;
}