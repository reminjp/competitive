text = "ruoYced_ehpigniriks_i_llrg_stae"

for key in range(1, len(text) + 1):
  flag = ""
  for i in range(0, len(text), key):
    flag += text[i:min(len(text), i + key)][::-1]
  flag = "cpaw{" + flag + "}"
  print(flag)
