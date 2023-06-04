def two_elevator():
    a = int(input())
    b = int(input())
    c = int(input())

    def which_elevator_tocall(a, b, c):
        time_1elevator = a-1
        if(c-b < 0):
            time_2elevator = ((c-b) * -1) + (c-1)
        else:
            time_2elevator = ((c-b) * -1) + (c-1)
            
        if(time_1elevator > time_2elevator):
            return 2
        elif(time_1elevator == time_2elevator):
            return 3
        else:
            return 1

    print(which_elevator_tocall(a, b, c))




test_cases = int(input())

while(test_cases > 0):
    two_elevator()
