#include <cstdio>

const int MAX = 1000+10;
int n, student[MAX][10];

int main()
{
  int maxCnt = -1, maxStudent, cnt =0;
  bool flag = false;
  scanf("%d", &n);
  for(int i = 1; i <= n; i++)
  {
    for(int j = 1; j <= 5; j++) scanf("%d", &student[i][j]);
  }
  
  for(int i = 1; i <=n; i++)
  {
    cnt = 0;
    for(int j = 1; j <=n; j++)
    {
      if(i == j) continue;
      flag = false;
      for(int k = 1; k <= 5; k++)
      {
        if(student[i][k] == student[j][k])
        {
          flag = true;
          break;
        }
      }
      if(flag) cnt++;
    }
    if(cnt > maxCnt)
    {
      maxStudent = i;
      maxCnt = cnt;
    }
  }
  printf("%d", maxStudent);
  return 0;
}