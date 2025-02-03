/***includes***/

#include <ctype.h>
#include <errno.h>
#include <stdlib.h>
#include <sys/ioctl.h>
#include <termios.h>
#include <unistd.h>
#include <string.h>
#include <stdio.h>

/***defines***/
#define GARP_VERSION "1.0"
#define CTRL_KEY(k) ((k) & 0x1f)

/***data***/

struct editorconfig{
    int cx;
    int cy;
    int screenrows;
    int screencols;
    struct termios orig_termios;
};
struct editorconfig E;

/***terminal***/

void die(const char *s)
{
    write(STDOUT_FILENO,"\x1b[2J",4);
    write(STDOUT_FILENO,"\x1b[H",3);
    perror(s);
    exit(1);
}

void disablerawmode()
{
    if(tcsetattr(STDIN_FILENO,TCSAFLUSH,&E.orig_termios)==-1) 
    die("tcsetattr");
}

void rawmode()
{
 if(tcgetattr(STDIN_FILENO,&E.orig_termios)==-1)
    die("tcgetattr");
 atexit(disablerawmode);
 struct termios raw = E.orig_termios;
 raw.c_iflag &=~(ICRNL | IXON | ISTRIP | INPCK | BRKINT);
 raw.c_lflag &=~(ECHO | ICANON | ISIG | IEXTEN);
 raw.c_cflag |=~(CS8);
 raw.c_oflag &=~(OPOST);
 raw.c_cc[VMIN] = 0;
 raw.c_cc[VTIME] = 1;
 if(tcsetattr(STDIN_FILENO,TCSAFLUSH,&raw)==-1)
    die("tcsetattr");
}

char editorreadkey(){
    int nread;
    char c;
    while((nread=read(STDIN_FILENO,&c,1))!=1){
        if((nread==-1&&errno!=EAGAIN)) die("read");
    }
    if(c =='\x1b'){
        char seq[3];
        if(read(STDIN_FILENO,&seq[0],1)!=1) return '\x1b';
        if(read(STDIN_FILENO,&seq[1],1)!=1) return '\x1b';
        if(seq[0]=='['){
            switch(seq[1]){
                case 'A':return 'w';
                case 'B':return 's';
                case 'C':return 'd';
                case 'D':return 'a';
            }
        }
        return '\x1b';
    }
    else{
        return c;
    }
}
int getwindowsize(int *rows,int *cols){
    struct winsize ws;
    if(ioctl(STDOUT_FILENO ,TIOCGWINSZ ,&ws) == -1 || ws.ws_col == 0){
        return -1;
    }
    else{
        *rows=ws.ws_row;
        *cols=ws.ws_col;
        return 0;
    }
}
/*** append buffer***/
struct abuf{
    char *b;
    int len;
};
void abappend(struct abuf *ab,const char *s,int len){
    char *new = realloc(ab->b,ab->len+len);
    if(new==NULL) return;
    memcpy(&new[ab->len],s,len);
    ab->b=new;
    ab->len+=len;

}
void abfree(struct abuf *ab){
    free(ab->b);
}
#define ABUF_INIT {NULL,0}
/***output***/
void editordrawrows(struct abuf *ab){
    int y;
    for(y=0;y<E.screenrows;y++){
        if (y == E.screenrows / 3) {
            char welcome[80];
            int welcomelen = snprintf(welcome, sizeof(welcome),"GARP editor -- version %s", GARP_VERSION);
        if (welcomelen > E.screencols) welcomelen = E.screencols;
        int padding = (E.screencols - welcomelen) / 2;
            if (padding) {
                abappend(ab, "~", 1);
                padding--;
            }
            while (padding--) abappend(ab, " ", 1);
            abappend(ab, welcome, welcomelen);
        }
        else{
            abappend(ab,"~",1);
        }
    }
    abappend(ab, "\x1b[K", 3);
    if(y<E.screenrows-1){
        abappend(ab,"\r\n",2);
    }
}

void editorrefreshscreen(){
    struct abuf ab = ABUF_INIT;

    abappend(&ab, "\x1b[?25l", 6);
    
    abappend(&ab,"\x1b[H",3);
    editordrawrows(&ab);
    char buf[32];
    snprintf(buf, sizeof(buf), "\x1b[%d;%dH", E.cy + 1, E.cx + 1);
    abappend(&ab, buf, strlen(buf));
    abappend(&ab,"\x1b[H",3);
    abappend(&ab, "\x1b[?25h", 6);

    write(STDOUT_FILENO, ab.b, ab.len);
    abfree(&ab);

}

/***input***/         
void editormovecursor(char key) {
  switch (key) {
    case 'a':
      E.cx--;
      break;
    case 'd':
      E.cx++;
      break;
    case 'w':
      E.cy--;
      break;
    case 's':
      E.cy++;
      break;
  }
}
void editorprocesskeypress(){
    char c=editorreadkey();
    switch (c){
        case CTRL_KEY('q'):
        write(STDOUT_FILENO, "\x1b[2J", 4);
        write(STDOUT_FILENO, "\x1b[H", 3);
        exit(0);
        break;
        case 'w':
        case 's':
        case 'a':
        case 'd':
        editormovecursor(c);
        break;
    }
}

/***init***/
void initeditor(){
    E.cx=0;
    E.cy=0;
    if(getwindowsize(&E.screenrows,&E.screencols) == -1) die("getwindowsize");

}

int main()
{
 rawmode();
 initeditor();
 while(1)
 {
    editorrefreshscreen();
    editorprocesskeypress();
 }
 return 0;
}
