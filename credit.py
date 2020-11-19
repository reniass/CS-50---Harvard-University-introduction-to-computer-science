from cs50 import get_int


def valid_card():
    # asking user about typing his credit card number
    credit_card_number = get_int("Number: ")
    credit_card_number = str(credit_card_number)
    first_sum_plus_second_sum = 0
    first_sum = 0
    second_sum = 0
    for i in range(len(credit_card_number)):
        if (len(credit_card_number) % 2 == 1):
            if i % 2 == 1:
                # multiply every odd number by two and store the result in variable product_of_two_number
                product_of_two_number = int(credit_card_number[i]) * 2
                # converting above variable to string
                product_of_two_number_as_a_string = str(product_of_two_number)
                for j in range(len(product_of_two_number_as_a_string)):
                    first_sum += int(product_of_two_number_as_a_string[j])
            else:
                second_sum += int(credit_card_number[i])

        else:
            if i % 2 == 0:
                # multiply every odd number by two and store the result in variable product_of_two_number
                product_of_two_number = int(credit_card_number[i]) * 2
                # converting above variable to string
                product_of_two_number_as_a_string = str(product_of_two_number)
                for j in range(len(product_of_two_number_as_a_string)):
                    first_sum += int(product_of_two_number_as_a_string[j])
            else:
                second_sum += int(credit_card_number[i])
    # adding first_sum and second_sum to each other
    first_sum_plus_second_sum = first_sum + second_sum
    # checking if card_number is valid
    if first_sum_plus_second_sum % 10 == 0:
        # checking if credit card is AMERICAN EXPRESS
        if (len(credit_card_number) == 15) and (credit_card_number[0] == '3' and
                                                (credit_card_number[1] == '4' or credit_card_number[1] == '7')):
            print("AMEX")
        # checking if credit card is MASTERCARD
        elif (len(credit_card_number) == 16) and (credit_card_number[0] == '5' and
                                                  (credit_card_number[1] == '1' or credit_card_number[1] == '2' or credit_card_number[1] == '3' or credit_card_number[1] == '4' or credit_card_number[1] == '5')):
            print("MASTERCARD")
        # checking if credit card is VISA
        elif ((len(credit_card_number) == 13 or len(credit_card_number) == 16) and credit_card_number[0] == '4'):
            print("VISA")
    # checking if credit card is invalid
    else:
        print("INVALID")


valid_card()
