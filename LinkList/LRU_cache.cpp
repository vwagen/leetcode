#include <iostream>
#include <algorithm>
#include <iterator>
#include <vector>
using namespace std;

typedef struct ListNode{
    int key;
    int value;
    ListNode* last;
    ListNode* next;
    ListNode(int for_key, int for_value):key(for_key), value(for_value), last(NULL), next(NULL){}
} Item;

int print_list_node(Item *head){
    Item* last_node = NULL;
    while(head != NULL) {
        if(head -> next != NULL) {
            cout << "{" << head -> key << ", " << head -> value << "}" << " -> ";
        }
        else {
            cout << "{" << head -> key << ", " << head -> value << "}";
        }
        last_node = head;
        head = head -> next;
    }
    cout << endl;
    //while(last_node != NULL) {
    //    if(last_node -> last != NULL) {
    //        cout << "{" << last_node -> key << ", " << last_node -> value << "}" << " -> ";
    //    }
    //    else {
    //        cout << "{" << last_node -> key << ", " << last_node -> value << "}";
    //    }
    //    last_node = last_node -> last;
    //}
    //cout << endl;
    return 0;
}

//Item* make_list_from_array(int A[], int n) {
//    if(n == 0) {
//        return NULL;
//    }
//    Item* head = NULL;
//    head = new Item(A[0]);
//    Item* tmp = head;
//    for(int i = 1; i < n; i++) {
//        tmp -> next = new Item(A[i]);
//        tmp = tmp -> next;
//    }
//    return head;
//}


class LRUCache{
    int max_size;
    int cache_size;
    Item* head;
    Item* tail;
public:
    LRUCache(int capacity) {
        max_size = capacity;
        cache_size = 0;
        head = NULL;
        tail = NULL;
    }

    Item* get_head() {
        return head;
    }

    Item* search(int key, Item* tmp){
        Item* last_item = NULL;
        while(tmp != NULL && tmp -> key != key) {
            last_item = tmp;
            tmp = tmp -> next;
        }
        if(tmp != NULL && last_item != NULL) {
            Item* next_item = tmp -> next;
            if(next_item != NULL) {
                next_item -> last = last_item;
            }
            else {
                tail = tail -> last;
            }
            last_item -> next = next_item;
            tmp -> last = NULL;
            head -> last = tmp;
            tmp -> next = head;
            head = tmp;
        }
        return tmp;
    }

    int get(int key) {
        Item* target = search(key, head);
        if(target != NULL) {
            return target -> value;
        }
        else {
            return -1;
        }
    }

    void deleteLastItem() {
        if(tail == NULL) {
            return;
        }
        if(tail != NULL && tail -> last == NULL) {
            free(tail);
            tail = NULL;
            head = NULL;
        }
        else {
            //cout << "tail: {" << tail -> key << ", " << tail -> value << "}" << endl;
            //cout << "tail -> last: {" << tail -> last -> key << ", " << tail -> last -> value << "}" << endl;
            tail -> last -> next = tail -> next;
            Item* wait_for_free = tail;
            tail = tail -> last;
            free(wait_for_free);
        }
    }

    void set(int key, int value) {
        Item* target = search(key, head);
        if(target != NULL) {
            target -> value = value;
        }
        else{
            Item* tmp = new Item(key, value);
            if(cache_size == max_size) {
                deleteLastItem();
            }
            else {
                cache_size++;
            }
            if(head == NULL) {
                tail = tmp;
            }
            else {
                tmp -> next = head;
                head -> last = tmp;
            }
            head = tmp;
        }
        return;
    }
};



int main(int argc, char* argv[]) {
    LRUCache s(10);
    //cout << endl << "s.set(1,2): " << endl;
    //s.set(1,2);
    //print_list_node(s.get_head());
    //cout << endl << "s.set(2,3): " << endl;
    //s.set(2,3);
    //print_list_node(s.get_head());
    //cout << endl << "s.get(1): " << s.get(1) << endl;
    //print_list_node(s.get_head());
    //cout << endl << "s.set(3,4): " << endl;
    //s.set(3,4);
    //print_list_node(s.get_head());
    //cout << endl << "s.set(4,5): " << endl;
    //s.set(4,5);
    //print_list_node(s.get_head());
    //cout << endl << "s.get(5): " << s.get(5) << endl;
    //print_list_node(s.get_head());
    //cout << endl << "s.get(3): " << s.get(3) << endl;
    //print_list_node(s.get_head());
    //cout << endl << "s.set(5,6): " << endl;
    //s.set(5,6);
    //print_list_node(s.get_head());


    s.set(10,13);
    cout << endl;
    cout << "s.set(10,13):" << endl;
    print_list_node(s.get_head());
    s.set(3,17);
    cout << endl;
    cout << "s.set(3,17):" << endl;
    print_list_node(s.get_head());
    s.set(6,11);
    cout << endl;
    print_list_node(s.get_head());
    s.set(10,5);
    cout << endl;
    print_list_node(s.get_head());
    s.set(9,10);
    cout << endl;
    print_list_node(s.get_head());
    s.get(13);
    cout << endl;
    print_list_node(s.get_head());
    s.set(2,19);
    cout << endl;
    print_list_node(s.get_head());
    s.get(2);
    cout << endl;
    print_list_node(s.get_head());
    s.get(3);
    cout << endl;
    print_list_node(s.get_head());
    s.set(5,25);
    cout << endl;
    print_list_node(s.get_head());
    s.get(8);
    cout << endl;
    print_list_node(s.get_head());
    s.set(9,22);
    cout << endl;
    print_list_node(s.get_head());
    s.set(5,5);
    cout << endl;
    print_list_node(s.get_head());
    s.set(1,30);
    cout << endl;
    print_list_node(s.get_head());
    s.get(11);
    cout << endl;
    print_list_node(s.get_head());
    s.set(9,12);
    cout << endl;
    print_list_node(s.get_head());
    s.get(7);
    cout << endl;
    print_list_node(s.get_head());
    s.get(5);
    cout << endl;
    print_list_node(s.get_head());
    s.get(8);
    cout << endl;
    print_list_node(s.get_head());
    s.get(9);
    cout << endl;
    print_list_node(s.get_head());
    s.set(4,30);
    cout << endl;
    print_list_node(s.get_head());
    s.set(9,3);
    cout << endl;
    print_list_node(s.get_head());
    s.get(9);
    cout << endl;
    print_list_node(s.get_head());
    s.get(10);
    cout << endl;
    print_list_node(s.get_head());
    s.get(10);
    cout << endl;
    print_list_node(s.get_head());
    s.set(6,14);
    cout << endl;
    print_list_node(s.get_head());
    s.set(3,1);
    cout << endl;
    print_list_node(s.get_head());
    s.get(3);
    cout << endl;
    print_list_node(s.get_head());
    s.set(10,11);
    cout << endl;
    print_list_node(s.get_head());
    s.get(8);
    cout << endl;
    print_list_node(s.get_head());
    s.set(2,14);
    cout << endl;
    print_list_node(s.get_head());
    s.get(1);
    cout << endl;
    print_list_node(s.get_head());
    s.get(5);
    cout << endl;
    print_list_node(s.get_head());
    s.get(4);
    cout << endl;
    print_list_node(s.get_head());
    s.set(11,4);
    cout << endl;
    print_list_node(s.get_head());
    s.set(12,24);
    cout << endl;
    print_list_node(s.get_head());
    s.set(5,18);
    cout << endl;
    print_list_node(s.get_head());
    s.get(13);
    cout << endl;
    print_list_node(s.get_head());
    s.set(7,23);
    cout << endl;
    print_list_node(s.get_head());
    s.get(8);
    cout << endl;
    print_list_node(s.get_head());
    s.get(12);
    cout << endl;
    print_list_node(s.get_head());
    s.set(3,27);
    cout << endl;
    print_list_node(s.get_head());
    s.set(2,12);
    cout << endl;
    print_list_node(s.get_head());
    s.get(5);
    cout << endl;
    print_list_node(s.get_head());
    s.set(2,9);
    cout << endl;
    print_list_node(s.get_head());
    s.set(13,4);
    cout << endl;
    print_list_node(s.get_head());
    s.set(8,18);
    cout << endl;
    print_list_node(s.get_head());
    s.set(1,7);
    cout << endl;
    print_list_node(s.get_head());
    s.get(6);
    cout << endl;
    print_list_node(s.get_head());
    s.set(9,29);
    cout << endl;
    print_list_node(s.get_head());
    s.set(8,21);
    cout << endl;
    print_list_node(s.get_head());
    s.get(5);
    cout << endl;
    print_list_node(s.get_head());
    s.set(6,30);
    cout << endl;
    print_list_node(s.get_head());
    s.set(1,12);
    cout << endl;
    print_list_node(s.get_head());
    s.get(10);
    cout << endl;
    print_list_node(s.get_head());
    s.set(4,15);
    cout << endl;
    print_list_node(s.get_head());
    s.set(7,22);
    cout << endl;
    print_list_node(s.get_head());
    s.set(11,26);
    cout << endl;
    print_list_node(s.get_head());
    s.set(8,17);
    cout << endl;
    print_list_node(s.get_head());
    s.set(9,29);
    cout << endl;
    print_list_node(s.get_head());
    s.get(5);
    cout << endl;
    print_list_node(s.get_head());
    s.set(3,4);
    cout << endl;
    print_list_node(s.get_head());
    s.set(11,30);
    cout << endl;
    print_list_node(s.get_head());
    s.get(12);
    cout << endl;
    print_list_node(s.get_head());
    s.set(4,29);
    cout << endl;
    print_list_node(s.get_head());
    s.get(3);
    cout << endl;
    print_list_node(s.get_head());
    s.get(9);
    cout << endl;
    print_list_node(s.get_head());
    s.get(6);
    cout << endl;
    print_list_node(s.get_head());
    s.set(3,4);
    cout << endl;
    print_list_node(s.get_head());
    s.get(1);
    cout << endl;
    print_list_node(s.get_head());
    s.get(10);
    cout << endl;
    print_list_node(s.get_head());
    s.set(3,29);
    cout << endl;
    print_list_node(s.get_head());
    s.set(10,28);
    cout << endl;
    print_list_node(s.get_head());
    s.set(1,20);
    cout << endl;
    print_list_node(s.get_head());
    s.set(11,13);
    cout << endl;
    print_list_node(s.get_head());
    s.get(3);
    cout << endl;
    print_list_node(s.get_head());
    s.set(3,12);
    cout << endl;
    print_list_node(s.get_head());
    s.set(3,8);
    cout << endl;
    print_list_node(s.get_head());
    s.set(10,9);
    cout << endl;
    print_list_node(s.get_head());
    s.set(3,26);
    cout << endl;
    print_list_node(s.get_head());
    s.get(8);
    cout << endl;
    print_list_node(s.get_head());
    s.get(7);
    cout << endl;
    print_list_node(s.get_head());
    s.get(5);
    cout << endl;
    print_list_node(s.get_head());
    s.set(13,17);
    cout << endl;
    print_list_node(s.get_head());
    s.set(2,27);
    cout << endl;
    print_list_node(s.get_head());
    s.set(11,15);
    cout << endl;
    print_list_node(s.get_head());
    s.get(12);
    cout << endl;
    print_list_node(s.get_head());
    s.set(9,19);
    cout << endl;
    print_list_node(s.get_head());
    s.set(2,15);
    cout << endl;
    print_list_node(s.get_head());
    s.set(3,16);
    cout << endl;
    print_list_node(s.get_head());
    s.get(1);
    cout << endl;
    print_list_node(s.get_head());
    s.set(12,17);
    cout << endl;
    print_list_node(s.get_head());
    s.set(9,1);
    cout << endl;
    print_list_node(s.get_head());
    s.set(6,19);
    cout << endl;
    cout << "s.set(6,19):" << endl;
    print_list_node(s.get_head());
    s.get(4);
    cout << endl;
    cout << "s.get(4):" << s.get(4) << endl;
    print_list_node(s.get_head());
    s.get(5);
    cout << endl;
    cout << "s.get(5):" << s.get(5) << endl;
    print_list_node(s.get_head());
    s.get(5);
    cout << endl;
    cout << "s.get(5):" << s.get(5) << endl;
    print_list_node(s.get_head());
    s.set(8,1);
    cout << endl;
    cout << "s.set(8,1):" << endl;
    print_list_node(s.get_head());
    s.set(11,7);
    cout << endl;
    cout << "s.set(11,7):" << endl;
    print_list_node(s.get_head());
    s.set(5,2);
    cout << endl;
    cout << "s.set(5,2):" << endl;
    print_list_node(s.get_head());
    s.set(9,28);
    cout << endl;
    cout << "s.set(9,28):" << endl;
    print_list_node(s.get_head());
    s.get(1);
    cout << endl;
    cout << "s.get(1):" << s.get(1) << endl;
    print_list_node(s.get_head());
    s.set(2,2);
    cout << endl;
    cout << "s.set(2,2):" << endl;
    print_list_node(s.get_head());
    s.set(7,4);
    cout << endl;
    cout << "s.set(7,4):" << endl;
    print_list_node(s.get_head());
    s.set(4,22);
    cout << endl;
    cout << "s.set(4,22):" << endl;
    print_list_node(s.get_head());
    s.set(7,24);
    cout << endl;
    cout << "s.set(7,24):" << endl;
    print_list_node(s.get_head());
    s.set(9,26);
    cout << endl;
    cout << "s.set(9,26):" << endl;
    print_list_node(s.get_head());
    s.set(13,28);
    cout << endl;
    cout << "s.set(13,28):" << endl;
    print_list_node(s.get_head());
    s.set(11,26);
    cout << endl;
    cout << "s.set(11,26):" << endl;
    print_list_node(s.get_head());




    return 0;
}
