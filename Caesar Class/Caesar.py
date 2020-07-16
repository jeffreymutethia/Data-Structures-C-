minchar = 32
maxchar = 122

def CaesarEncrypt(message, key):
  result = ""
  for i in range(len(message)):
    intchar = ord(message[i]) - minchar
    shiftedchar = (intchar + ord(key[i%len(key)]) - minchar) % (maxchar + 1 - minchar)
    result = result + chr(shiftedchar + minchar)
  return result

assert CaesarEncrypt("dog", "a") == "JUM"
