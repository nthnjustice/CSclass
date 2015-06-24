Hello Grader,

Unfortunately, I was unable to completely finish this homework assignment. I've built a main, that makes very little sense, but it does show most of my program is functional. 

I am able to build a linked-list of courses with data within a Semester. I am able to add Semesters of data to a Transcript. I am able to add a single Trancript to TOT, but not multiple Transcripts. 

When you test my program, however you manage to do that, you will have to move the appropriate pointers from private to public data members within each respective class. I did not write functions to pull those members out of private to be available to main. 

I feel I was overly confident with my understand of copy constructors and assignment overload functions. In retrospect, I wish I would have written the appropriate copy functions long hand - I think I would have been able to finish in time had I done that.

Main starts by building two Nodes, which will serve as classes for the linked-list. I then fill the classes with the appropriate data (courseID and grade). Next I build a semester with a term, a year, and the first class. I print the semester/class information to demonstrate the Class Semester is properly built. The next segment of code is a print sequence that demonstrates the functionality of the linked-list within Semester. 

The next line demonstrates the functionality of the function that prints the size of the linked-list in the semester.

The next block builds another class, and it adds the new class to the linked-list using my addCourse() function. 

The next line again demonstrates the functionality of my size() function.

The next line builds another instance of the linked-list with another class - which is filled with data. 

The following line builds another semester with a new linked-list with the newest build class.

The block after shows the successful construction of another semester.

The next two lines builds two transcripts with the two constructed semesters.

The next three lines declares a TOT and adds the two build transcripts.

Here is where things get ugly. This last bit of code attempts to call the lookUP() function of TOT by finding the transcript with the ID "007". I then try to print out the courseID of the first class to show TOT was set up correctly. Unfortunately I segfault.

The program compiles. Use:
g++ -Wall -Wextra TOT.h Transcript.h Semester.h TOT.cpp Transcript.cpp Semester.cpp main.cpp

Thank you very much for your time grading. I apologize for the sloppy program. 
