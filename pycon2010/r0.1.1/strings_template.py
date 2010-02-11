import string
msg = string.Template('the square of the $number is $square')
for number in range(10):
    square = number * number
    print msg.substitute(locals())

msg = string.Template('This is different way: $number * $number = $square')
for num in range(10):
    print msg.substitute(number=num, square=num*num)
