def solution(numbers, hand) :
    answer = ''
    finger = ['*','#']
    for i in numbers :
        if (i in [1,4,7]) :
            answer += 'L'
            finger[0] = i
        elif (i in [3,6,9]) :
            answer += 'R'
            finger[1] = i
        elif(i in [2,5,8,0]) :
            left_distance =distance(i,finger[0])
            right_distance =distance(i,finger[1])
            if(left_distance < right_distance) :
                answer +='L'
                finger[0] = i
            elif(left_distance>right_distance) :
                answer+='R'
                finger[1] = i
            else :
                if(hand == 'right') :
                    answer += 'R'
                    finger[1] = i
                else :
                    answer += 'L'
                    finger[0] = i
    return answer
def distance(i,finger_number) :
    if(i==1) :
        a = [0, 0]
    elif (i == 2):
        a = [0, 1]
    elif (i == 3):
        a = [0, 2]
    elif (i == 4):
        a = [1, 0]
    elif (i == 5):
        a = [1, 1]
    elif (i == 6):
        a = [1, 2]
    elif (i == 7):
        a = [2, 0]
    elif (i == 8):
        a = [2, 1]
    elif (i == 9):
        a = [2, 2]
    elif (i == '*'):
        a = [3, 0]
    elif (i == 0):
        a = [3, 1]
    elif (i == '#'):
        a = [3, 2]

    if (finger_number == 1):
        b = [0, 0]
    elif (finger_number == 2):
        b = [0, 1]
    elif (finger_number == 3):
        b = [0, 2]
    elif (finger_number == 4):
        b = [1, 0]
    elif (finger_number == 5):
        b = [1, 1]
    elif (finger_number == 6):
        b = [1, 2]
    elif (finger_number == 7):
        b = [2, 0]
    elif (finger_number == 8):
        b = [2, 1]
    elif (finger_number == 9):
        b = [2, 2]
    elif (finger_number == '*'):
        b = [3, 0]
    elif (finger_number == 0):
        b = [3, 1]
    elif (finger_number == '#'):
        b = [3, 2]

    return (a[0]-b[0])**2 + (a[1]-b[1])**2




# def distance(i,finger_number) :
#     if(i == 2) :
#         if(finger_number == 1) : return 1
#         elif(finger_number == 4) : return 1.1
#         elif (finger_number == 7):return 2.1
#         elif (finger_number == '*'):return 3.1
#         elif (finger_number == 3):return 1
#         elif (finger_number == 6):return 1.1
#         elif (finger_number == 9):return 2.1
#         elif (finger_number == '#'):return 3.1
#         elif (finger_number == 2):
#             return 0
#         elif (finger_number == 5):
#             return 1
#         elif (finger_number == 8):
#             return 2
#         elif (finger_number == 0):
#             return 3
#
#     elif (i == 5):
#         if (finger_number == 1):
#             return 1.1
#         elif (finger_number == 4):
#             return 1
#         elif (finger_number == 7):
#             return 1.1
#         elif (finger_number == '*'):
#             return 2.2
#         elif (finger_number == 3):
#             return 1.1
#         elif (finger_number == 6):
#             return 1
#         elif (finger_number == 9):
#             return 1.1
#         elif (finger_number == '#'):
#             return 2.1
#         elif (finger_number == 2):
#             return 1
#         elif (finger_number == 5):
#             return 0
#         elif (finger_number == 8):
#             return 1
#         elif (finger_number == 0):
#             return 2
#     elif (i == 8):
#         if (finger_number == 1):
#             return 2.1
#         elif (finger_number == 4):
#             return 1.1
#         elif (finger_number == 7):
#             return 1
#         elif (finger_number == '*'):
#             return 1.1
#         elif (finger_number == 3):
#             return 2.1
#         elif (finger_number == 6):
#             return 1.1
#         elif (finger_number == 9):
#             return 1
#         elif (finger_number == '#'):
#             return 1.1
#         elif (finger_number == 2):
#             return 2
#         elif (finger_number == 5):
#             return 1
#         elif (finger_number == 8):
#             return 0
#         elif (finger_number == 0):
#             return 1
#     elif (i == 0):
#         if (finger_number == 1):
#             return 3.1
#         elif (finger_number == 4):
#             return 2.1
#         elif (finger_number == 7):
#             return 1.1
#         elif (finger_number == '*'):
#             return 1
#         elif (finger_number == 3):
#             return 3.1
#         elif (finger_number == 6):
#             return 2.1
#         elif (finger_number == 9):
#             return 1.1
#         elif (finger_number == '#'):
#             return 1
#         elif (finger_number == 2):
#             return 3
#         elif (finger_number == 5):
#             return 2
#         elif (finger_number == 8):
#             return 1
#         elif (finger_number == 0):
#             return 0


print(solution([1, 2, 3, 4, 5, 6, 7, 8, 9, 0], "right"))