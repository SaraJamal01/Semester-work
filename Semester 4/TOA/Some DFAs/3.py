import re
def alphabets(string):
    charRe = re.compile(r'[^a-b]')     # Python program for all strings containing the substring "aba"
    string = charRe.search(string)     # Regular expression : (a+b)*.aba.(a+b)*
    return not bool(string)

word = input("Enter string: ")
result = alphabets(word)
substring = "aba"

if substring in word and result:
  print("String accepted")
else:
  print("String rejected")