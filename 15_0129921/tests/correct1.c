int list init_list(int n) {
	int i;
	int list new;
	new = NIL;
	for (i = 0; i < n; i = i + 1) {
		new = i : new;
	}
	return new;
}

float convert_to_float(int i) {
    return i;
}

int prev(int i) {
	return i-1;
}

int geq_five(int i) {
    return i >= 5;
}


int main() {
    int list a;
    int a5;
    float list b;
    int list c;

    a = init_list(10);
    a5 = geq_five << a;
    b = convert_to_float >> prev >> a;
    c = NIL;

    int list a_tail;
    int a_head;
    a_tail = !a;
    a_head = ?a;

    if (a != NIL) {
		int a_destructive_head;
        a_destructive_head = %a;
	}

    int list d;
    d = 1+2*(5/6) : 1*3 : d;
    a = b = c;

    return 0;
}