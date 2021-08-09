/* This comment should be ignored */
// This comment should also be ignored
float f;
int i;

int main() {
    f = 0.1;
    read(i);
    read(f);

    if (i == 3) {
        writeln("i is equal 3");
    } else if (i < 3){
        writeln("i is less than 3");
    } else {
        writeln("i is greater than 3");
    }

    f = i + 1;
    write(f);
    write(i);

    return 0;
}
