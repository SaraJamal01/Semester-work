import re
def alphabets(string):
    charRe = re.compile(r'[^a-b]')     # Python program for all strings starting or ending with "aa"
    string = charRe.search(string)     # Regular expression : (aa.(a+b)*) + ((a+b)*.aa)
    return not bool(string)

word = input("Enter string: ")
result = alphabets(word)
ans = re.findall("aa\Z", word)
ans1 =  re.findall("\Aaa", word)


if ans or ans1 and result:
  print("String accepted")
else:
  print("String rejected")