#include<cstdio>
#include<cstdlib>
#define fat "[Fatal] "
#define ifo "[Info] "
#define ret (*(retp))
#define re return (ret);
#define b (*(bp))
#define t (*(tp))
using namespace std;

void* bp;
void* tp;
void* retp;

int main(int argc,const char** argv)
{
    register int stack_size=1048576;
    if(argc==1)
    {
        fprintf(stderr,fat "No input files. Aborting.\n");
        return 1;
    }
    else if(argc==2) // only the file name, not the stack size, defaults to 1MB
    {
        fprintf(stderr,ifo "You did not enter the stack size, defaults to 1MB = 1048576B.\n");
    }
    else
    {
        // deal with stack size, not doing now!
    }
    char c; 
    retp=malloc(sizeof(int));
    bp=retp+sizeof(int);
    realloc(bp,stack_size);
    tp=bp;
    // Possible chars: 
    while((c=getchar())+1)switch(c)
    {
        case 9:break;// undefined '\t'
        case 10:return ret;// do nothing '\n'
        case 32:break;// halt ' '
        case 33:*((unsigned char*)(t)-1)=!(*((unsigned char*)(t)-1));break;// logic not '!'
        case 34:short* short_=(short*)(tp)-2;printf("%hd",*short_);delete short_;break;// output the topmost 2 integers as a short integer, i.e. top-1 ++ top-2
    }
    
    free(bp);
    free(retp);
    re;
}