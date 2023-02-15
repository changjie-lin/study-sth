lex-study
=========

Source code for the lex/flex tutorial on [YouTube](https://www.youtube.com/watch?v=54bo1qaHAfk).

## What is lex / flex
lex is a Lexical Analyser ("scanner" in other words) generator:

- Input is a set of regular expressions (RE)  and associated actions (written in C).
- lex transforms the REs into a deterministic finite automaton (DFA) which recoginizes the tokens from the source file (character stream) 
- Output is a table-driven scanner (lex.yy.c file).

Lex is the original lexical scanner developed by Lesk and Schmidt; Paxson's improved version is flex.

## Run code

Run ex1.l
```
# Process the lex file to generate a scanner (gets saved as lex.yy.c)
lex ex1.l

# compile the scanner and grab main() from the lex library (-ll option)
cc lex.yy.c -ll

./a.out

```
Output
```
./a.out
hello world
GOODBYE
```


Run myscanner.l
```
lex myscanner.l

cc myscanner.c lex.yy.c -o myscanner

./myscanner <config.in
```

Output
```
1
db_type is set to mysql
2
db_name is set to testdata
3
db_table_prefix is set to test_
4
db_port is set to 1099
```


## Reference
The original thesis 
http://www.cs.rpi.edu/courses/fall00/modcomp3/lex.pdf
