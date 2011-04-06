#include <sys/types.h>
#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <termios.h>

static int gp_save_term(int fd, struct termios *tios)
{
        return tcgetattr(fd, tios);
}

static int gp_load_term(int fd, struct termios *tios)
{
        return tcsetattr(fd, TCSAFLUSH, tios);
}

static void gp_set_password_flags(struct termios *tios)
{
        tios->c_lflag &= ~ECHO; /* disable echo */
        tios->c_lflag &= ~ISIG; /* ignore signals */
}

/* Get a password of max len-1 chars and store it in dest.
 * The string is anyway nul terminated, the echo disabled. */
int palla_getpass(char *dest, size_t len)
{
        unsigned int i; /* character index inside pass */
        int ttyfd = fileno(stdin);
        struct termios orig, new;

        /* sanity check */
        if (!len || !dest)
                return -1;

        /* Save the old status */
        if (gp_save_term(ttyfd, &orig) == -1)
                return -1;
        new = orig; /* copy it in the new */
        gp_set_password_flags(&new); /* set the right flags */
        if (gp_load_term(ttyfd, &new) == -1) /* load the new term config */
                return -1;

        /* Now we are in "password mode", get the input */
        i = 0;
        while(i < (len-1)) {
                char c;
                if (read(ttyfd, &c, 1) <= 0)
                        break;
                if (c == '\n')
                        break;
                dest[i] = c;
                i++;
        }
        dest[i] = '\0'; /* add the nul term */
        if (gp_load_term(ttyfd, &orig) == -1) /* restore the old term */
                return -1; /* sorry, the term is left unsane */
        return i;
}

int main(void)
{
        char dest[10];
        printf("password: ");
        fflush(stdout);
        palla_getpass(dest, 10);
        printf("'%s'\n", dest);
        return 0;
}
