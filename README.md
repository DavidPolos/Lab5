# Lab5

## About

This software is made to be a console program.

Compile it by calling make in the src folder.

Run it with the syntax: ./program [k] file.txt [b]
where [k] and [b] represent positive integers, and file.txt is a text file.

The program trains an artifical idiot (Ai) that uses the text in file.txt to try and create a string of text of length [b]. It is trained on substrings of the file.txt file of length [k]. It does this by creating a datastructure that holds every substring of length [k] (k-gram), the frequency of which the k-gram appears and which character most frequently follows which we call [c]. It then begins generating the sentence by starting with the most frequent k-gram, adding to it [c] then using the k-gram ending in [c] that it has generated to generate the next character. This is done until a sentence of length [b] is generated.

If the text file does not contain a k-gram that the Ai generates then the Ai will not be able to generate the next character and so the sentence may not always be of length [b].
