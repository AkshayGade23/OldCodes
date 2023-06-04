
lst = [10, 16, 8, 12, 15, 6, 9]


def swap(lst, ind1, ind2):
    temp = lst[ind2]
    lst[ind2] = lst[ind1]
    lst[ind1] = temp


def partition(lst, low, high):
    pivot = low
    i = low+1
    j = high

    while(i < j):
        while(lst[i] <= lst[pivot]):
            i += 1

        while(lst[j] > lst[pivot]):
            j -= 1

        if(i < j):
            swap(lst, i, j)

    swap(lst, j, pivot)
    return j


def quick_sort(lst,  low, high):
    if(low < high):
        sorted_element = partition(lst, low, high)
        quick_sort(lst, low, sorted_element-1)
        quick_sort(lst, sorted_element+1, high)


quick_sort(lst, 0, len(lst)-1)
print(lst)
