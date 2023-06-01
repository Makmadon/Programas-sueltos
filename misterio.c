#include <stdio.h>

int misterio(int x,int y){
    int t;
    if(!y)
        return 1;
    t=misterio(x,y>>1);
    if(y&1)
        return t*t*x;
    return t*t;
}

int y=2;


int main(){
    printf("%d", misterio(y,4));
}