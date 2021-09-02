/* General list operations */
int list il;
float list fl;

int list times_2(int i) {
    return i * 2;
}

int is_greater_than5(int i) {
    if (i > 5) {
        return 1;
    }
    return 0;
}

int list create_list() {
    int i;
    int list new;
    new = NIL
    for (i = 0; i < 10; i = i+1) {
        new = i : new;
    }
}

int main() {
    int head;
    il = create_list();
    head = ?il;
    il = times_2 >> il;
    il = is_greater_than5 << il;

    write(%il);
    write(head);

    return 0;
}
