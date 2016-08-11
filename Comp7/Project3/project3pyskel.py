#!/usr/bin/env python

#
# project3.py
# Author: [Alejandro Friedman]
# Date Created:
# Last Modified:
#
# [DESCRIPTION OF PROGRAM FUNCTION HERE]
#

# Use split to get rid of the '>' character, number, and white space at 
# the beginning of each read id in the clasification file.  
# Return just the ID string, without any extra characters.
def prepareKey(idName):
        pass


# CONSTANTS
CLASS_FILE = "rand_10.txt"
READS_FILE = "rand_10.fastq"
# update these to the full data files when you are sure your code works!  
CUTOFF = 0.8


def main():
        classes = readInClasses(CLASS_FILE)

        classified = partitionClasses(classes)

        reads = readInFastq(READS_FILE)

        avgNCount = findAvgNCount(classified, reads)

        report(avgNCount)


# Reads in the classifications file (input) into a dictionary of the form
# {id:classification ...}
# Consider using a boolean (True or False) to figure out whether each line
# is an id or a classification string: you can toggle the Boolean variable
# every time you read a line from the file to indicate whether the line 
# you just read is an id or a classification string.
#
# Use the prepareKey() function to transform an id string to a proper format
# for using it as a key for the dictionary 
#
# Return the dictionary created in this function.
def readInClasses(inputfile):
        f = open(inputfile, "r")
        classes = {}
        IDvar = ""
        for line in f:
                if line[0] == ">":
                        IDvar = line
                        IDvar = prepareKey(IDvar)
                        classes[IDvar] = ""
                else:
                        classes[IDvar] = line
        return classes

print readInClasses('rand_10.txt')
       

# Creates a dictionary named "classified", of the form
# {id:True, id:False, id:True ...}
# where the value for a key (id) is a Boolean value (True or False) 
# that tells you whether the id was classified at the genus level.
# 
# Call getScore() with the classification string as a parameter to 
# get the confidence score for the classification.  If value returned by 
# getScore() is greater than or equal to CUTOFF, it is classfied, so 
# the value for that read id in "classified" should be True. 
# Otherwise, make this value False.
# 
# Return the dictionary, "classified".
def partitionClasses(classes):
        pass


# Takes in a classification string and finds the percent certainty of
# the classification at the genus level.
#
# If the read was classified to the genus level, the list generated from 
# splitting classString on semicolons will have 12 elements, and element    
# 11 (indices in python are 0-based, but there is a trailing 
# semicolon, so look at what happens when you split this!) will be the score 
# at the genus level. 
#
# If this list has fewer than
# 12 elements, then the read was not classified to the genus level, and the
# function should return 0.0.
# Make sure that this function always returns a float.
def getScore(classString):
        pass


# Use split to get rid of the '>' character, number, and white space at 
# the beginning of each read id in the clasification file.  
# Return just the ID string, without any extra characters.
def prepareKey(idName):
        pass


# Reads in the FASTQ file (input) into dictionary of the form:
# {id:nucleotides, id:nucleotide, ...}
#
# The third and fourth lines of each read can be discarded.
# Consider using a counter and modular arithmetic to determine the lines 
# that are ids and nucleotides.
#
# The ids each contain a second block of text that should be discarded.
# Consider using the split() string method to do that.
# Also, the IDs start with an unnecessary "@" character.  Use string slicing
# to remove that first character from the ID string before you use it.
# This function should return the dictionary mapping read ids to nucleotides.
def readInFastq(inputfile):
        pass


# Determines the average percent N content of the reads that are 
# classfied at genus level and the reads that are unclassified. 
#
# Use a helper function, getPctNs(), to calculate the percent of N contents
# for a read (string). 
#
# This function should construct 
# a list of the percent N content for the classified reads (classified[id] == True), 
# and a separate list for those that are not classified (classified[id] == False).
# 
# Finally, compute the average of the percentages in each list using the 
# avgList() helper function.   You can call the avgList() function twice, 
# once for each list that you created.
#
# Return a two element list of the form 
# [AVG_PERCENT_N_for_classified_reads, AVG_PERCENT_N_for_unclassified_reads]
def findAvgNCount(classified, reads):
        pass


# Determines the percent N content of the read passed in.
# It is good defensive programming to make sure all of the characters
# in the read are capitalized. This can be accomplished using the upper()
# function.
# This function should also convert the decimal value of the percange.
# For example, if 0.002 of the nucleotides are N, then 0.2% of the nucleotides
# are N.
# Return a float. 
def getPctNs(read):
        pass


# Calculates the average of listToAverage. Assumes that all elements in the
# list are either ints or floats. 
# Returns a float.
def avgList(listToAverage):
        pass


# Prints out a description of the avgerage percent N content
# in the classified reads and the unclassified reads. 
# This function also rounds this percentage to 4 decimal places.
def report(avgNCount):
        pass


if __name__ == '__main__':
        main()
