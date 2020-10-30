#include<bits/stdc++.h>

using namespace std;

#define ll long long

const int ANGKA_SIZE = 10;

// trie node 
struct TrieNode{
    struct TrieNode *children[ANGKA_SIZE]; 

    // isEndOfWord is true if the node represents 
    // end of a word 
    bool isEndOfWord;
    int isPrefix;
    
    // buat construct trie
    TrieNode(){
    	isEndOfWord = 0;
    	isPrefix = 0;
    	for(int i = 0; i < 10; i++){
    		children[i] = NULL;
		}
	}
}; 


void insert(struct TrieNode *node, string key){ 
    if(key == ""){
    	// mark last node as leaf 
    	node->isEndOfWord = true;
	}
	else{
		node->isPrefix++;
		int ch = key[0] - '0';
		if(node->children[ch] == NULL){
			node->children[ch] = new TrieNode();
		}
		key.erase(key.begin());
		insert(node->children[ch], key);
	}
} 

 
bool search(struct TrieNode *node, string key){
	
	if(key == ""){
		if(node->isPrefix == 0){
			// klo gk ada lanjutannya lagi berarti 1
			return 1;
		}
		else{
			return 0;
		}
	}
	else{
		int ch = key[0] - '0';
		if(node->children[ch] == NULL){
			node->children[ch] = new TrieNode();
		}
		key.erase(key.begin());
		return search(node->children[ch], key);
	}
} 

int main(){
	
	int t, n;
	cin >> t;
	while(t--){
		
		cin >> n;
		
		struct TrieNode *root = new TrieNode();
		
		// Construct trie
		string str, arr[n+5];
		for(int i = 0; i < n; i++){
			cin >> str;
			arr[i] = str;
			insert(root, str);
		}
		
		int valid = 1;
		for(int i = 0; i < n; i++){
			valid = search(root, arr[i]);
			if(valid == 0) break;
		}
		if(valid == 1){
			cout << "YES" << endl;
		}
		else{
			cout << "NO" << endl;
		}
	}
	
	return 0;
}