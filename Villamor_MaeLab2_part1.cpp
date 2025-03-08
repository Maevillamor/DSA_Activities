#include <iostream>

using namespace std;

typedef struct Node{
    string songName;
    Node *link;
}Node;

Node *createNode(string data){
    Node *newNode = new Node;
    newNode->songName = data;
    newNode->link = NULL;

    return newNode;
}

void traverse(Node *head){
    Node *temp = new Node;
    temp = head;

    cout << "Playlist ko pag naka sakay sa bus" <<endl;
    while(temp != NULL){
        cout << temp->songName<< "->"<<endl;
        if(temp->link == NULL){
            cout << "NULL"<<endl;
        }
        
        temp = temp->link;
    }
}        

Node *insertAtEnd(string data, Node *head){
    if(head == NULL){
        Node *newNode = createNode(data);
        head = newNode;
        cout << "A new node has been inserted at the end \n" << endl;
        return head;
    }
    Node *temp = new Node;
    temp = head;
    
    while(temp->link != NULL){
        temp = temp->link;
    }
    
    Node *newNode = createNode(data);
    temp->link = newNode;

    cout << "A new node has been inserted at the end \n" << endl;
    return head;
}    

Node *insertAtBeginning(string data, Node *head){
    Node *newNode = createNode(data);
    newNode->link = head;

    head = newNode;

    cout << "A new node has been inserted at the beginning \n" << endl;
    return head;
}

string insertAfter(string after, string data, Node *head){
    Node *temp = new Node;
    temp = head;

    while(temp->songName.compare(after) !=0){
        if(temp == NULL){
            return "No such song exist, please try again later.";
        }

        temp = temp->link;

    }
    Node *newNode = createNode(data);
    newNode->link = temp->link;
    temp->link = newNode;

    return "An new node has been added after " + after + "\n";

}

int main(){
    Node *head = createNode("Bawat Daan By Ebe Dancel");
    head = insertAtEnd("Sa Bawat Sandali By Amiel Sol", head);
    insertAtEnd("Starting Over Again By Nathali Cole", head);
    insertAtEnd("Bawat Piyesa By Toneejay", head);
    insertAtEnd("Ikot By October", head);

    head = insertAtBeginning("Burnout By David La Sol", head);
    head = insertAtBeginning("Unti-unti By Dharma Down", head);
    head = insertAtBeginning("Dilaw By Maki", head);
    head = insertAtBeginning("Tibok By Earl Augustin", head);


    traverse(head);
 


    return 0;
}
