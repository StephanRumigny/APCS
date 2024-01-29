import cs50

while True:
    dollars = cs50.get_float("Change owed: ")
    if dollars > 0:
        cents = round(dollars * 100)
        coins = 0

        # quarter values (25)
        quarter = int(cents / 25)
        # dime value (10)
        dime = int((cents % 25) / 10)
        # nickels value (5)
        nickel = int(((cents % 25) % 10) / 5)
        # pennies value (1)
        penny = int(((cents % 25) % 10) % 5)

        # counting quantity of coins using the known value
        coins = coins + quarter
        if dime > 0:
            coins = coins + dime
        if nickel > 0:
            coins = coins + nickel
        if penny > 0:
            coins = coins + penny

        # prints the final value
        print(coins)
        break
