# Lab5

## About

This software is made to be a console program.

Compile it by calling make in the src folder.

Run it with the syntax: ./program [k] file.txt [b]
where [k] and [b] represent positive integers, and file.txt is a text file acting as the corpus to ai trains on.

The program trains an Ai that uses the text in file.txt to try and create a string of text of length [b]. It is trained on substrings of the file.txt file of length [k]. It does this by creating a datastructure that holds every substring of length [k] (k-gram), the frequency of which the k-gram appears and which character most frequently follows which we call [c]. It then begins generating the sentence by starting with the most frequent k-gram, adding to it [c] then using the k-gram ending in [c] that it has generated to generate the next character. This is done until a sentence of length [b] is generated.

If the text file does not contain a k-gram that the Ai generates then the Ai will not be able to generate the next character and so the sentence may not always be of length [b].

## Code explanation

The code is seperated into two classes Gram_map and Ai.

Gram_map acts as the datastructure containing pairings of a k-gram, its frequency, and the the most likely character to follow it. The functionality is bare-bones but extensible. As it is it is only possible to add an element, get the most frequent element, and get the most likely element given a k-gram. The last of which ideally would be would be replaced by some kind of iterator so that the user can perform similar actions by themselves.

The Ai class uses the Gram_map. It has two methods. One that trains the model and one that generates a text given a model.

## Limitations

As mentioned earlier, if the text file does not contain a k-gram the Ai generates it will not be able to generate the next character.
This could be fixed by generating a random character from the corpus or by training the Ai class on a smaller k gram for those cases.
