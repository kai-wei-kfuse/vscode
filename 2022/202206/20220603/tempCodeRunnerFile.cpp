
    build(1, 1, n);
    for (int i = 1; i <= q; ++i) {
        int y, x;
        int l, r;
        read(y);
        if (y == 1) {
            read(x);
            s[x] = 0;
            /* change1(1, x, x, 0);
            for (int i = 4; i <= 7; ++i) {
                cout << t[i].li << " ";
            }
            cout << endl; */
        } else if (y == 2) {
            read(x);
            s[x] = 1;
            /* change1(1, x