#include <bits/stdc++.h>
using namespace std;


// Time Complexity of building a trie is O(N*avg(L))
// N -> no. of strings to be inserted 
// avg(L) -> average length of strings 


// structure of a trie node -> 

// 1. it contains the character that the node represents in the trie
// 2. every node of a trie can be connected to at most 26 alphabets a - z for doing that 
// every node should contain an array of pointers to the trie node type 
// 3. a boolean variable to distiguish the node as the end of a word

class TrieNode{
    public:
    char data;
    TrieNode *children[26];
    bool isTerminal;

    TrieNode(char data){
        this -> data = data;

        for(int i = 0; i < 26; i++){
            children[i] = NULL;
        }
        
        isTerminal = false;
    }
};

// T.C -> O(L) L -> Length of the word
// How to insert a string in a trie? 

// 1. if the character (node) is present go to that node and check for the next character (node) 
// (if the index of children vector is null signifies there is no node and if it is not null signifies there is a node of index + 'a' character)
// 2. else create a new node for the character and connect it to the previous node and go to the new node
// 3. repeat until all the characters are inserted and mark the end of the word (isTerminal) true for the last character


void insertWord(TrieNode *root, string word){
    if(word.size() == 0){
        root -> isTerminal = true;
        return ;
    }

    char ch = word[0];
    int index = ch - 'A';


    TrieNode *child;

    if(root -> children[index] != NULL){
        child = root -> children[index];
    }else{
        child = new TrieNode(ch);
        root -> children[index] = child;
    }
    
    insertWord(child, word.substr(1));
}

// T.C -> O(L) L -> Length of the word
// How to search for a word in Trie?

// 1. Start from the root node and check if the character is present (index for the character in the children vector of the root is not null) 
// 2. if it is present repeat it for the next character until the whole word is completed with the current character as the new root
// 3. else if it is null return false
// 4. when the whole word is completed check if the end of word (isTerminal) for the root is true or not
// 5. return true (isPresent) if isTerminal is true
// 6. else return false (Absent) 


bool searchWord(TrieNode *root, string word){ 
    if(word.size() == 0){
        if(root -> isTerminal){
            return true;
        }else{
            return false;
        }
    }

    int index = word[0] - 'A';
    TrieNode *child;

    if(root -> children[index] != NULL){
        child = root -> children[index];
        return searchWord(child, word.substr(1));
    }else{
        return false;
    }
}

// T.C -> O(L) L -> Lenght of the word 
// How to delete a word from Trie?

// We do not remove the nodes from the trie we just make isTerminal or end of word false for the given word.
// 1. Search for the word and go till the last node / character of the word 
// 2. Mark the isTerminal or End of Word false for the node

void deleteWord(TrieNode *root, string word){
    if(word.size() == 0){
        root -> isTerminal = false;
        return ;
    }

    TrieNode *child;
    int index = word[0] - 'A';

    if(root -> children[index] != NULL){
        child = root -> children[index];
        deleteWord(child, word.substr(1));
    }else{
        cout << "Trying to delte a word that is not present in the Trie" << endl;
        return ;
    }
}


int main(){
    TrieNode *root = new TrieNode('-');
    insertWord(root, "CODING");
    insertWord(root, "CODE");
    insertWord(root, "CODER");
    insertWord(root, "CODEHELP");
    insertWord(root, "BABY");

    if(searchWord(root, "CODE")){
        cout << "Present" << endl;
    }else{
        cout << "Absent" << endl;
    }

    deleteWord(root, "CODERI");

    if(searchWord(root, "CODE")){
        cout << "Present" << endl;
    }else{
        cout << "Absent" << endl;
    }
}
