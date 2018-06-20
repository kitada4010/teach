#include <stdio.h>
#define MAX 11      /*配列の要素数を11としている*/
/*数字または分数入力させる関数*/
void scan_number(char tmp[],int n){
  int l; /*l:文字数受け取る変数*/
  do{
    printf("何文字入力ますか:");
    scanf("%d",&l);
    if (l>n-1)
      printf("%d以下の整数を入力してください。\n",n-1);
    else if (l<=0)
      printf("正の整数を入力してください。\n");
  }while(l>n-1||l<=0);
  printf("数字または分数を入力してください:");
  scanf(" %s",tmp);
}

char value(char *tmp){
  if ('0'<=*tmp&&'9'>=*tmp)
    *tmp-='0';
  return *tmp;
}


double change_fraction(char tmp[],int n){ /*分数を数値として出力させる関数*/
  int i=0; /*i:インクリメントで使用する変数*/
  int min=1;/*min:正負の判定に用いる変数*/
  int sla=0;/*'/'が出てきたかどうか判定するのに用いる変数*/
  double c; /*c:数値を入れる変数*/
  double a=0.0; /*a:分子の数値を入れる変数*/
  double b=0.0; /*b:分母の数値を入れる変数*/

  if(tmp[0]=='-') /*正負を判定*/
    min=-1;

  while(tmp[i]){/*ナル文字が出るまで文字から数値に変換する*/
    if(sla==0&&tmp[i]!='/')
      a=(a*10)+value(&tmp[i]);
    else if(tmp[i]=='/')
      sla=1;
    else if(sla==1){
      b=(b*10)+value(&tmp[i]);
      printf("%lf\n",b);
    }
    i++;
  }
  if(sla)  /*'/'がなかった場合分母の数値(変数b)を1にする*/
    b=1.0;
  printf("%lf\n",b);
  c=(a/b)*min;  /*分数から小数へ(正負も掛ける)*/
  return(c);
}

int main(void){
  char suu[MAX];
  double sum=0.0,mul=0.0;
  double num1, num2;
  scan_number(suu,MAX);  /*関数を使って配列の中身を書き込む*/
  num1= change_fraction(suu,MAX); /*配列の中身を関数に渡し小数になったものをnum1に代入する*/
  printf("num1=%.2f\n",num1);
  scan_number(suu,MAX);    /*関数を使って配列の中身を書き込む*/
  num2= change_fraction(suu,MAX); /*配列の中身を関数に渡し小数になったものをnum2に代入する*/
  printf("num2=%.2f\n",num2);
  sum=num1+num2;
  mul=num1*num2;

  printf("和は%.2fで積は%.2fです。\n",sum,mul);
  return 0;
}
