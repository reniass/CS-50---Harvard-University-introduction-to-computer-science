from cs50 import get_float


def cash():
    # asking user's about change owed until his/her input will be non-negative
    while True:
        # money that we have to give away to customer
        odd_money = get_float("Change owed: ")
        if odd_money >= 0:
            break
    odd_money = odd_money * 100

    # number of coins equals 0 at the beginning
    coins = 0
    quarter = 25
    dime = 10
    nickel = 5
    penny = 1
    while odd_money > 0:

        # check if odd_money is bigger than 0.25
        if odd_money >= quarter:
            coins = coins + (odd_money // quarter)
            odd_money = odd_money - (odd_money // quarter) * quarter
        # check if odd_money is bigger than 0.1 and less than 0.25
        elif odd_money >= dime:
            coins = coins + (odd_money // dime)
            odd_money = odd_money - (odd_money // dime) * dime
        # check if odd_money is bigger than 0.05 and less than 0.1
        elif odd_money >= nickel:
            coins = coins + (odd_money // nickel)
            odd_money = odd_money - (odd_money // nickel) * nickel
        # check if odd_money is bigger than 0.01 and less than 0.05
        elif odd_money >= penny:
            coins = coins + (odd_money // penny)
            odd_money = odd_money - (odd_money // penny) * penny
    # return number of coins
    return coins


print(cash())
