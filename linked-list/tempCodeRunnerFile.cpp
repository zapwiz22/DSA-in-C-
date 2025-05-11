bool searchElement(int val, Node* head) {
    Node* temp = head;
    while (temp != NULL) {
        if (temp->data == val) {
            return true;
        }
        temp = temp->next;
    }
    return false;
}