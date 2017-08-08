import re
import string
import csv
import textract


#insert text file here:
document_text = open('lyrics.txt', 'r')
#set the text to a variable
text_string = document_text.read()

#uncomment below if you're using a pdf and put the right directory:
#text_string = textract.process("/Users/raulboquin/Desktop/pdf/memorial.pdf")

text_string = text_string.lower()



#exclude words that contain non a-z and have no more than 15 letters
#pattern = r'\b[a-z]{10,15}\b'

match_pattern = re.findall(r'\b[a-z]{1,15}\b', text_string)


#print match_pattern
frequency = {}

#loop over words in 
for word in match_pattern:
    count = frequency.get(word,0)
    frequency[word] = count + 1

wordList = sorted(frequency, key=frequency.get)

print wordList

occurencesList = frequency.values().sort()

frequency_list = frequency.keys()
xData = []
yData = []

for words in frequency_list:
	xData.append(words)
	yData.append(frequency[words])
    #print words, frequency[words]

#put in csv format - zip returns a list of tuples , example: [(word1,frquency[word1]), (word2,frequency[word2])]
DATA = zip(xData,yData)


#convert to csv:
with open("pdfCounter.csv",'wr') as resultFile:
    wr = csv.writer(resultFile)
    for item in DATA:
    	wr.writerow(item)

















