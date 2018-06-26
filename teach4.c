#include  <stdio.h>
#include <stdlib.h>
int intercalary_year(int year){
  int n=0;
  if(year%4==0){
    if(year%100==0){
      if(year%400==0)  //うるう年チェック//
    n=1;
    }
    else
      n=1;
  }
  return(n);
}
int determin_week(int year,int mon,int day){
  int w;
  if(mon==1||mon==2){
    mon+=12;
    year-=1;
  }
  w=(5*year/4-year/100+year/400+(26*mon+16)/10+day)%7;
  return(w);
}
void make_calendar(int table[5][7],int year,int month){
  int tmp=0,count=0;
  int day=1;
  int j,k,t,end,emp;
  int weak=determin_week(year,month,day);
  int leap=intercalary_year(year);

  j=month+1;
  if(month==2)
    tmp=2;
  else  if(((1<=month&&7>=month)&&month%2)||((9<=j&&13>=j)&&j%2)){  //31日まである月//
    tmp=1;
  }
  else  //30日までの月//
    tmp=3;

  if(leap==1&&tmp==2)
    end=29;
  else if(leap==0&&tmp==2)
    end=28;
  else if(tmp==1)
    end=31;
  else
    end=30;

  for(k=0;k<5;k++)
    for(t=0;t<7;t++){
      if(count>=weak||(count-weak)<=end)
    emp=1;
      else
    emp=0;
      if(emp==1){
    table[k][t]=day;
    day++;
      }
      else
    table[k][t]=0;
      count++;
    }
}
void print_calendar(const int table[5][7],int year,int month){
  int i,w;
  printf("  %2d月 %d年\n",month,year);
  printf("日 月 火 水 木 金 土\n");
  for(i=0;i<5;i++)
    for(w=0;w<7;w++)
      printf("%2d ",table[i][w]);
  putchar('\n');
}

int main(int argc, char *argv[]){
  int year;
  int month;
  int cal[5][7];
  int all=0,i=0;
  year=atoi(argv[1]);
  month=atoi(argv[2]);
  make_calendar(cal,year,month);
  if(month==0){
    all=1;
    i=1;
  }
  while((i==2&&all==0)||(i==12&&all==1)){
    print_calendar(cal,year,month+i);
    i++;
  }
  return 0;
}
