from cs50 import get_int


def mario():
    # ask user about height in case when input is less than 0 or greater than 23 repeat until input will be proper
    while True:
        height = get_int("Height: ")
        if (height > -1) and (height < 24):
            break
    # variable rowLength store how many charachter are in each row
    row_length = height
    how_many_hashes = 1
    for row in range(height):
        # variable store how many space in the actual row we print on the output
        how_many_spaces = row_length - how_many_hashes
        # printing spaces
        for number in range(how_many_spaces):
            print(" ", end="")
        # printing hashes
        for number in range(how_many_hashes):
            print("#", end="")
        print("  ", end="")
        # printing hashes
        for number in range(how_many_hashes):
            print("#", end="")
        print()
        # increment number of hashes
        how_many_hashes += 1


mario()
