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