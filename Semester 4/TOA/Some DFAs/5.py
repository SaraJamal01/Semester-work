import re
def alphabets(string):
    charRe = re.compile(r'[^a-b]')   # Python program for all strings containing at least one occurence of aa and bb
    string = charRe.search(string)   # Regular expression : ((a+b)*aa(a+b)*bb(a+b)*) + ((a+b)*bb(a+b)*aa(a+b)*)
    return not bool(string)

word = input("Enter string: ")
result = alphabets(word)
aa = "aa"
bb = "bb"

if aa in word and bb in word and result:
  print("String accepted")
else:
  print("String rejected")