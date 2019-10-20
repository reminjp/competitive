import re

file = open("misc100", "r")
file.seek(0x10)
text = file.read()
file.close()

flag = "".join(re.findall(r"(.)\1{2}", text)).lower()
print(flag)
# cpaw{mgrep}
