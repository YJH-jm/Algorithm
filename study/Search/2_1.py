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
a = solution([1,3,2,4,2])
print(a)