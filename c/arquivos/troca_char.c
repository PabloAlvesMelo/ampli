#include <stdio.h> 
#include <string.h>
 
int main()
{
    char s[4],c1,c2;  
    int  i;
 
    printf("Enter  the string : ");
    fgets(s, 4 , stdin);
    c1=',';
    c2='.';
    
    for(i=0;s[i];i++)
	{  
		if(s[i]==c1)
		{
		   s[i]=c2;
	 
	    }
 
	}
	   
    printf("\nafter replace:%s\n\n",s);
 	 
     
    return 0;
}