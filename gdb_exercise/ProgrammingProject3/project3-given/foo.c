long foo ( long a, long b ) {
    long t1 = (13*a)<<2;
    long t2 = 3*b;
    t1+=(t2<<5)-t2;
    b=b-a;
    t1+=((3*b)<<5)-b;
    return t1;
}