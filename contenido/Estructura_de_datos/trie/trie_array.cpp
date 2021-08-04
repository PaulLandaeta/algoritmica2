#include <bits/stdc++.h> 

using namespace std; 

struct node {
    char currentCharacter;       
    bool isWord;
   //  int priority = 0;            
    struct node *children[27];  // [null,null,null,......,null]
    node() {
        isWord = false;
    }
}*trie; 

// Inicializar 

void init() {
    trie = new node();  // Instanciar el objeto trie
}

void insertWord(string word) {   // alba 
    node *currentNode =  trie;  
    for (int i = 0; i< word.length(); i++) { // alba
        int character = word[i] - 'a';       // i = 0 'a'-'a' = 0
        if(currentNode->children[character] == NULL ) {
            currentNode->children[character] = new node();
           // currentNode->isWord = false;
        }
      //   currentNode = max(currentNode->priority,priority);
        currentNode = currentNode->children[character];
        currentNode->currentCharacter = word[i];
    }
    currentNode->isWord = true;
}

bool searchWord(string word) {   // alto 
    node *currentNode =  trie;  
    for (int i = 0; i< word.length(); i++) {
        int character = word[i] - 'a';       // i = 0 'a'-'a' = 0
        if(currentNode->children[character] == NULL ) {
           return false;
        }
        currentNode = currentNode->children[character];
    }
    cout<<currentNode->currentCharacter<<endl;
    return currentNode->isWord;
}


/*
int findWords(string prefix) {   // alto 
    node *currentNode =  trie;  
    for (int i = 0; i< prefix.length(); i++) {
        int character = prefix[i] - 'a';       // i = 0 'a'-'a' = 0
        if(currentNode->children[character] == NULL ) {
           return 0;
        }
        currentNode = currentNode->children[character];
    }
    return currentNode->countWords;
}*/
/*
void showTrie(node currentNode ) {
    node *currentNode =  trie;  
    for (int i =0; i< 27; i++) {
        currentNode = currentCharacter = word[i];
        cout (char(i+'a'));
        showTrie(currentNode)
    }
}*/ 


void isThereWord(string word) {
    if(searchWord(word)) {
        cout<<"si existe : "<<word<<" en el trie"<<endl;
    } else {
        cout<<"No Existe :P"<<endl;
    }
}

int main() {

    // Inicializar Trie
    init();  
    string word = "auto";
    insertWord(word);
    isThereWord(word);
    word = "automovil";   
    insertWord(word);
    isThereWord("auto");
    isThereWord(word);
    return 0;
}