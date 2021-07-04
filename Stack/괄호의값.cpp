# include <cstdio>
# include <cstring>

const int MAX = 30+10;
char data[MAX];
int stack[MAX];

int main()
{
  int stack_len = 0, input_len;
  bool flag = false; // flag = true면 괄호 짝이 안 맞는 경우
  scanf("%s",data);
  
  input_len = strlen(data);
  
  for(int i = 0; i < input_len; i++)
  {
    if(data[i] == '(') stack[stack_len++] = -2;
    else if(data[i] == '[') stack[stack_len++] = -3;
    else if(data[i] == ')')
    {
      if(stack_len >= 2 && stack[stack_len-1] > 0 && stack[stack_len-2] == -2)
      {
        stack[stack_len-2] = stack[stack_len-1]*2;
        stack[stack_len-1] = 0;
        stack_len--;
      }
      else if(stack_len >= 1 && stack[stack_len-1] == -2)
      {
        stack[stack_len-1] = 2;
      }
      else
      {
        flag = true;
        break;
      }
    }
    else if(data[i] == ']')
    {
      if(stack_len >= 2 && stack[stack_len-1] > 0 && stack[stack_len-2] == -3)
      {
        stack[stack_len-2] = stack[stack_len-1]*3;
        stack[stack_len-1] = 0;
        stack_len--;
      }
      else if(stack_len >= 1 && stack[stack_len-1] == -3)
      {
        stack[stack_len-1] = 3;
      }
      else
      {
        flag = true;
        break;
      }
    }

    
    if(stack_len >= 2 && stack[stack_len-1] > 0 && stack[stack_len-2] >0)
    {
      stack[stack_len-2] += stack[stack_len-1];
      stack[stack_len-1] = 0;
      stack_len--;
    }
  }
  
  if(stack_len != 1 || (stack_len == 1 && stack[stack_len-1] < 0)) flag = true;
  if(flag) printf("0\n");
  else printf("%d\n", stack[stack_len-1]);
  return 0;
}