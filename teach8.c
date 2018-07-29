#include <stdio.h>
#include <math.h>
int judge(void){ /*変換を実行するか入力させる関数*/
  int jud=0;
  do{
    printf("変換するなら\"1\"を変換しないなら\"0\"を入力してください:");
    scanf("%d",&jud);
    if(jud<0||jud>1)
      puts("0または1を入力してください。");
  }while(jud<0||jud>1);
  return(jud);
}

struct orth_coord{
  double x; /*直行座標を表す構造体*/
  double y;
};

struct pol_coord{
  double r; /*極座標を表す構造体*/
  double ang;
};

struct pol_coord orth2polar_p(double x,double y){
  struct pol_coord temp;
  temp.r=sqrt(x*x+y*y); /*直行座標から極座標に変換する関数*/
  temp.ang=atan2(y,x);
  return temp;
}

struct orth_coord polar2orth_p(double r,double ang){
  struct orth_coord temp;
  temp.x=r*cos(ang); /*極座標から直行座標に変換する関数*/
  temp.y=r*sin(ang);
  return temp;
}
int main(void){
  struct orth_coord orth;
  struct pol_coord pol;
  int jud;
  puts("直行座標から極座標(r,θ)に変換します。");
  jud=judge();
  if(jud){
    puts("x,y座標を入力してください。");
    printf("x=");
    scanf("%lf",&orth.x);
    printf("y=");
    scanf("%lf",&orth.y);
  pol=orth2polar_p(orth.x,orth.y);
    printf("極座標はr=%.4f,θ=%.4fです。\n",pol.r,pol.ang);
  }

  puts("極座標から直行座標(x,y)に変換します。");
  jud=judge();
  if(jud){
    puts("r,θ座標を入力してください。");
    do{
      printf("r=");
      scanf("%lf",&pol.r);
      if(pol.r<0)
    puts("正の値を入力してください。");
    }while(pol.r<0);
    printf("θ=");
    scanf("%lf",&pol.ang);
    orth=polar2orth_p(pol.r, pol.ang);
    printf("直行座標はx=%.4f,y=%.4fです。\n",orth.x,orth.y);
  }
  return 0;
}
