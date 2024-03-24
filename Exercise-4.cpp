#include <iostream>
using namespace std;
class Node{
    private:
        int obj;
        Node *prev;
        Node *next;
    public:
        void SetObj(int val);
        void SetPrevious(Node *adr);
        void SetNext(Node *adr);
        int GetObj();
        Node* GetPrevious();
        Node* GetNext();
};
void Node::SetObj(int val){
    obj = val;
}
void Node::SetPrevious(Node *adr){
    prev = adr;
}
void Node::SetNext(Node *adr){
    next = adr;
}
int Node::GetObj(){
    return obj;
}

Node* Node::GetPrevious(){
    return prev;
}

Node* Node::GetNext(){
    return next;
}

class CircularList{
    private:
        Node* head;
        Node* tail;
    public:
        CircularList();
        void InsertAtEnd(int val);
        void Delete(int val);
        void Display();
        ~CircularList();
        int Josephus(int k);
};
CircularList::CircularList(){
    head = nullptr;
    tail = nullptr;
}
void CircularList::InsertAtEnd(int val){
    Node* newNode = new Node;
    newNode->SetObj(val);
    newNode->SetPrevious(nullptr);
    newNode->SetNext(nullptr);
    if(head == nullptr){
        newNode->SetNext(newNode);
        newNode->SetPrevious(newNode);
        head = newNode;
        tail = newNode;
    }
    else{
        newNode->SetNext(head);
        newNode->SetPrevious(tail);
        head->SetPrevious(newNode);
        tail->SetNext(newNode);
        tail = newNode;
    }
}
void CircularList::Display(){
    if(head == nullptr){
        cout << "List is empty" << endl;
    }
    else{
        Node *temp = head;
        do{
            cout << temp->GetObj() << " " ;
            temp = temp->GetNext();
        }while(temp!=head);
    }
}
void CircularList::Delete(int val){
    if(head == nullptr){
        cout << "List is empty" << endl;
        return;
    }
    else{
        Node *temp = head;
        do{
            if(temp->GetObj() == val){
                if(temp == head){
                    head = head->GetNext();
                    head->SetPrevious(tail);
                    tail->SetNext(head);
                }
                else if(temp == tail){
                    tail = tail->GetPrevious();
                    head->SetPrevious(tail);
                    tail->SetNext(head);
                }
                else {
                    temp->GetPrevious()->SetNext(temp->GetNext());
                    temp->GetNext()->SetPrevious(temp->GetPrevious());
                }
                delete temp;
                return;
            }
            temp = temp->GetNext();
        }while(temp != head);
        cout << "Value not found" << endl;
    }
}
int CircularList::Josephus(int k){
    if(head == nullptr){
        cout << "List is empty" << endl;
        return -1;
    }
    Node *temp = head;
    while(temp->GetNext() != temp){
        for(int i=0; i<k-1; i++){
            temp = temp->GetNext();
        }
        Node *current = temp->GetNext();
        cout << "The person to be killed is : " << current->GetObj() << endl;
        Delete(current->GetObj());
        temp = temp->GetNext();
    }
    return temp->GetObj();
}
CircularList::~CircularList(){
    if(head == nullptr){
        return;
    }
    Node *current = head;
    do{
        Node *temp = current->GetNext();
        delete current;
        current = temp; 
    }while(current!=head);
}
int main(){
    CircularList c1;
    int people = 7;
    for(int i=0; i<people; i++){
        c1.InsertAtEnd(i+1);
    }
    cout << "People in the circle are : " << endl;
    c1.Display();
    int survivor = c1.Josephus(3);
    cout << "----------Winner from the circle is : " << endl;
    cout << survivor << endl;
}