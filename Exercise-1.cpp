#include <iostream>
using namespace std;
class Node
{
private:
    int object;
    Node *next;
    Node *previous;

public:
    int GetData();
    void SetData(int data);
    Node *GetNext();
    void SetNext(Node *nextNode);
    Node *GetPrevious();
    void SetPrevious(Node *prevNode);
};
void Node::SetData(int data){
    object = data;
}
void Node::SetNext(Node *nextNode){
    next = nextNode;
}void Node::SetPrevious(Node *prevNode){
    previous = prevNode;
}
int Node::GetData(){
    return object;
}
Node* Node::GetNext(){
    return next;
}
Node* Node::GetPrevious(){
    return previous;
}
int main()
{
}