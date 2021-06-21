/*
백준 2745문제 - 진법 변환
https://www.acmicpc.net/problem/2745
*/

#include <cstdio>
#include <cstring>
const int MAX = 200;
int main()
{
  char str[MAX];
  int n, b, len, num = 1, sum = 0, tmp;
  
  scanf("%s",str);
  scanf("%d", &b);

  len = strlen(str);

  for(int i = 0; i < len; i++)
  {
    if(str[len-1-i] >= '0' && str[len-1-i] <= '9') tmp = str[len-1-i]-'0';
    else if(str[len-1-i] >= 'A' && str[len-1-i] <= 'Z') tmp = str[len-1-i]-'A'+10;
 
    sum += tmp*num;
    num *= b;
  }

  printf("%d\n", sum);
  return 0;
}