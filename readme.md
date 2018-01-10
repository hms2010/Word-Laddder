# Word Ladder
## Requirements
* C++ compiler with support of standard C++11 and above

* Python 3 interpreter

* СMake 3.0 and above version
## To install
``` 
cmake CMakeLists.txt
make
```
## Usage

```
Word_Ladder <filename>
```
_<filename\> argument must be without .dat extension. But filename must contains it._

File includes two words splitted by a space or an end-of-line char - start word and end word. It can ends with or without end-of-line.
## Examples
on Linux systems: ./Word_Ladder test.dat
on Windows systems: Words_Ladder test.dat

The input file test.dat:
```
root fact
```
The result file - test.ans: 
```
root
foot
fort
form
farm
fare
face
fact

```