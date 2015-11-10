# Counting letter frequencies in text
# By: Nathan Justice
# 11/10/15

dictionary = {}

f = open("infile1.txt", "r")

story = ""

for line in f:
    story = story + line

story = story.lower()

for char in story:
    if dictionary.has_key(char)== False:
        dictionary[char] = 0
    dictionary[char] = dictionary[char] + 1
