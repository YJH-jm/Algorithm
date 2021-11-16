def solution(answers):
    answer = []
    list_1 = [1, 2, 3, 4, 5, 1, 2, 3, 4, 5]
    len_1 = len(list_1)
    list_2 = [2, 1, 2, 3, 2, 4, 2, 5, 2, 1, 2, 3, 2, 4, 2, 5]
    len_2 = len(list_2)
    list_3 = [3, 3, 1, 1, 2, 2, 4, 4, 5, 5, 3, 3, 1, 1, 2, 2, 4, 4, 5, 5]
    len_3 = len(list_3)
    index = 0
    while len(list_1) < 10000:
        list_1.append(list_1[index])
        index += 1
        if index == len_1:
            index = 0
    
    while len(list_2) < 10000:
        list_2.append(list_2[index])
        index += 1
        if index == len_2:
            index = 0

    while len(list_3) < 10000:
        list_3.append(list_3[index])
        index += 1
        if index == len_3:
            index = 0
    
    # 문제를 맞추면 갯수를 증가하는 부분 
    dict_num = {1:0, 2:0, 3:0}
    
    for i in range(len(answers)):
        if answers[i] == list_1[i]:
            dict_num[1] += 1
        if answers[i] == list_2[i]:
            dict_num[2] += 1
        if answers[i] == list_3[i]:
            dict_num[3] += 1

    new_list = sorted(dict_num.values(), reverse=True)
    max_value = new_list[0]
    for k,v in dict_num.items():
        if v == max_value:
            answer.append(k)
    answer.sort()
    return answer


def solution2(answers):
    list1 = [1, 2, 3, 4, 5]
    list2 = [2, 1, 2, 3, 2, 4, 2, 5]
    list3 = [3, 3, 1, 1, 2, 2, 4, 4, 5, 5]

    len_ans = len(answers)
    len_list1 = len(list1)
    len_list2 = len(list2)
    len_list3  = len(list3)

    index = 0
    cnt = 0
    while cnt < len_ans:
        list1.append(list1[index])
        index += 1
        cnt +=1
        if index == len_list1:
            index = 0

    index = 0
    cnt = 0
    while cnt < len_ans:
        list2.append(list2[index])
        index += 1
        cnt +=1
        if index == len_list2:
            index = 0

    index = 0
    cnt = 0
    while cnt < len_ans:
        list3.append(list3[index])
        index += 1
        cnt +=1
        if index == len_list3:
            index = 0


    dict_cnt = {1:0, 2:0, 3:0}

    for i in range(len_ans):
        if answers[i] == list1[i]:
            dict_cnt[1] += 1
        if answers[i] == list2[i]:
            dict_cnt[2] += 1
        if answers[i] == list3[i]:
            dict_cnt[3] += 1
 
    new_list = sorted(dict_cnt.values(), reverse=True)
    answer = []
    for k, v in dict_cnt.items():
        if v == new_list[0]:
            answer.append(k)
            
    return answer
    

def solution3(answers): # 더 간단한풀이, enumerate 사용할 것!
    list1 = [1, 2, 3, 4, 5]
    list2 = [2, 1, 2, 3, 2, 4, 2, 5]
    list3 = [3, 3, 1, 1, 2, 2, 4, 4, 5, 5]
    score = [0, 0, 0]
    answer = []
    
    for idx, val in enumerate(answers):
        if answers[idx] == list1[idx % len(list1)]:
            score[0] += 1
        if answers[idx] == list2[idx % len(list2)]:
            score[1] += 1
        if answers[idx] == list3[idx % len(list3)]:
            score[2] += 1

    for v in range(len(score)):
        if score[v] == max(score):
            answer.append(v+1)
        
    return answer

if __name__ == "__main__":
    answers = [1, 2, 3, 4, 5]
    print(answers)
    
    print(solution(answers))
    
