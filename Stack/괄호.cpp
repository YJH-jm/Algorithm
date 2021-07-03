#include <cstdio>
#include <cstring>

const int MAX = 50+10;
char input[MAX];
char stack[MAX];

int main()
{
  int len, stack_len = 0; 
  
  scanf("%s", input);
  len = strlen(input);
  
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
        printf("NO\n");
        return 0;
      }
      
      else 
      {
        stack[stack_len-1] = 0;
        stack_len--;
      }
    }
  }
 
  if(stack_len != 0) printf("NO\n");
  else printf("YES\n");
  
  return 0;
}