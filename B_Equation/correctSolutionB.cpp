#include<stdio.h>
int main(){
  int a,b,c;
  scanf("%d %d %d",&a,&b,&c);
  int x=-1,y=-1;
  for(int i=0 ; i<100 ; i++){
    for(int j=0 ; j<100 ; j++){
      if(a*i + b*j == c){
        x = i;
        y = j;
      }
    }
  }
  printf("%d %d\n",x,y);
}