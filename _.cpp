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
        case 9:break;           // undefined    '\t'
        case 10:return ret;     // halt         '\n'
        case 32:break;          // do nothing   ' '
        case 33:t=!t;           // logic not    '!'
        case 34:t=
    }
    
    free(bp);
    free(retp);
    return 0;
}