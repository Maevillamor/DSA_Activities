#include <iostream>
using namespace std;

typedef struct Node {
    string songName;
    Node* link;
} Node;

// Create a new node
Node* createNode(string data) {
    Node* newNode = new Node;
    newNode->songName = data;
    newNode->link = NULL;
    return newNode;
}

// Traverse the linked list
void traverse(Node* head) {
    Node* temp = head;
    cout << "My Playlist" << endl;
    while (temp != NULL) {
        cout << temp->songName << "->" << endl;
        if (temp->link == NULL) {
            cout << "NULL" << endl;
        }
        temp = temp->link;
    }
}

// Insert at the end
Node* insertAtEnd(string data, Node* head) {
    if (head == NULL) {
        Node* newNode = createNode(data);
        head = newNode;
        cout << "A new node has been inserted at the end\n" << endl;
        return head;
    }
    Node* temp = head;
    while (temp->link != NULL) {
        temp = temp->link;
    }
    Node* newNode = createNode(data);
    temp->link = newNode;
    cout << "A new node has been inserted at the end\n" << endl;
    return head;
}

// Insert at the beginning
Node* insertAtTheBeginning(string data, Node* head) {
    Node* newNode = createNode(data);
    newNode->link = head;
    head = newNode;
    cout << "A new node has been inserted at the beginning \n" << endl;
    return head;
}

// Insert after a given node
string insertAfter(string after, string data, Node* head) {
    Node* temp = head;
    while (temp != NULL && temp->songName != after) {
        temp = temp->link;
    }

    if (temp == NULL) {
        return "No such song exists, please try again later.";
    }

    Node* newNode = createNode(data);
    newNode->link = temp->link;
    temp->link = newNode;

    return "A new node has been added after " + after + "\n";
}

// Delete node at the end
string deleteAtEnd(Node* &head) {
    if (head == NULL) {
        return "The linked list is empty\n";
    }

    // If there is only one node
    if (head->link == NULL) {
        delete head;
        head = NULL;
        return "The head has been deleted\n";
    }

    // Traverse to the second to last node
    Node* temp = head;
    while (temp->link != NULL && temp->link->link != NULL) {
        temp = temp->link;
    }

    // Delete the last node
    delete temp->link;
    temp->link = NULL;
    return "A node has been deleted at the end\n";
}

int main() {
    // Create a linked list
    Node* head = createNode("Starting Over Again by Natalie Cole");
    head = insertAtEnd("Die With A Smile by Bruno Mars, Lady Gaga", head);
    head = insertAtEnd("Yellow by Coldplay", head);
    head = insertAtEnd("Glue Song by Beabadoobee", head);
    head = insertAtEnd("Bawat Daan by Ebe Dancel", head);
    head = insertAtTheBeginning("Burnout by Sugarfree", head);
    head = insertAtTheBeginning("Tibok by Earl Agustin", head);
    head = insertAtTheBeginning("18 by One Direction", head);
    head = insertAtTheBeginning("Lighters by Bad Meets Evil, Bruno Mars", head);

    // Display the playlist
    traverse(head);

    // Insert after certain songs
    cout << insertAfter("Burnout by Sugarfree", "Ikot by October", head);
    cout << insertAfter("Tibok by Earl Agustin", "Multo by Cup Of Joe", head);
    cout << insertAfter("18 by One Direction", "Inner Child by Toneejay", head);

    // Display the updated playlist
    traverse(head);

    // Delete the last node
    cout << deleteAtEnd(head);
    traverse(head); // Show the updated list after deletion

    return 0;
}
