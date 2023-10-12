# textcompressor

A weird text compressing project

## Concept

The idea is to create a fun compressing project, with first a fun approach to it with a dumb idea

### Idea 1 : Funzipper

To compress a text file a custom way, when you read a file there are some repeated words, and if you compress the data with only one instances of each word, and a map bewteen this and some binary with a variable size depending on the number of different words.
And after have a new file format a .funzip.

#### .funzip :

at the end of the file you have a dictionnary section with a binary representation of the map between words and binary, and at the start of the file the text data until the dictionnary section.

You have some places Tag to know where you are :

- TEXT_START
- TEXT_END
- DIC_START
- DIC_END

and a tag for a \n :

- BACKSPACE

The spaces are not coded, and the words with apostrophes in them are counted as an individual file

### Idea 2 : Funzipper Comparator

A tool to know how much data you will save doing this compressor

## Programming Languages

The goal is to do the Funzipper in C++ for performances, and also for c++ training, and the Funzipper Comparator in a Web Service Friendly way, maybe c++ that compiles into WASM, but maybe python or javascript if i'm lazy.
