import sys
from cs50 import get_string


def caesar():
    if len(sys.argv) != 2 or int(sys.argv[1]) < 0:
        print("Usage: python caesar.py k")
        exit(1)
    # asking user's about plaintext
    plain_text = get_string("plaintext: ")
    # variable shift store information how many place each letter included in plaintext should be shifted
    shift = int(sys.argv[1]) % 26
    cipher_text = ""
    for sign in plain_text:
        secret_letter = ""
        # checking to what numerical interval the sign belongs
        if (ord(sign) >= 65 and ord(sign) <= 90):
            secret_letter = chr(((ord(sign) - 65 + shift) % 26) + 65)
            cipher_text += secret_letter
        elif (ord(sign) >= 97 and ord(sign) <= 122):
            secret_letter += chr(((ord(sign) - 97 + shift) % 26) + 97)
            cipher_text += secret_letter
        else:
            cipher_text += sign
    print("ciphertext: " + cipher_text)


caesar()
