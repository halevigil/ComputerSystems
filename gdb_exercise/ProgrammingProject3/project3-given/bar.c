long bar ( long a, long b ) {
    long t2=(int) 0;
    long t3=11*a;
    t3+=2*b-(b<<4)+1;
    while (a<=b){
        a++;
        t2+=t3;
    }
    return t2;
}
