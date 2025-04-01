#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define N 20 

// codigo a completar 
int main()
{
    /* code */
    
    int i; 
    double vt[N];
    //p_vt = vt; 
    srand(time(NULL));
    for(i = 0;i<N; i++) 
    {  
        *(vt+i)=1+rand()%100;
        printf("%.2f   ", *(vt+i));     
    }
    return 0;
}