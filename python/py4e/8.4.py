"""
Open the file romeo.txt and read it line by line. For each line,
split the line into a list of words using the split() method.
The program should build a list of words. For each word on each line
check to see if the word is already in the list and if not append it
to the list. When the program completes, sort and print the resulting
 words in alphabetical order.
"""



fname = input("Enter file name: ")
fh = open(fname)
lst = list()#完整的则是list(fh)，把fh读取的内容转换成列表
for line in fh:#一行行读取fh打开的文档
    words = line.rstrip().split()#将从fh中读取的内容末尾指定字符删除（默认为空格）且对字符串切片赋给word
    for stuff in words :   #从word中读取值赋给stuff
        if stuff in lst :  #判断stuff是否在lst中
            continue      #如果在，则跳出循环
        else :
            lst.append(stuff)  #否则把stuff内容添加到lst末尾
lst.sort() #sort()->分类，把读进lst()中的句子，按ASCII顺序排列
print (lst)
