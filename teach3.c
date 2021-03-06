#include <stdio.h>
#define MAX 12      /*配列の要素数を12としている*/

double change_fraction(const char tmp[]){ /*分数を数値として出力させる関数*/
  int i=0; /*i:インクリメントで使用する変数*/
  int min=1;/*min:正負の判定に用いる変数*/
  int sla=0;/*'/'が出てきたかどうか判定するのに用いる変数*/
  double fig; /*fig:数値を入れる変数*/
  double num=0.0; /*num:分子の数値を入れる変数*/
  double den=0.0; /*den:分母の数値を入れる変数*/

  if(tmp[0]=='-') /*正負を判定*/
    min=-1;
  while(tmp[i]){/*ナル文字が出るまで文字から数値に変換する*/
    if('0'<=tmp[i]&&'9'>=tmp[i]){
      if(sla==0)
    num=num*10+(tmp[i]-'0'); /*分子を求める*/
      else
    den=den*10+(tmp[i]-'0'); /*分母を求める*/
    }
    else if(tmp[i]=='/')
      sla=1;
    i++;
  }

  if(sla==0)  /*'/'がなかった場合分母の数値(変数den)を1にする*/
    den=1.0;

  fig=num/den*min;  /*分数から小数へ(正負も掛ける)*/
  return(fig);
}

int main(void){
  char suu1[MAX],suu2[MAX];
  double sum=0.0,mul=0.0;
  double num1, num2;

  printf("数字または分数を%d以上入力すると正確に計算することはできません。\n",MAX-1);
  printf("数字または分数を%d以下で入力してください:",MAX-2);
  fgets(suu1,MAX,stdin);  /*配列の中身を書き込む*/
  num1= change_fraction(suu1); /*配列の中身を関数に渡し小数になったものをnum1に代入する*/
  printf("数字または分数を%d以上入力すると正確に計算することはできません。\n",MAX-1);
  printf("数字または分数を%d以下で入力してください:",MAX-2);
  fgets(suu2,MAX,stdin);  /*関数を使って配列の中身を書き込む*/
  num2= change_fraction(suu2); /*配列の中身を関数に渡し小数になったものをnum2に代入する*/

  printf("num1=%.2f\n",num1);
  printf("num2=%.2f\n",num2);

  sum=num1+num2;
  mul=num1*num2;

  printf("和は%.2fで積は%.2fです。\n",sum,mul);
  return 0;
}
