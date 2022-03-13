
from typing import final


def get_ascii_val(num, key):

    if (num + key) > 127:
        final_val = num + key
        while(final_val > 127):
            final_val = final_val % 127 
    else:
        final_val = num + key
    
    return final_val

def decrypt_ascii_val(num,key):
    final_val = num - key
    if (final_val>127) or (final_val<0):
        while (127 < final_val < 0):
            final_val = final_val % 127
    else:
        return final_val

def encrypt(text,s):
    result = ""
    # transverse the plain text
    for i in range(len(text)):
        char = text[i]
        # Encrypt uppercase characters in plain text
        if (char.isupper()):
            result += chr((ord(char) + s-65) % 26 + 65)
        # Encrypt lowercase characters in plain text
        else:
            result += chr((ord(char) + s - 97) % 26 + 97)

    return result
#check the above function
text = "CEASER CIPHER DEMO"
s = 4

print("Plain Text : " + text)
print("Shift pattern : " + str(s))
print("Cipher: " + encrypt(text,s))


