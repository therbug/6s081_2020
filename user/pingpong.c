#include "kernel/types.h"
#include "user/user.h"

int main(int argc, char *argv[]) {
    int p1[2], p2[2];
    char buf[1];

    pipe(p1);
    pipe(p2);

    if (fork() != 0) {
        write(p1[1], "1", 1);
        read(p2[0], &buf, 1);
        printf("%d: received pong\n", getpid());
        exit(0);
    } else {
        read(p1[0], &buf, 1);
        printf("%d: received ping\n", getpid);
        write(p2[1], "1", 1);
    }
    exit(0);
}