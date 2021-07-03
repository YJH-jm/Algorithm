#include <cstdio>
#include <cstring>

const int MAX = 50+10;
char input[MAX];
char stack[MAX];

int main()
{
  int len = strlen(input), stack_len = 0; 
  bool flag = false;
  
  scanf("%s", input);
  
  for(int i = 0; i < len; i++)
  {
    if(input[i] == '(')
    {
      stack[stack_len] = input[i];
      stack_len++;
    }
    else if(input[i] == ')')
    {
      if(stack_len <= 0) 
      {
        flag = true;
        break;
      }
      
      else 
      {
        stack[stack_len-1] = 0;
        stack_len--;
      }
    }
  }
  
  if(!flag && stack_len != 0) flag = true;
  printf(stack_len);
  if(flag) printf("NO\n");
  else printf("YES\n");
  
  return 0;
}