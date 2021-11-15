def solution(prices): 
    answer = [] # 정답을 넣을 list
    
    for i in range(len(prices)):  # 기준 초 설정
        # 초기화
        sec = 0
        flag = False # 가격이 떨어지면 TRUE 값을 가지는 변수 
            
        for j in range(i+1, len(prices)): # 기준 초 i를 기준으로 그 뒤의 값
            sec += 1
            
            if prices[i] > prices[j]: # 가격이 떨어지는 경우
                answer.append(sec)
                flag = True # 가격이 떨어졌기 때문에 TRUE로 바꿈
                break
                
        if flag == False: # 가격이 떨어지지 않았을 경우
            answer.append(sec)
        
    return answer


def solution2(prices): # O(n^2) -> 시간 줄일 수 있는 풀이 생각해 볼 것 ....
    answer = []
    
    for i in range(len(prices)-1):
        cnt = 0
        for j in range(i+1, len(prices)):
            cnt+=1
            if prices[i] > prices[j]:
                break
        answer.append(cnt)
    
    answer.append(0)
    
    return answer

def solution3(prices): # stack풀이 
    len_prices = len(prices)
    answer = [0] * len_prices
    
    stack = []
    
    for i in range(len_prices):
        # 1. 스택 비지 않고, prices[top] > prices[i] 이라면 다음 반복
        # 1-1. 스택에서 마지막에 저장된 시간 top 꺼냄
        # 1-2. answer[top]에 i - top을 저장
        while stack and prices[stack[-1]] > prices[i]:
            top = stack.pop()
            answer[top] = i - top
        # 2. 스택에 현재 시간 i 저장
        stack.append(i)
    
    # 4. 만약 스택이 남아있다면, 스택이 빌 때까지 다음 반복
    while stack:

        top = stack.pop()
        answer[top] = len_prices - 1 - top
    
    return answer