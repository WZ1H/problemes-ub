/* Program to show buffering */
#include <stdio.h>
#include <unistd.h>

int main() {
    /* Write to buffer but won't show yet */
    printf("Starting");
    sleep(3);           /* Wait 3 seconds */
    printf(" process"); /* Still won't show */
    sleep(3);          /* Wait another 3 seconds */
    printf("\n");      /* NOW everything shows at once */
    return 0;
}