# textcompressor

A weird text compressing project

This project came from a random shower thought, i wanted to do a project in C++ involving streams and serialisation.
I wanted to play around with the possibility of serialising data but only using the bits necessary to store data.
And i thought about doing this to compress data.
I wanted to only work with what i could think of. 
So i decided to work with redundant words, and to do lossless compression.

While reading the text, each word (For this project, a word is surrounded by space) is checked if in the dictionnary, and if not insert it in. After the word is in the dictionnary, it inserts his id (an integer) as the place of the word into the new file.

After it finished interating through the file, it creates a compressed version of the text, with first the dictionnary, with the id's only using the number of bytes needed to store the max sized int.

This concept is really primitive and was more a way for me to have an idea and make it in C++.
It is not really performant, and there is a lot of possible things i could do to improve the performance.
But on some text with a lot of redundant words, it succeeds in it's goal of saving memory space.

You can run this project, by going into the mains directory, and running 'make', it will compile the c++ and run the compressor on three texts, the french constitution (2023), the miserable script and the tartuffe script.

I also created a python script to know if the compressor will be worth it on a provided text file. But for now it does not work as intended.

I think the project is at it's end. But some thing i want to add is a CLI, so you can call 'funzip file.txt' and 'funzip -d file.txt' to compress a file and decompress an archive, and maybe a CLI to know how much bytes will be saved if you use this program.
