#include <stdio.h>
#include <string.h>


struct employee {
    char name[20];
    int id;
};


int main() {
    struct employee person;
    strncpy(person.name, "Joe", 19); // Leave space for null
    person.id = 715;
    printf("[%s, %i]\n", person.name, person.id);
}
