#include "arcfour.h"


#define F fflush(stdout)
int main(void);

void printbin(int8 *input , const int16 size){
    int16 i;
    int8 *p;
    assert(size>0);
    for( i=size; p=input; i;i--,p++){
        if(!(i%2))
            printf(" ");
        printf("%.02x",*p);
        
    }
    printf("\n");
    return;
}
int main(){
    char *key, *from;
    int8 *encrypted, *decrypted;

    Arcfour *rc4;
    int16 skey,stext;
    

    key = "potatoes";
    skey = strlen(key);
    from = "I will make a good project";
    stext = strlen(from);

    printf("Initialize Encryption  ...");
    rc4 = rc4init((int8 *)key,skey);
    printf("Done\n !");
    printf("'%s'\n-> ",from);
    encrypted = rc4encrypt(rc4,from,stext);
    printbin(encrypted,skey);

    rc4uninit(rc4);
    
    printf("Initialize Decryption  ...");
    rc4 = rc4init((int8 *)key,skey);
    printf("Done\n !");
    decrypted = rc4decrypt(rc4,encrypted,stext);
    printf("-> '%s'\n",decrypted);

    rc4uninit(rc4);
    return 0;
}