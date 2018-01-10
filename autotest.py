#!/usr/bin/python3

import getopt
import subprocess
import sys

wordLadder = "./wordLadder"
separator  = 20 * "_"
block_be   = 20 * "*"
def usage():
	print("usage: python3 autotest.py [options: --full|--correct|--incorrect]")
	print("by default: --full cases testing is selected")

def exit_status(message):
	if message == 0:
		return "CORRECT_EXIT_STATUS"
	if message == 1:
		return "INCORRECT_ARGS_NUMBER_STATUS"
	if message == 2:
		return "FILE_DOESNT_EXISTS_STATUS"
	if message == 3:
		return "KNOWN_EXCEPTION_CAUGHT_STATUS"
	if message == 4:
		return "UNKNOWN_EXCEPTION_CAUGHT_STATUS"
	return "EXIT_STATUS_CODE_NOT_FOUND"

def run_correct_tests():
	print("{}\n{}\n{}".format(block_be, "Running correct input tests (./correct)...", block_be))
	print(separator)
	path = "tests/correct/test{:d}"
	cases_num = 3

	# there are 3 cases:
	# 0 case: both words are correct; but there is no path between it
	# 1 case: both words are correct; exists path
	# 2 case: both words are correct and equal; no changes requires

	for index in range(cases_num):
		message = subprocess.call([wordLadder, path.format(index)])
		if not message:
			print("Test {} status: success".format(path.format(index)))
		else:
			print("Test {} status: failed".format(path.format(index)))
			print("Test {} exit code: {}".format(path.format(index), exit_status(message)))
		print(separator)
	print("{}\n{}\n{}".format(block_be, "Finished correct input tests (correct).", block_be))


def run_incorrect_tests():
	print("{}\n{}\n{}".format(block_be, "Running incorrect input tests (correct)...", block_be))
	path = "tests/incorrect/test{:d}"
	cases_num = 4

	# there are 4 cases:
	# 0 case: given 1 word, but 2 expected
	# 1 case: lengths of words are not equal 
	# 2 case: first word doesn't exist in dictionary, second - exists
	# 3 case: first word  exists in dictionary, second - doesn't exist

	for index in range(cases_num):
		message = subprocess.call([wordLadder, path.format(index)])
		print("Test {} exit code: {}".format(path.format(index), exit_status(message)))
		print(separator)
	print("{}\n{}\n{}".format(block_be, "Finished incorrect input tests (incorrect)", block_be))

def run_tests(options):
	if (options & 1):
		run_correct_tests()
	if (options & 2):
		run_incorrect_tests()


def main():
	try:
		opts, args = getopt.getopt(sys.argv[1:], "hfci:fciv", ["help", "full", "correct", "incorrect"])
	except getopt.GetoptError as err:
		# print help information and exit:
		print(err) # will print something like "option -a not recognized"
		usage()
		sys.exit(2)

	options = 0
	# 0 (00) - will not run tests
	# 1 (01) - will run only correct input cases
	# 2 (10) - will run only incorrect input cases
	# 3 (11) - will run full pack of tests
	for o, a in opts:
		if o == "-v":
			verbose = True
		elif o in ("-h", "--help"):
			usage()
			sys.exit()
		elif o in ("-f", "--full"):
			options = 3
		elif o in ("-c", "--correct"):
			options |= 1
		elif o in ("-i", "--incorrect"):
			options |= 2
		else:
			assert False, "unhandled option"

	if (not options): 
		options = 3
	run_tests(options)

if __name__ == "__main__":
	main()


