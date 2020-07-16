
#include "table.h"
#include "student.h"

int main() {
    student s("andy", "exley", 751011);
    table<student> t;
    t.insert(s);
}
