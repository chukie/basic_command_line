#include <stdio.h>  
#include <ctype.h>
#include <limits.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h> 
#include <sys/wait.h>
#include <stdbool.h>
void printWords(const char *string) {
    // Make a local copy of the string that we can manipulate.
    char * const copy = strdup(string);
    char *space = copy;
    // Find the next space in the string, and replace it with a newline.
    while (space = strchr(space,' ')) *space = '\n';
    // There are no more spaces in the string; print out our modified copy.
    printf("%s\n", copy);
    // Free our local copy
    free(copy);
}
int main(int argc, char* argv[])
{
    int cont=1;
    int startg = 0;
    while(cont<2)
    {
        char str1[100];
        char newString[10][10]; 
        int i,j,ctr;
        int* status;
        if(startg==0)
        {
        	printf("Welcome to Chuks Command prompt Enter any linux shell command :\n");
        	printf("---------------------------------------\n");
        	printf("tip: Use quit to quit\n");   
        	printf("Enter command: ");
        	
        }
        else
        {
        	printf("Enter command: ");
	}
	fgets(str1, sizeof str1, stdin);
	startg = startg + 1;
        char *stringsx[15];
        int count = 0;

        int init_size = strlen(str1);
	    char delim[] = " ";

	    char *ptr = strtok(str1, delim);

	    while(ptr != NULL)
	    {
		    //printf("'%s'\n", ptr);
            stringsx[count]=ptr;
		    ptr = strtok(NULL, delim);
            count = count + 1;
	    }

        for(int i = 0;i<count;i++)
        {
            printf("%s",stringsx[i]);
        }



    
        
        char *argvx[count+1];
        for(int i = 0,j=0;i<count;i++,j++)
        {
            argvx[i] = stringsx[i];
            char *newline = strchr( argvx[i], '\n' );
            if ( newline )
                *newline = 0;
            //printf("length of string %s is  %zu",stringsx[i],strlen(stringsx[i]));
        }
        argvx[count] = NULL;

        char lookfor[]="quit";
            
        if(strcmp(argvx[0],lookfor) == 0)
        {
            printf("exiting........");
            cont=cont+1;
        }
        
        int child = fork();
        if(child==0)
        {
            //printf("command to be executed %s",stringsx[0]);
            //printf("\nchild proccess with proccess id %d is started and command would be executed \n",getpid());
            execvp(argvx[0], argvx);
        
        }
        waitpid(child,status,0);
        
        
        
    }
    return 0;
}
