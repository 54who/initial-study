"""
Write a program that prompts for a file name,
then opens that file and reads through the file,
and print the contents of the file in upper case.
Use the file words.txt to produce the output below.
"""



fname = input("Enter file name: ")  #提示输入内容并赋给fname
try :                               #try：except：else：称为异常处理
    fh = open(fname)                #尝试打开fname
except :
    print ("File cannot opended;" , fname)#失败则输出

content = fh.read().rstrip()        #读取fh且去除末尾空格
print (content.upper())             #把content中的小写字母转换成大写字母打印
