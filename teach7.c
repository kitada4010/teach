#include <stdio.h>
#define MAX 10
double max_of(double tmp[],int n){
  double max=tmp[n];
  if (n>0)
    if(max<max_of(tmp,n-1))
      max=max_of(tmp,n-1);
  return(max);
}

void scan_data(double x[],int n){
  int i;
  for(i=0;i<n;i++){
    printf("x[%d]=",i);
    scanf("%lf",&x[i]);
  }
}

int main(void){
  double data[MAX];
  int num;
  puts("最大値を求めます。");
  do{
    printf("データを何個入力しますか:");
    scanf("%d",&num);
    if(num<0)
      puts("正の数を入力してください。");
    else if(MAX<num)
      printf("%d以下の正を入力してください。\n",MAX);
  }while(num<0||MAX<num);
  scan_data(data,num);
  printf("最大値は%fです。\n",max_of(data,num));
  return 0;
}
