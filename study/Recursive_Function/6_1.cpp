/*
백준 10829문제 - 이진수 변환
https://www.acmicpc.net/problem/10829
*/
#include <cstdio>

const int MAX = 60;
int result[MAX] = {0,}, len_res = 0;

void getBinary(long long int x)
{
  if(x == 0) return;
  
  result[len_res++] = x % 2;
  getBinary(x/2);
}

int main()
{
  long long int n;
  scanf("%lld", &n);
  getBinary(n);
  
  for(int i = len_res-1; i >= 0; i--)
  {
    printf("%d", result[i]);
  }

  return 0;
}