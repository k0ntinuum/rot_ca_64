unt lcs(unt x, unt i) { return (x << (64 - i ) | (x >> i));}
unt rcs(unt x, unt i) { return ( x << i | x >> (64 - i ));}
unt val(unt x, unt i) { return lcs(rcs(M, i) & x , i);}

unt rot_ca(unt f, unt s, unt x) {
    unt y = 0ULL, b;
    for (unt i = 0; i < L; i++) { 
        b = val(x, i); 
        y |= ((f & 1ULL << b) >> b) << i;
        f = lcs(f,s);
    }
    return y;
}
unt rot_ca_set(unt* f, unt s, unt x) {
    for (unt i = 0 ; i < E; i++) {
        x = rot_ca(f[i%F], s, x);
    }
    return x;
}
