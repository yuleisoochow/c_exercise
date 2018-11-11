#include <stdio.h>
#include <string.h>

int parse_one_domain_2_hex(char *domain, char *hex)
{
    int len = 0;
    char *p = NULL;
    int tmp = 0;

    if(domain == NULL || hex == NULL)
        return 0;

    while ( (p = strchr(domain, '.')) != NULL ) {
        tmp = p - domain;
        hex[len++] = tmp;
        memcpy(hex+len, domain, tmp);
        len += tmp;
        domain = p + 1;
    }
    p = domain;
    if ( *p != '\0' ) {
        tmp = strlen(p);
        hex[len++] = tmp;
        memcpy(hex+len, p, tmp);
        len += tmp;
    }
    hex[len++] = 0;

    return len;
}

int domain2hex(char *domain, char *hex)
{
    int i=0,j=0;
    char buf[1024] = {0};
    char *p = NULL;
    int hex_len = 0;

    if(domain == NULL || hex == NULL)
        return 0;

    /* format, remove redundant space */
    while ( *domain == ' ' ) {
        domain++;
    }
    for (i = 0; i < strlen(domain); i++) {
        buf[j++] = domain[i];
        if (domain[i] == ' ') {
            while (domain[i+1] == ' ') {
                i++;
            }
        }
    }
    if (buf[j-1] != ' ') {
        buf[j] = ' ';
        j++;
        buf[j] = '\0';
    }
    /* end format */

    domain = buf;
    while ( (p = strchr(domain, ' ')) != NULL ) {
        *p = '\0';
        hex_len += parse_one_domain_2_hex(domain, hex + hex_len);
        domain = p + 1;
    }

    return hex_len;
}

int hex2domain(char *buf, char *domain, int len)
{
    int i = 0;
    int domain_len = 0;
    int tmp = 0;
    char *p = NULL;

    if(domain == NULL || buf == NULL)
        return -1;

    if (buf[len-1] != 0) {
        for(i=len-1; i>0; i--)
        {
            if (buf[i] == 0) {
                len = i + 1;
                break;
            }
        }
        if(i == 0)
            return -1;
    }

    i = 0;
    while (i < len) {
        tmp = *(buf+i);
        if (i + tmp > len) {
            break;
        }
        memcpy(domain + domain_len, buf + i + 1, tmp);
        domain_len += tmp;
        i += tmp + 1;

        if( *(buf+i) == 0 )
        {
            *(domain + domain_len) = ' ';
            domain_len++;
            i++;
        }
        else
        {
            *(domain + domain_len) = '.';
            domain_len++;
        }
    }


    p = strrchr(domain, ' ');
    if(p != NULL)
        *p = '\0';

    return 0;
}
int main(int argc, const char *argv[])
{
    char domain[] = "  www.baidu.com   aa.daniel.net      ee.suda.edu ";
    char domain1[] = "yuleisoochow.github.io cc.suzhou.doc www.youku.com";
    char domain2[] = " gfhs.dfgfd.dfds.dfgd.dsd   euyeyu.sregg.fwef.4254.dfgerg   jsd.567.34523.fdgserg.fdgssd  ";
    char hex[1024] = {0};
    char buf[1024] = {0};
    int len = 0;
    int i = 0;

    // 1
    printf("-----first case-----\n");
    printf("The domain:%s---end\n", domain);
    printf("to     hex:");
    len = domain2hex(domain, hex);
    for (i = 0; i < len; i++) {
        if (hex[i] < 20)
            printf("%d", hex[i]);
        else
            printf("%c", hex[i]);
    }
    printf("---end\n");
    hex2domain(hex, buf, len);
    printf("to  domain:%s---end\n\n", buf);

    // 2
    printf("-----second case-----\n");
    printf("The domain:%s---end\n", domain1);
    printf("to     hex:");
    len = domain2hex(domain1, hex);
    for (i = 0; i < len; i++) {
        if (hex[i] < 20)
            printf("%d", hex[i]);
        else
            printf("%c", hex[i]);
    }
    printf("---end\n");
    hex2domain(hex, buf, len);
    printf("to  domain:%s---end\n\n", buf);

    // 3
    printf("-----third case-----\n");
    printf("The domain:%s---end\n", domain2);
    printf("to     hex:");
    len = domain2hex(domain2, hex);
    for (i = 0; i < len; i++) {
        if (hex[i] < 20)
            printf("%d", hex[i]);
        else
            printf("%c", hex[i]);
    }
    printf("---end\n");
    hex2domain(hex, buf, len);
    printf("to  domain:%s---end\n\n", buf);

    return 0;
}
