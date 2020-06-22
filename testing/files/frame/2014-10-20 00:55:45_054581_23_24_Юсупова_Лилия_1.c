int main(int argc, char **argv) {
 
        if (argc!=4) {
                printf("Usage: frame <height> <width> <text>\n");
                return 666;
        }
        int len;
        len=strnlen(argv[3],1000);
        if ((atoi(argv[1])<3)||(atoi(argv[2])-2<len)) {
                printf("Error\n");
                return 666;
        }
        int k1,k2,i=0;
        k1=(atoi(argv[2])-2-len)/2;
        k2=atoi(argv[2])-2-len-k1;
        for (;i<atoi(argv[2]);i++) printf("*");
        printf("\n");
        int k3,j;
        if ((atoi(argv[1])-2)%2==0) k3=atoi(argv[1])/2;
        else k3=(atoi(argv[1])+1)/2;
        for (i=1;i<(atoi(argv[1])-1);i++) {
                if  (i==k3-1) {
                        printf("*");
                        for (j=0;j<k1;j++) printf(" ");
                        printf("%s",argv[3]);
                        for (j=0;j<k2;j++) printf(" ");
                        printf("*\n");
                } else {
                        printf("*");
                        for (j=1;j<(atoi(argv[2])-1);j++) printf(" ");
                        printf("*\n");
                }
        }
        for (i=0;i<atoi(argv[2]);i++) printf("*");
        return 666;
}