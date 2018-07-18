#include <stdio.h>
#include <stdlib.h>

typedef struct packet_s{
    int len;
    char data[0];
}packet_t;

int main(int argc, char *argv[])
{
    int len=20;
    int i;
    packet_t *p=NULL;

    p = (packet_t *)malloc( sizeof(packet_t) + sizeof(char) * len );
    p->len = len;

    for(i=0;i<p->len;i++)
    {
        p->data[i] = i+1;
    }

    for(i=0;i<p->len;i++)
    {
        printf("p->data[%d]=%d\n", i, p->data[i]);
    }

    free(p);
    p = NULL;

    return 0;
}
