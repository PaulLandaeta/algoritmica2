// Santiago está aprendiendo inglés y él está anotando cada palabra que está aprendiendo.
// Ahora él se pregunta cuántas palabras con el prefijo X aprendió. 

// Hints. Trie porque guardaremos palabras y porque se necesita los prefijos

#include <bits/stdc++.h> 

using namespace std; 

struct node {
    char currentCharacter;       // 'a'
    bool isWord;                // false 
    int countWords = 0; 
    struct node *children[27];  // sus nodos hijos  [null,null,null.....] 
}*trie; 

// Inicializar 

void init() {
    trie = new node();
    trie->isWord = false;
    trie->countWords = 0;
}

void insertWord(string word) {   // alto 
    node *currentNode =  trie;  
    for (int i = 0; i< word.length(); i++) {
        int character = word[i] - 'a';       // i = 0 'a'-'a' = 0
        if(currentNode->children[character] == NULL ) {
            currentNode->children[character] = new node();
            currentNode->children[character]->countWords = 0;
        }
        currentNode = currentNode->children[character];
        // cout<< "Insertanto el caracter "<< word[i]<< endl;
        currentNode->currentCharacter = word[i];
        currentNode->countWords++;
        currentNode->isWord = false; // llevamos al constructor 
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
    return currentNode->isWord;
}



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
}

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
    string word = "alto";
    insertWord(word);
    isThereWord(word);
    word = "automovil";   
    insertWord(word);
    isThereWord("auto");
    isThereWord(word);
    return 0;
}