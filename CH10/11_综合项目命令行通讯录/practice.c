#include <stdio.h>
#include <string.h>

#define CONTACT_CAPACITY 4
#define NAME_CAPACITY 32
#define PHONE_CAPACITY 24

typedef struct
{
    char name[NAME_CAPACITY];
    char phone[PHONE_CAPACITY];
} Contact;

static int add_contact(Contact contacts[],
                       size_t *count,
                       const char *name,
                       const char *phone)
{
    if (/* TODO：检查容量和字符串长度 */) {
        return 0;
    }

    /* TODO：安全复制 name 和 phone */
    (*count)++;
    return 1;
}

static const Contact *find_contact(const Contact contacts[],
                                  size_t count,
                                  const char *name)
{
    for (size_t i = 0; i < count; i++) {
        if (/* TODO：名字匹配 */) {
            return &contacts[i];
        }
    }
    return NULL;
}

int main(void)
{
    Contact contacts[CONTACT_CAPACITY];
    size_t count = 0;

    add_contact(contacts, &count, "Ada", "10086");
    const Contact *contact = find_contact(contacts, count, "Ada");

    if (contact != NULL) {
        printf("%s %s\n", contact->name, contact->phone);
    }
    return 0;
}

