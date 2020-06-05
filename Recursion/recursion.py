# recursive factoring function in Python

def factor(num, div):
    fac = 0
    if num % div == 0: #c heck if div is a factor of num
        fac = factor(num//div,div) # call factor function recursively if true
        fac += 1 # increment factor count upon return
    return(fac)

# take user input, call factoring function
number = int(input("Enter number to be factored: "))
divisor = int(input("Enter factor: "))
fac_count = factor(number, divisor)

# output results
print(str(divisor) + " factors into " + str(number) + " " + str(fac_count) + " times.")
