#!/usr/bin/python3

import getopt
import subprocess

def usage():
	print("usage: python3 autotest.py [options: --full|--correct|--incorrect]")
	print("by default: full cases testing is selected")
	print("")

def run_tests(options):
	if (options && 1):
		print("Running correct input tests (./correct)...")
		path = "./correct/test{:d}.dat"
		cases_num = 3

'''
		there are 3 cases:
		0 case: both words are correct; but there is no path between it
		1 case: both words are correct; exists path
		2 case: both words are correct and equal; no changes requires
'''
		for index in range(cases_num):
			if (!subprocess.call(["../wordLadder", path.format(index)])):
				print("Test {} status: success".format(path.format(index)))
			else:
				print("Test {} status: failed".format(path.format(index)))
		print("Finished correct input tests (./correct).")
	if (options && 2):
		rint("Running incorrect input tests (./correct)...")
		path = "./incorrect/test{:d}.dat"
		cases_num = 4

'''
		there are 7 cases:
		0 case: given 1 word, but 2 expected
		1 case: lengths of words are not equal 
		2 case: first word doesn't exist in dictionary, second - exists
		3 case: first word  exists in dictionary, second - doesn't exist
'''
		for index in range(cases_num):
			if (!subprocess.call(["../wordLadder", path.format(index)])):
				print("Test {} status: success".format(path.format(index)))
			else:
				print("Test {} status: failed".format(path.format(index)))
		print("Finished incorrect input tests (./correct).")


def main():
	try:
		opts, args = getopt.getopt(sys.argv[1:], "hfci:v", ["help", "full", "correct", "incorrect"])
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

	if (!options): 
		options = 3
	run_tests();

if __name__ == "__main__":
	main()


