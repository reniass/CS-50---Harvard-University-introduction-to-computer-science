from cs50 import get_int


def mario():
    # ask user about height in case when input is less than 0 or greater than 23 repeat until input will be proper
    while True:
        height = get_int("Height: ")
        if (height > -1) and (height < 24):
            break
    # variable rowLength store how many charachter are in each row
    row_length = height + 1
    how_many_hash = 2
    for row in range(height):
        how_many_space = row_length - how_many_hash
        # printing spaces
        for number in range(how_many_space):
            print(" ", end="")
        # printing hashes
        for number in range(how_many_hash):
            print("#", end="")
        # increment number of hashes
        how_many_hash += 1
        print()


mario()
