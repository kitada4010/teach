#include <stdio.h>
#define MAX 100

double change(char tmp[],int n){
  int m,l,r;
  int i=0,k=0,j=0,o=1,min=1;
  double c;
  double a=0.0,b=0.0;
  double x,y;
  if(tmp[0]=='-')
    min=-1;
  while((tmp[i]!='/')&&(tmp[i]!=0)){
    if ('0'<=tmp[i]&&'9'>=tmp[i]){
      tmp[i]-='0';
      k+=1;
    }
    i+=1;
  }
  while(j<i){
    o=1;
    if(0<=tmp[j]&&9>=tmp[j]){

      for(l=k-1;l>0;l--){
    printf("l=%d\n",l);
    o*=10;
    printf("o=%d\n",o);
      }
      printf("tmp[%d]=%d\n",j,tmp[j]);
      x=tmp[j]*o;
      printf("tmp[%d]=%lf\n",j,x);
      a+=tmp[j];
      k-=1;
    }

    j+=1;
  }
  i+=1;
  j=i;
  k=0;
  while(tmp[i]){
    if ('0'<=tmp[i]&&'9'>=tmp[i]){
      tmp[i]-='0';
      k+=1;
      printf("tmp[%d]=%d\n",i,tmp[i]);
    }
    i+=1;
  }
  if(k==0)
    b=1.0;
  printf("tmp[%d]=%d\n",i,tmp[i]);

  while(j<i){
    o=1;
    if(0<=tmp[j]&&9>=tmp[j]){
      for(l=k-1;l>0;l--)
    o*=10;
      tmp[j]*=o;
      printf("tmp[%d]=%d yattaze\n",j,tmp[j]);
      b+=tmp[j];
      k-=1;
    }


    j+=1;
  }
  printf("a=%.2f,b=%.2f\n",a,b);
  c=a/b*min;
  printf("c=%.2f\n",c);
  return(c);
}

int main(void){
  char suu[MAX];
  double sum=0,mul=0;
  int l;
  do{
    printf("何文字入力ますか:");
    scanf("%d",&l);
    if (l>MAX-1)
      printf("%d以下の整数を入力してください。\n",MAX-1);
  }while(l>MAX-1);
  printf("数字または分数を入力してください:");
  scanf(" %s",&suu);
  printf("suu=%s\n",suu);

  double num1=change(suu,MAX);
  printf("%f\n",num1);
  do{
    printf("何文字入力ますか:");
    scanf("%d",&l);
    if (l>MAX-1)
      printf("%d以下の整数を入力してください。\n",MAX-1);
  }while(l>MAX-1);
  printf("数字または分数を入力してください:");
  scanf(" %s",&suu);
  printf("suu=%s\n",suu);

  double num2=change(suu,MAX);
  printf("%f\n",num2);

  sum=num1+num2;
  mul=num1*num2;

  printf("和は%.2fで積は%.2fです。\n",sum,mul);
  return 0;
}
