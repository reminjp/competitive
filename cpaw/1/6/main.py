text = "fsdz{Fdhvdu_flskhu_lv_fodvvlfdo_flskhu}"
flag = ""

for c in text:
    if ord("A") <= ord(c) and ord(c) <= ord("Z"):
        flag += chr(ord("A") + (26 + ord(c) - ord("A") - 3) % 26)
    elif ord("a") <= ord(c) and ord(c) <= ord("z"):
        flag += chr(ord("a") + (26 + ord(c) - ord("a") - 3) % 26)
    else:
        flag += c

print(flag)
# cpaw{Caesar_cipher_is_classical_cipher}
