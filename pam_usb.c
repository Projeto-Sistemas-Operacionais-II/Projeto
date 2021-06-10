#include <dirent.h>
#include <stdio.h>
#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <time.h>
#include <errno.h>
#include <pwd.h>
#include <security/pam_modules.h>
#include <security/pam_ext.h>
#include <zconf.h>

#define _GNU_SOURCE
#define MAX_PROVIDED_INFORMATION_SIZE 128
#define MAX_POST_SIZE 1024
#define MAX_PARAM_SIZE 1024
#define CRED_BUF_SIZE 4096

dateTime()
{
    struct tm *date_time;
    time_t segundos;
    time(&segundos);
    date_time = localtime(&segundos);

    FILE *log;
    log = fopen("/etc/pam.d/pam.usb/login", "a");
    fprintf(log, "%s", "\nUser ROOT: ");
    fprintf(log, "%d/", date_time->tm_mday);
    fprintf(log, "%d/", date_time->tm_mon+1);
    fprintf(log, "%d ", date_time->tm_year+1900);
    fprintf(log, "%d:", date_time->tm_hour);
    fprintf(log, "%d:", date_time->tm_min);
    fprintf(log, "%d\n ", date_time->tm_sec);
}

login_user()
{
    ssize_t len;

    char buf[256], *p;
    char buf2[256];
    int i;

    len = readlink("/sys/block/sdb", buf, 256);

    buf[len] = 0;

    sprintf(buf2, "%s/%s", "/sys/block/", buf);
    for (i=0; i<6; i++)
    {
        p = strrchr(buf2, '/');
        *p = 0;
    }

    strcat(buf2, "/serial");

    int f = open(buf2, 0);
    len = read(f, buf, 256);
    if (len <= 0){}

    buf[len - 1 ] = 0;

    FILE *g = fopen("/etc/pam.d/pam.usb/usb.serial", "r");
    size_t serial = 100;
    char *line = malloc(serial);
    int estado;

    if (!g)
    {
        perror("/etc/pam.d/pam.usb/usb.serial");
        exit(1);
    }
    while (getline(&line, &serial, g) > 0)
    {
        if(strcmp(buf, line) == 0)
        {
            system("clear");
            dateTime();
            printf("\n\nAccess allowed.");
            printf("\nLogging in...\n\n");
            return PAM_SUCCESS;
        }
        else
        {
            system("clear");
            printf("\nAccess denied.");
            printf("\nInsert a registered device.\n\n");
            return PAM_AUTH_ERR;
        }
    }
    if (line)
    {
        free(line);
    }
    fclose(g);
}

int collect_information(pam_handle_t *pamh, const char * message, int msg_style, char * result)
{

    struct pam_response *resp;
    struct pam_conv *conv;
    struct pam_message msg[1], *pmsg[1];
    pmsg[0] = &msg[0];
    msg[0].msg_style = msg_style;
    msg[0].msg = message;


    int rval = pam_get_item(pamh, PAM_CONV, (const void **) &conv);
    if ( rval == PAM_SUCCESS)
    {
        rval = conv->conv(1, (const struct pam_message **)pmsg, &resp, conv->appdata_ptr);
        strncpy(result, resp[0].resp, MAX_PROVIDED_INFORMATION_SIZE);
    }

    return rval;
}

PAM_EXTERN int pam_sm_setcred( pam_handle_t *pamh, int flags, int argc, const char **argv )
{
    return PAM_SUCCESS;
}

PAM_EXTERN int pam_sm_authenticate( pam_handle_t *pamh, int flags,int argc, const char **argv )
{
    int rval;
    const char* username;

    rval = pam_get_user(pamh, &username, "Username: ");

    if (strcmp("root",username) == 0)
    {
        dateTime();
        printf("\nUser ROOT detected. Access allowed.");
        printf("\n\nLogging in...\n");
        return PAM_SUCCESS;
    }
    else
    {
        login_user();
    }

    if (rval == -1)
    {
        return PAM_SUCCESS;
    }
}
