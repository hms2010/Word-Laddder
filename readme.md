## Word Ladder
### Requirements
* C++ compiler with support of standard C++11 and above

* Python 3 interpreter

* СMake 3.0 and above version
### To install
```commandline 
cmake CMakeLists.txt
make
```
The program is ready to use.
### Prepairing dictionary
Usage:
```commandline
python3 prepare_dict.py --input=<input dictionary file name> --output=<result file name>
```

Example:
```commandline
python3 prepare_dict.py --input=default.dict --output=default
```
The result of works:
default/{words length} - files in directory "default" named by words length they contains.
### Usage of _wordLadder_
```commandline
wordLadder <filename>
```
_<filename\> argument must be without .dat extension. But filename must contains it._

File includes two words splitted by a space or an end-of-line char - start word and end word. It can ends with or without end-of-line.
### Examples
See files: example/test.dat, example.ans

on Linux systems: ./wordLadder test
on Windows systems: wordLadder test

The input file test.dat:
```text
root fact
```
The result file - test.ans: 
```text
root
foot
fort
form
farm
fare
face
fact

```

### Run tests
You can use autotest.py to run the tests. 

Usage:
```commandline
python3 autotest.py [options: --full|--correct|--incorrect]"
```
Options:
* -h, --help - prints usage
* -c, --correct - run tests with correct input file (creates test{index}.ans in tests/correct)
* -i, --incorrect - run tests with incorrect input file (doesn't create any files; just print error message in stdout)
* -f, --full - run all tests


Example:
```commandline
python3 autotest.py --correct
```
The result of works:
```text
********************
Running correct input tests (./correct)...
********************
____________________
Test tests/correct/test0 status: success
____________________
Test tests/correct/test1 status: success
____________________
Test tests/correct/test2 status: success
____________________
********************
Finished correct input tests (correct).
********************

```