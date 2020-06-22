int main (int argc, char const *argv[])
{
    int a;
    scanf("%d", &a);
    int b[999];
    int x;
    scanf("%d",&x);
    int i;
    for (i=0; i<a+1; i++) {
        scanf("%d", &b[i] );
        
    }
    
    long int d=b[0];
    for (i=0; i<a; i++) {
        d=d*x+b[i+1];
    }
    printf("%ld ",d);
    
    for ( i=0; i<a; i++){
        b[i]=b[i]*(a-i);
        
    }
    
    d=b[0];
    for ( i=0; i<a-1; i++) {
        d=d*x+b[i+1];
    }
    
    printf("%ld\n", d);
    
    
    return 0;
}