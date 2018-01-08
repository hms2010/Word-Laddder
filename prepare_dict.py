#!/usr/bin/python3
# python 3.* ver.

import sys
import os
import getopt

def usage():
	print("usage: prepare_dict.py ---input=<input dictionary file name> --output=<result file name>")

def dict_proc(ifname, ofname):
	fin = open(ifname, 'r')
	words = fin.read().split()
	fin.close()
	word_dict = dict()
	for word in words:
		word_len = len(word)
		word_dict[word_len] = word_dict.get(word_len, [])
		word = word.lower()
		word_dict[word_len].append(word)

	os.mkdir("{}".format(ofname))
	for key in word_dict:
		fout = open("{}/{}".format(ofname, key), "w")
		for elem in word_dict[key]:
			fout.write("{}\n".format(elem))
		fout.close()

def main():
	try:
		opts, args = getopt.getopt(sys.argv[1:], "hio:v", ["help", "input=", "output="])
	except getopt.GetoptError as err:
		# print help information and exit:
		print(err) # will print something like "option -a not recognized"
		usage()
		sys.exit(2)
	input_file = None
	output_file = None
	verbose = False
	for o, a in opts:
		if o == "-v":
			verbose = True
		elif o in ("-h", "--help"):
			usage()
			sys.exit()
		elif o in ("-i", "--input"):
			input_file = a
		elif o in ("-o", "--output"):
			output_file = a
		else:
			assert False, "unhandled option"
	dict_proc(input_file, output_file)
	
if __name__ == "__main__":
	main();