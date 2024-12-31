
void demo() {
    unt f_set[10] = {0}, f_hue = 100, down = 4, fail = 0; 
    unt enc_row, marg = 4, page_delay = 1000000, row_delay = 100000;
    cls();hide_cursor();
    for (size_t t = 0; t < 200000; t++) {
        cls();
        cursor_to(down,0);
        if (t % 2 == 0 ) {
            srand(time(NULL));
            //vary system parameters for demo
            //P = 1 << (1 + arc4random_uniform(4));
            P = 16;
            S = L / P;
            //E = 1 + arc4random_uniform(14);
            E = 16;
            //F = 1 + arc4random_uniform(E/2);
            F = 4;
            enc_row = down + F + 1;
            init_f_set(f_set);
        }
        unt p = first_P_bits(arc4random());
        unt c = enc(f_set, 1, p);
        unt d = dec(f_set, 1, c);
        //if (!(p == d)) continue;
        
        
        spaces(marg);printf(" f  =  ");rgb(G,G,G);print_bits(f_set[0]);
        for (unt e = 1; e < F; e++ ) {spaces(marg + 7);print_bits(f_set[e]);}
        nl();rgb(255,255,255);
        //spaces(marg);printf(" p  =  ");print_p(p);nl();
        cursor_to(enc_row ,0);
        spaces(marg);printf(" c  =  ");
        if (!c) rgb(255,0,0);
        print_bits(c);
        if (!c) rgb(255,255,255);
        cursor_to(enc_row + E + 1,0);
        spaces(marg);printf(" p  =  ");print_p(d);
        cursor_to(enc_row + 1,0);
        for (unt e = 0; e < E; e++ ) {
            c = rot_ca(f_set[e%F], 1, c);
            usleep(row_delay);
            spaces(marg+ 7);;print_c_highlights(c);
        }
        //if (d != p) fail++;
        //printf("\nERRORS %d", fail); 
        usleep(page_delay);

    }

}
