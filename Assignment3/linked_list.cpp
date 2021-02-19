#include <string.h>
#include<iostream>
using namespace std;

//node class
class NODE
{
    int data;
    NODE *next;

public:
    //constructor that initialize a node with the given value and pointing the next to NULL
    NODE(int d)
    {
        data = d;
        next = NULL;
    }
    //to get the value of a node
    int get_value()
    {
        return data;
    }
    //to access the pointer
    NODE *get_next()
    {
        return next;
    }
    //to add a node 
    void add_node(NODE *n)
    {
        next = n;
    }
};

class LINKED_LIST
{
    NODE *head;

public:
    LINKED_LIST()
    {
        head = NULL;
    }
    int check_empty()
    {
        if (head == NULL)
        {
            cout << "Empty List !\n";
            return 1;
        }
        return 0;
    }
    void add_node(int data)
    {
        NODE *node = new NODE(data);
        if (head == NULL)
        {
            head = node;
        }
        else
        {
            NODE *temp = head;
            while ((*temp).get_next() != NULL)
                temp = (*temp).get_next();
            (*temp).add_node(node);
        }
    }
    void delete_node(int data)
    {
        NODE *temp = head;
        int flag = 0;
        if (check_empty())
            return;
        if ((*temp).get_value() == data)
        {
            head = (*temp).get_next();
            free(temp);
            flag = 1;
        }
        else
        {
            while ((*(*temp).get_next()).get_value() != data)
                temp = (*temp).get_next();
            NODE *temp1 = (*temp).get_next();
            (*temp).add_node((*temp1).get_next());
            free(temp1);
            flag = 1;
        }
        if (flag == 0)
            cout << "Node not found";
    }
    void display_list()
    {
        NODE *temp = head;
        cout << "List" << endl;
        do
        {
            cout << (*temp).get_value() << ":";
            temp = (*temp).get_next();
        } while (temp != NULL);
        cout << "\n\n";
    }
};

int main()
{
    LINKED_LIST lst;
    lst.add_node(10);
    lst.add_node(50);
    lst.add_node(40);
    lst.add_node(20);
    lst.display_list();
    lst.delete_node(10);
    lst.display_list();
    lst.delete_node(40);
    lst.display_list();
    lst.delete_node(20);
    lst.delete_node(50);
    lst.delete_node(0);
    return 0;
}