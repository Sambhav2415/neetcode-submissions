class Node{
public:
    unordered_map<char , Node*> children;
    bool endOfWord;
    Node(){
        endOfWord = false;
    }
};
class WordDictionary {
public:
    Node* root;
    WordDictionary() {
        root = new Node();
    }
    
    void addWord(string word) {
        Node* temp = root;
        for(int i=0;i<word.size();i++){
            if(!temp->children.count(word[i])){
                temp->children[word[i]] = new Node();
            }
            temp = temp->children[word[i]]; 
        }
        temp->endOfWord = true;
    }

    bool dfs(Node* node, string& word, int idx){
        if(node == nullptr){
            return false;
        }
        if(idx == word.size()){
            return node->endOfWord;
        }
        char ch = word[idx];
        if(ch == '.'){
            for(auto &[c,child]:node->children){
                if(dfs(node->children[c],word,idx+1)){
                    return true;
                }
            }
            return false;
        }
        if(!node->children.count(ch)){
            return false;
        }else{
            return dfs(node->children[ch] , word,idx+1);
        }
    }
    
    bool search(string word) {
        return dfs(root,word,0);
    }
};
