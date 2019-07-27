#include <iostream>
using namespace std;

struct node
{
    node *next;
    int data;
};

void insert_into_list(int data, node *&head, node *&tail)
{
    node *temp;
    if((head == nullptr)&&(tail == nullptr))
    {
        temp = new node;
        temp->data = data;
        temp->next = nullptr;
        head = tail = temp;
    }
    else
    {
        temp = new node;
        temp->data = data;
        temp->next = nullptr;
        tail->next = temp;
        tail = temp;
    }
}

void delete_from_list(node *&head, node *&tail)
{
    node *temp;
    if((head == nullptr)&&(tail == nullptr))
    {
        std::cout<<"Empty list\n";
    }
    else if(head->next == nullptr)
    {
        temp = head;
        std::cout<<"Deleted element"<<temp->data;
        std::cout<<"\n";
        delete(temp);
        head = tail = nullptr;

    }
    else
    {
        temp = head;
        while(temp->next != tail)
        {
            temp = temp->next;
        }
        std::cout<<"Deleting element "<<tail->data;
        std::cout<<"\n";
        delete(tail);
        tail = temp;
        tail->next = nullptr;
    }

}

void priority_delete(int data, node *&head, node *&tail) //Works only if data is present in the queue
{
    node *temp, *temp2;
    if(head->data == data)
    {
        temp2 = head;
        head = head->next;
    }
    else {
        temp = head;
        while ((temp->next)->data != data) {
            temp = temp->next;
        }
        temp2 = temp->next;
        temp->next = temp2->next;
    }
    std::cout<<"Deleted element "<<temp2->data;
    std::cout<<"\n";
    delete(temp2);
}

void reverse_list(node *&head, node *&tail)
{
    node *prev,*upto;
    upto = head;
    prev = nullptr;
    node *temporary;
    tail = head;
    while(upto!= nullptr)
    {
   	 temporary = upto->next;
    	 upto->next = prev;
    	 prev = upto;
     	 upto = temporary;
    }
    head = prev;
}

int main() {
    node *head, *tail, *temp;
    int user_input,data;
    head=tail= nullptr;

    while(1)
    {
        std::cout<<"1.Display\n2.Insert\n3.Delete\n4.Priority Delete\n5.Reverse List\n6.Exit\n";
        cin>>user_input;
        switch(user_input)
        {
            case 1: temp = head;
           	    std::cout<<"\n";
           	    while(temp != nullptr)
           	    {
                	 std::cout<<temp->data<<" ";
                	 temp = temp->next;
            	    }
                    std::cout<<"\n";
                    break;
            case 2: std::cout<<"Enter data ";
                    cin>>data;
                    insert_into_list(data,head,tail);
                    break;
            case 3: delete_from_list(head,tail);
                    break;
            case 4: std::cout<<"Enter data ";
                    cin>>data;
                    priority_delete(data,head,tail);
                    break;
            case 5: reverse_list(head,tail);
                    break;
            case 6: exit(0);
                    break;
            default:break;
        }
    }

}
