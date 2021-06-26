#include <cstdio>
const int MAX = 10;
int bingo[MAX][MAX];
 
int main()
{
  int value, cnt = 0, total_cnt = 0, value_cnt = 0;
  bool flag = false;
  for(int i = 1; i <= 5; i++)
  {
    for(int j = 1; j <= 5; j++) scanf("%d", &bingo[i][j]);
  }
  
  for(int k = 1; k <= 25; k++)
  {
    scanf("%d", &value);

    value_cnt++;
    total_cnt = 0;
    flag = false;

    for(int i = 1; i <= 5; i++)
    {
      for(int j = 1; j <= 5; j++)
      {
        if(bingo[i][j] == value)
        {
          bingo[i][j] = 0;
          flag = true;
          break;
        }

        if(flag) break;
      }
    }
    
    for(int i = 1; i <= 5; i++)
    {
      cnt = 0;

      for(int j = 1; j <= 5; j++)
      {
        if(bingo[i][j] == 0) cnt++;
      }
      
      if(cnt == 5) total_cnt++;
    }
    
    
    for(int i = 1; i <= 5; i++)
    {
      cnt = 0;

      for(int j = 1; j <= 5; j++)
      {
        if(bingo[j][i] == 0) cnt++;
      }

      if(cnt == 5) total_cnt++;
    }
    
    cnt = 0;
    for(int i = 1; i <= 5; i++)
    {
      if(bingo[i][i] == 0) cnt++;
    }
    if(cnt == 5) total_cnt++;

    cnt = 0;
    for(int i = 1; i <= 5; i++)
    {
      if(bingo[i][6-i] == 0) cnt++;
    }
    if(cnt == 5) total_cnt++;
    
    if(total_cnt >= 3) break;
  }
  
  printf("%d\n", value_cnt);
  
  return 0;
}