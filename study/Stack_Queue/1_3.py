'''
QUEUE/STACK - 다리를 지나는 트럭 : https://programmers.co.kr/learn/courses/30/lessons/42583

1. Queue라는 list 변수에는 현재 지나고 있는 차들을 넣음
   cur_weight , 현재 다리에 있는 차들의 총 무게
   cur_time라는 list에는 Queue에 있는 차들이 머문 시간
   --
2. cur_time의 맨 앞의 값이 bridge_length와 같으면 pop!
3. truck_weight가 비어있고, Queue가 비어있을 때 까지 반복
    3-1.만약 Queue의 길이가 bridge_length보다 짧고 현재 들어가려고 하는 차의 무게를 합쳤을 때
    weight보다 작다면 Queue와 cur_time에 추가
    3-2 그렇지 않다면 continue
    

'''

def solution(bridge_length, weight, truck_weights):
    answer = 0
    Queue = []
    cur_weight = 0
    cur_time = []
    
    while True:
        answer += 1
        if cur_time and cur_time[0] >= bridge_length:
            cur_time.pop(0)
            cur_weight -= Queue[0]
            Queue.pop(0)
        
        if len(truck_weights) == 0 and len(Queue) == 0:
            break
            
        #대기 트럭에 값이 있고 다리에 차가 충분히 차지 않았다면
        if  truck_weights and len(Queue) < bridge_length and (cur_weight + truck_weights[0]) <= weight:
            cur_weight += truck_weights[0]
            Queue.append(truck_weights[0])
            truck_weights.pop(0)
            cur_time.append(0)

            
        for t in range(len(cur_time)):
            cur_time[t] += 1
            
    return answer


def solution2(bridge_length, weight, truck_weights):
    answer = 0

    cur_length = 0
    cur_weight = 0
    on_bridge = []
    on_bridge_time = []
    while truck_weights or on_bridge:
        idx = 0
        answer += 1
        
        if on_bridge:  

            if  on_bridge_time[0] == bridge_length:
                cur_length -= 1
                a = on_bridge.pop(0)
                # print(" ---- ", a )
                cur_weight -= a
                on_bridge_time.pop(0)
                
            for i in range(len(on_bridge)):
                on_bridge_time[i] += 1


        if truck_weights and cur_length + 1 <= bridge_length and cur_weight + truck_weights[0] <= weight:
            cur_weight += truck_weights[0]
            cur_length += 1
            on_bridge.append(truck_weights[0])
            on_bridge_time.append(1)
            truck_weights.pop(0)

    return answer


if __name__ == "__main__":
    bridge_length = 2
    weight = 10
    truck_weights = [7,4,5,6]


    bridge_length = 100
    weight = 100
    truck_weights = [10,10,10,10,10,10,10,10,10,10]	

    print(solution(bridge_length, weight, truck_weights))