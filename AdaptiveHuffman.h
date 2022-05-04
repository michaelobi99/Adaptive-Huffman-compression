#pragma once
#include "BitIO.h"
#include <cstdio>
#include <cstdlib>
#include <cctype>

const char* compressionName = "Adaptive Huffman coding, with escape codes\n";
const char* usage = "infile outfile\n";

#define END_OF_STREAM 256
#define ESCAPE 257
#define SYMBOL_COUNT 258
#define NODE_TABLE_COUNT ((SYMBOL_COUNT * 2) - 1)
#define ROOT_NODE 0
#define MAX_WEIGHT 0x8000
#define TRUE 1
#define FALSE 0

struct Tree {
	int leaf[SYMBOL_COUNT]{ 0 };
	int next_freee_node;
	struct Node {
		unsigned int weight;
		int parent;
		int child_is_leaf;
		int child;
	}nodes[NODE_TABLE_COUNT];
};


/*
initializeTree()->
when performing adaptive compression, the Huffman tree starts out very nearly empty. The only two symbols present
initially are the ESCAPE symbol and the END_OF_STREAM symbol. The ESCAPE symbol has to be included so we can tell
the expansion program that we are tramsmitting a previously unseen symbol. The END_OF_STREAM symbol is here because
it is greater than 8-bits, and our ESCAPE sequence only allows for eight bit symbols following the ESCAPE code

In addition to setting up the root node and its two children, the routine also initializes the leaf array. The
ESCAPE and END_OF_STREAM leaves are the only ones initially defined. The rest of the leaf elements are set to -1 to
show that they aren't present in the Huffman tree yet.
*/

void initializeTree(Tree &tree) {
	tree.nodes[ROOT_NODE].child = ROOT_NODE + 1;

}


void compressFile(std::fstream& input, std::unique_ptr<stl::BitFile>& output, int argc, char* argv[]) {
	int c;
	Tree tree;
	initializeTree(tree);
}


