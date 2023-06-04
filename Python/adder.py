
sum = 0
item = []
while(True):
  user_input = input('Enter number or q for quit')
  if user_input != 'q':
      sum += int(user_input)
      item.append(int(user_input))
      print(f"Order total so far {sum}")

  else:
      for i in range(0, len(item)):
          print(f' {i+1} -> {item[i]}')
      print(f'total of numbers is {sum}.')





