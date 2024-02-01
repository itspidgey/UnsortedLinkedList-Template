

template<class T>
UnsortedList<T>::UnsortedList() {
    length = 0;
    head = nullptr;
    iterNode = nullptr;
}

template<class T>
void UnsortedList<T>::MakeEmpty() {

    length = 0;

    while (head != nullptr){
        Node* oldHead = head;
        head = head->next;
        delete oldHead;
    }
}

template<class T>
bool UnsortedList<T>::IsFull() const {

    try {
        Node* node = new Node;
        delete node;
        return true;
    }
    catch(std::bad_alloc error){
        return false;
    }

}

template<class T>
int UnsortedList<T>::GetLength() const {
    return length;
}

template<class T>
bool UnsortedList<T>::Contains(T someItem) {

    Node* currN = head;

    while (currN != nullptr){

        if (currN->value == someItem){
            return true;
        }
        currN = currN->next; //moves currN to the next Node
    }

    // Looked at everything and didn't find someItem

    return false;
}

template<class T>
void UnsortedList<T>::AddItem(T item) {
    Node* node = new Node;
    node->value = item;
    node->next = head;
    length++;
    head = node;
}

template<class T>
void UnsortedList<T>::DeleteItem(T item) {
    Node* currN = head;
    Node* prevN = nullptr;

    while (currN != nullptr){

        if (currN->value == item){

            if (currN != head){
                prevN->next = currN->next;
            }
            else{
                head = currN->next;
            }
            delete currN;
            length--;
            return; //found the value and deleted, now leave the function.
        }
        prevN = currN;
        currN = currN->next; //moves currN to the next Node
    }
}

template<class T>
void UnsortedList<T>::ResetIterator() {
    iterNode = head;
}

template<class T>
T UnsortedList<T>::GetNextItem() {

    if (iterNode == nullptr){
        throw "End of iterator";
    }

    T nextItem = iterNode->value;
    iterNode = iterNode->next;
    return nextItem;
}
