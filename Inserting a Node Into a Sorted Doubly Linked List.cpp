/*
 * Complete the 'sortedInsert' function below.
 *
 * The function is expected to return an INTEGER_DOUBLY_LINKED_LIST.
 * The function accepts following parameters:
 *  1. INTEGER_DOUBLY_LINKED_LIST llist
 *  2. INTEGER data
 */

/*
 * For your reference:
 *
 * DoublyLinkedListNode {
 *     int data;
 *     DoublyLinkedListNode* next;
 *     DoublyLinkedListNode* prev;
 * };
 *
 */

DoublyLinkedListNode* sortedInsert(DoublyLinkedListNode* head, int data) 
{
    DoublyLinkedListNode* newnode = new DoublyLinkedListNode(data);
    
    if(head==NULL)
    {
        return head;
    }
    if(head->data >= newnode->data)
    {
        newnode->next=head;
        head->prev = newnode;
        newnode->prev = nullptr;
        return newnode;
    }
    DoublyLinkedListNode* temp = head;
    
    
    while(temp != NULL)
    {
        if(temp->data >= newnode->data)
        {
           
            temp->prev->next=newnode;
             newnode->prev=temp->prev;
            newnode->next=temp;
            temp->prev=newnode;
            break;
        }
        else if (temp->next==NULL) 
        {
            temp->next = newnode;
            newnode->prev=temp;
            //newnode->next=nullptr;
            break;
        } 
        temp = temp->next;
    }
    return head;
    
}

int main()
