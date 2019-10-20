import sys
from Crypto.Cipher import AES
import base64


def decrypt(key, text):
    s = ""
    for i in range(len(text)):
        s += chr(
            (
                (
                    (0x7E - 0x20 + 1)
                    + (ord(text[i]) - 0x20)
                    - (ord(key[i % len(key)]) - 0x20)
                )
                % (0x7E - 0x20 + 1)
            )
            + 0x20
        )
    return s


key1 = "SECCON"
key2 = "seccon2019"
text = "FyRyZNBO2MG6ncd3hEkC/yeYKUseI/CxYoZiIeV2fe/Jmtwx+WbWmU1gtMX9m905"

cipher = AES.new(key2 + chr(0x00) * (16 - (len(key2) % 16)), AES.MODE_ECB)

t = base64.b64decode(text)
t = cipher.decrypt(t)
p = ord(t[-1:])
t = decrypt(key1, t[:-p].decode("ascii"))
print(t)
