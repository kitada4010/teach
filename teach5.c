#include <stdio.h>
void prin_table( int tmp[][3]){
  int i,j;
  puts("    1    2    3");
  for(i=0;i<3;i++){
    puts("  ----------------");
    printf("%d ",i+1);
    for(j=0;j<3;j++){
      if(tmp[i][j]==1)
    printf("| ○  ");
      else  if(tmp[i][j]==-1)
    printf("| ☓  ");
      else
    printf("|    ");
    }
    printf("|\n");
  }
  puts("  ----------------");
}
void scan_position(int tmp[][3],int play,int sym){
  int i,j;
  printf("Player %d , rnter roe and column:",play);
  scanf("%d %d",&i,&j);
  tmp[i-1][j-1]=sym;
}
int main(void){
  int tic[3][3]={0},win[8]={0};
  int jud=1,fin=0,i=0;
  int j,o,p;
  prin_table(tic);
  do{
    if(jud==1){
      scan_position(tic,1,jud);
      prin_table(tic);
      jud*=-1;
      i++;
    }
    else{
      scan_position(tic,2,jud);
      prin_table(tic);
      jud*=-1;
      i++;
    }
    for(o=0;o<3;o++){
      for(p=0;p<3;p++)
    printf("%2d ",tic[o][p]);
      putchar('\n');
    }
    if(i>=3){
      for(j=0;j<3;j++){
    win[0]+=tic[2-j][j];
    printf("win[0]=%d\n",win[0]);
    win[1]+=tic[0][j];
    printf("win[1]=%d\n",win[1]);
    win[2]+=tic[1][j];
    printf("win[2]=%d\n",win[2]);
    win[3]+=tic[2][j];
    printf("win[3]=%d\n",win[3]);
    win[4]+=tic[j][0];
    printf("win[4]=%d\n",win[4]);
    win[5]+=tic[j][1];
    printf("win[5]=%d\n",win[5]);
    win[6]+=tic[j][2];
    printf("win[6]=%d\n",win[6]);
    win[7]+=tic[j][j];
    printf("win[7]=%d\n",win[7]);
      }

      for(j=0;j<8;j++)
    if(win[j]==3){
      puts("Player 1 wins");
      fin=1;
      printf("win[%d]=%d\n",j,win[j]);
    }
    else if(win[j]==-3){
      puts("Player 2 wins");
      fin=1;
      printf("win[%d]=%d\n",j,win[j]);
    }
    }
  }while(fin==0);
  return 0;
}
