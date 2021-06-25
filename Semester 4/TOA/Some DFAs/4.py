import re
def alphabets(string):
    charRe = re.compile(r'[^b]')     # Python program for all strings containing b's only
    string = charRe.search(string)   # Regular expression : b+
    return not bool(string)

word = input("Enter string: ")
result = alphabets(word)


if result:
  print("String accepted")
else:
  print("String rejected")