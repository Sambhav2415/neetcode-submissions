class Node{
public:
    unordered_map<char , Node*> children;
    bool endOfWord;
    Node(){
        endOfWord = false;
    }
};

class PrefixTree {
    Node* root;
public:
    PrefixTree() {
        root = new Node();
    }
    
    void insert(string key) {
        Node* temp = root;
        for(int i=0;i<key.size();i++){
            if(!temp->children.count(key[i])){
                temp->children[key[i]] = new Node();
            }
            temp =  temp->children[key[i]];
        }
        temp->endOfWord = true;
    }
    
    bool search(string key) {
        Node* temp = root;
        for(int i=0;i<key.size();i++){
            if(!temp->children.count(key[i])){
                return false;
            }
            temp =  temp->children[key[i]];
        }
        return temp->endOfWord;
    }
    
    bool startsWith(string key) {
        Node* temp = root;
        for(int i=0;i<key.size();i++){
            if(!temp->children.count(key[i])){
                return false;
            }
            temp =  temp->children[key[i]];
        }
        return true;
    }
};
