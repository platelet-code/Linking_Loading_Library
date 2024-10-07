#include <stdio.h>
#include <stdlib.h>
#include <elf.h>
#include <link.h>

int main(int argc, char *argv[], char *envp[]) 
{
    printf("Argument count: %d\n", argc);

    for (int i = 0; i < argc; i++) {
        printf("Argument %d: %s\n", i, argv[i]);
    }

    printf("Environment:\n");
    for (int i = 0; envp[i] != NULL; i++) {
        printf("%s\n", envp[i]);
    }

    printf("Auxiliary Vectors:\n");
    ElfW(auxv_t) *auxv;
    while (*envp++ != NULL);
    for (auxv = (ElfW(auxv_t) *) envp; auxv->a_type != AT_NULL; auxv++) {
        printf("Type: %ld Value: %lx\n", (long) auxv->a_type, (long) auxv->a_un.a_val);
    }

    return 0;
}
