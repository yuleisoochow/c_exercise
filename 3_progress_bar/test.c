#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/ioctl.h>

#define COL(x)      "\e["#x"m"
#define RED         COL(31)
#define GREEN       COL(32)
#define RELLOW      COL(33)
#define BLUE        COL(34)
#define MAGENTA     COL(35)
#define CYAN        COL(36)
#define RAW         COL(0)


int show_process_bar(int percentage)
{
    struct winsize size;
    int bar_len=0;
    char *bar=NULL;
    int i;

    if(isatty(STDOUT_FILENO) == 0)
    {
        printf("Not tty device!!!\n");
        return -1;
    }

    if(ioctl(STDOUT_FILENO, TIOCGWINSZ, &size)<0)
    {
        printf("ioctl TIOCGWINSZ error!!!\n");
        return -1;
    }
    
    if(size.ws_col < 20)
    {
        printf("The windows column size is too small!!!\n");
        return -1;
    }

    bar_len = size.ws_col - 15;
    bar = (char *)malloc(bar_len);
    if(bar == NULL)
    {
        printf("Malloc space for bar failed!!!\n");
        return -1;
    }

    for(i=0;i<=((bar_len-2)*percentage/100);i++)
    {
        bar[i] = '#';
    }
    for(;i<=(bar_len-2);i++)
    {
        bar[i] = '-';
    }
    bar[bar_len-1] = '\0';

    printf(GREEN "[%s][%3d%%]\r%s" RAW, bar, percentage, percentage==100?"\n":"");
    fflush(stdout);

    return 0;
}

int main(int argc, char **argv)
{
    int i;

    for(i=0;i<=100;i++)
    {
        show_process_bar(i);
        usleep(100000);
    }

    return 0;
}
