#include <iostream>
#include <string>
#include <fstream>
#include "HuffmanHeader.h"

using namespace std;

int main() {
    // Read input text from file
    ifstream inputFile("input.txt");
    string text((istreambuf_iterator<char>(inputFile)), (istreambuf_iterator<char>()));
    inputFile.close();
    // Build Huffman tree
    Huffman huffman;
    huffman.buildTree(text);
    // Encode and decode input text
    string encodedText = huffman.encode(text);
    string decodedText = huffman.decode(encodedText);
    // Write encoded text to file
    ofstream encodedFile("encoded.txt");
    encodedFile << encodedText;
    encodedFile.close();
    // Write decoded text to file
    ofstream decodedFile("decoded.txt");
    decodedFile << decodedText;
    decodedFile.close();
    // Print results
    cout << "Input text: " << text << endl;
    cout << "Encoded text: " << encodedText << endl;
    cout << "Decoded text: " << decodedText << endl;
    return 0;
}