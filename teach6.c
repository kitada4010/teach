#include <stdio.h>
#define MAX 10
double max_of(double tmp[],int n){
  
  if(n>0)
    return (tmp[n] > max_of(tmp,n-1) ) ? tmp[n] : max_of(tmp,n-1);
  
  return tmp[0];
}

void scan_data(double x[],int n){
  int i;
  for(i=0;i<n;i++){
    printf("x[%d]=",i+1);
    scanf("%lf",&x[i]);
  }
}

int main(void){
  double data[MAX];
  static double max;
  int num;
  puts("最大値を求めます。");
  do{
    printf("データを何個入力しますか:");
    scanf("%d",&num);
    if(num<1)
      printf("正の数を入力してください。");
    else if(MAX<=num)
      printf("%d以下の正を入力してください。",MAX);
    printf("ooo\n");
  }while(num<1||MAX<=num);
  printf("ooo\n");
  scan_data(data,num);
  printf("最大値は%fです。\n",max_of(data,num-1));
  return 0;
}
