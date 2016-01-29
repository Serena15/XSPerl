#include <EXTERN.h>               /* from the Perl distribution     */
#include <perl.h>                 /* from the Perl distribution     */
#include "decodebase64.h"
#include <stdio.h>


static PerlInterpreter *my_perl;  /***    The Perl interpreter    ***/


char *ReadFile(const char *filename) {
    FILE *fp = fopen ( filename , "rb" );
    if (!fp) {
	fputs("Error in the open file\n",stderr);
        exit(1);
    }
    fseek( fp , 0L , SEEK_END);//reference in the end of file
    size_t size = ftell( fp );//current position
    rewind( fp );//in the begining file
    char *buffer = calloc( 1, size + 1 );
    if (!buffer) {
        fclose(fp); 
	fputs("memory alloc fails",stderr);
        exit(1);
    }
    if (fread( buffer , size, 1 , fp) != 1) {
       fclose(fp);
       free(buffer);
       fputs("entire read fails",stderr);
       exit(1);
    }
    fclose(fp);
    buffer[size-1] = '\0';
    return buffer;
}

char *ReadingText(const char *filename) {
    char *encoded = ReadFile(filename);
    size_t len;
    char *decoded = Base64Decode(encoded, strlen(encoded), &len);
    free(encoded);
    return decoded;
}

void PrintKeys(HV* hash) {
    char *key;
    I32 key_length;
    SV *value;
    hv_iterinit(hash);
    while (value = hv_iternextsv(hash, &key, &key_length)) {
        int val = SvIV(value);
        printf("%s %d\n",key, val);
    }
}
  

static void GetStatistic(char *text, size_t len) {
    dSP;                           
    ENTER;                         
    SAVETMPS;                      
    PUSHMARK(SP);                   
    XPUSHs(sv_2mortal(newSVpv(text, len))); 
    PUTBACK;                     
    call_pv("Statistic::Statistic", G_SCALAR);    
    SPAGAIN;   
    char *key;
    I32 key_length;
    HV *hash = (HV *) SvRV(POPs);
    PrintKeys(hash);
    PUTBACK;
    FREETMPS;                      
    LEAVE;                      
}

int main(int argc, char **argv, char **env) {
    char *args[] = { NULL };
    PERL_SYS_INIT3(&argc,&argv,&env);
    my_perl = perl_alloc();
    perl_construct(my_perl);
    perl_parse(my_perl, NULL, argc, argv, NULL);    
    PL_exit_flags |= PERL_EXIT_DESTRUCT_END;
    /*** skipping perl_run() ***/
    perl_run(my_perl);
    printf("Start program: \n");
    char * text = ReadingText("data2.txt");
    GetStatistic(text, strlen(text));
    free(text);    
    perl_destruct(my_perl);
    perl_free(my_perl);
    PERL_SYS_TERM();     
}


