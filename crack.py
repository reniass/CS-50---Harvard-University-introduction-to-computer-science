import crypt
import sys
import string

# variable alphabet include all lowercase and uppercase letters
alphabet = string.ascii_letters


def main():
    # checking if there is no more that two command line arguments
    if len(sys.argv) != 2:
        print("Usage: python crack.py hash")
        exit(1)
    # loading from command line second argument as a hash
    hash_chain = sys.argv[1]
    # checking first possible option, password is one-letter
    password = ""
    for i in alphabet:
        password += i
        if crypt.crypt(password, "50") == hash_chain:
            return password
        password = ""
    # checking second possible option, password is two-letter
    for i in alphabet:
        password += i
        for j in alphabet:
            password += j
            if crypt.crypt(password, "50") == hash_chain:
                return password
            password = ""
            password += i
        password = ""
    # checking third possible option, password is three-letter
    for i in alphabet:
        password += i
        for j in alphabet:
            password += j
            for k in alphabet:
                password += k
                if crypt.crypt(password, "50") == hash_chain:
                    return password
                password = ""
                password += i
                password += j
            password = ""
            password += i
        password = ""
    # checking fourth possible option, password is four-letter
    for i in alphabet:
        password += i
        for j in alphabet:
            password += j
            for k in alphabet:
                password += k
                for l in alphabet:
                    password += l
                    if crypt.crypt(password, "50") == hash_chain:
                        return password
                    password = ""
                    password += i
                    password += j
                    password += k
                password = ""
                password += i
                password += j
            password = ""
            password += i
        password = ""


if __name__ == '__main__':
    print(main())
