# include <stdio.h>
# include <math.h>
int qwerty(unsigned long long n)//Функция, считающая кол-во делителей.
{
    unsigned long long i,k,a;
    k=0;
    a=sqrt(n);//Корень считаем вне цикла, чтобы ускорить работу функции.
    for(i=2;i<a;i++)
    {
        if (n%i==0) k+=2;
        if((i==a)&&(n%(i*i)==0))
                k--;
    }
    return k;
}
int main()
{
        unsigned long long n,i,k;
        n=0;
        i=0;
        k=0;
        while (k<3000)
        {
                i+=1;
                n+=i;
                if(n%(2*3*5*7*11)!=0) continue;//Если число не делится на эти числа, то дальше считать делители не имеет смысла.
                k=qwerty(n);
        }
        printf("%lld\n",n);
        return 0;
}