# Sequence variation in APOE
# Reports substitutions in 5 patient sequences compared to a reference sequence
# By: Nathan Justice
# 11/10/15

f = open("apoe_sequences.txt", "r")

reference = f.readline()

sampleID = 0

for line in f:
    for i in range(0, len(line)):
        if reference[i] != line[i]:
            print sampleID, i, reference[i], line[i]
    sampleID = sampleID + 1
