'''
QUEUE/STACK - 기능개발 : https://programmers.co.kr/learn/courses/30/lessons/42586

문제 풀기 전 구현 설계
1. Queue 즉, progress가 비기 전까지 반복문을 이용하여 하루 진도 반영 
2. progress 맨 앞의 값이 100%를 달성, 즉 나갈수 있다면
    2.1 pop(0)을 이용하여 값을 빼주고 count 해준다. 이 때 speeds 값도 같이 제거 # QUEUE
       맨 앞 값이 100%가 아닐 때 까지 빼주고 count;
    2.2 맨 앞 값이 100이 아니면 1로 돌아가기 
'''
'''
풀고 난 후
1. 코드를 작성 할 때 pop을 해도 list 범위에 문제가 가지 않게 잘 설정 할 것!
'''

def solution(progresses, speeds):
    answer = []
    
    while progresses:
        #진도 갱신
        count = 0
        flag = False # 하나라도 배포가 된 것이 있으면 falg는 True값 가짐
        
        for i in range(len(progresses)):
            progresses[i] += speeds[i]
        
        while True: # 맨 앞 progresses 가 100% 넘어 배포
            if progresses and progresses[0] >= 100:
                flag = True
                count += 1 
                progresses.pop(0) 
                speeds.pop(0)
            else:
                break
                
        if progresses == False:
            break
        
        if flag: # 배포된 것이 있으면
            answer.append(count)
            
    return answer


def solution2(progresses, speeds):
    answer = []
    while progresses:
        cnt = 0
        for i in range(len(progresses)):
            progresses[i] += speeds[i]
        
        while True and progresses: 
            if progresses[0] >= 100:
                cnt += 1
                progresses.pop(0)
                speeds.pop(0)

            else:
                break
            
        if cnt != 0:
            answer.append(cnt)

    return answer
