long bar ( long a, long b ) {
    long t1=(int) 0;
    long t2=11*a+2*b-(b<<4)+1;
    while (a<=b){
        a++;
        t1+=t2;
    }
    return t1;
}
