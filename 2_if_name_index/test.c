#include <stdio.h>
#include <stdlib.h>
#include <net/if.h>

int main(int argc, char *argv[])
{
    struct if_nameindex *head, *ifni;

    ifni = if_nameindex();
    head = ifni;

    if( head == NULL )
    {
        printf("if_nameindex() error!\n");
        return -1;
    }

    while(ifni->if_index != 0)
    {
        printf("Interface %-3d : %s\n", ifni->if_index, ifni->if_name);
        ifni++;
    }

    if_freenameindex(head);
    head = NULL;
    ifni = NULL;

    return 0;
}
