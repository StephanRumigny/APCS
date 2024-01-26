def main():
    # ask user for pyramid height (1-8)
    while True:
        height = get_int("Height: ")
        if 1 <= height <= 8:
            break

    # create the pyramids
    for i in range(height):
        # print left padding for pyramid
        for j in range(height - i - 1):
            print(" ", end="")

        # print # for left side of pyramid
        for j in range(i + 1):
            print("#", end="")

        # create a gap between the two sides
        print("  ", end="")

        # print # for right side of pyramid
        for j in range(i + 1):
            print("#", end="")

        # create next line
        print()


# function to get int from user
def get_int(prompt):
    while True:
        try:
            value = int(input(prompt))
            return value
        except ValueError:
            print("Error! Invalid integer.")


if __name__ == "__main__":
    main()
