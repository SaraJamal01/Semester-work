import re
def alphabets(string):
    charRe = re.compile(r'[^a-b]')     # Python program for all strings starting with "ab"
    string = charRe.search(string)     # Regular expression : ab.(a+b)*
    return not bool(string)

word = input("Enter string: ")
result = alphabets(word)
ans = re.findall("\Aab", word)

if ans and result:
  print("String accepted")
else:
  print("String rejected")
