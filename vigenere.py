import sys
from cs50 import get_string


def main():
    # checking if the number of arguments differs from 2
    if len(sys.argv) != 2:
        print("Usage: python vigenere.py k")
        exit(1)
    # checking if sign does not equal to alphabetic character
    for sign in sys.argv[1]:
        if not((ord(sign) >= 65 and ord(sign) <= 90) or (ord(sign) >= 97 and ord(sign) <= 122)):
            print("Usage: python vigenere.py k")
            exit(1)

    plain_text = get_string("plaintext: ")

    cipher = sys.argv[1]
    # create variable that will be store cipher text, at the beginning it will be empty string
    cipher_text = ""
    # variable needed to iterate over cipher[i], i = <0, len(cipher) - 1>
    i = 0
    for sign in plain_text:
        # we finish iterate over cipher then we have to start iterating from the beginning so we set i to 0
        if i == len(cipher):
            i = 0
        #  sign have lower-case alphabetical character
        if (ord(sign) >= 97 and ord(sign) <= 122):
            # cipher[i] have lower-case alphabetical character
            if (ord(cipher[i]) >= 97 and ord(cipher[i]) <= 122):
                cipher_text += chr(((ord(sign) - 97 + ord(cipher[i]) - 97) % 26) + 97)
                i += 1
            # cipher[i] have upper-case alphabetical character
            elif (ord(cipher[i]) >= 65 and ord(cipher[i]) <= 90):
                cipher_text += chr(((ord(sign) - 97 + ord(cipher[i]) - 65) % 26) + 97)
                i += 1
        #  sign have upper-case alphabetical character
        elif (ord(sign) >= 65 and ord(sign) <= 90):
            # cipher[i] have lower-case alphabetical character
            if (ord(cipher[i]) >= 97 and ord(cipher[i]) <= 122):
                cipher_text += chr(((ord(sign) - 65 + ord(cipher[i]) - 97) % 26) + 65)
                i += 1
            # cipher[i] have upper-case alphabetical character
            elif (ord(cipher[i]) >= 65 and ord(cipher[i]) <= 90):
                cipher_text += chr(((ord(sign) - 65 + ord(cipher[i]) - 65) % 26) + 65)
                i += 1
        # sign is not alphabetical character
        else:
            cipher_text += sign
    print("ciphertext: " + cipher_text)


if __name__ == "__main__":
    main()
