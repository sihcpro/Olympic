
void down(int id) {
    int t = nodes[id].lazy;
    nodes[id*2].lazy += t;
    nodes[id*2].val += t;

    nodes[id*2+1].lazy += t;
    nodes[id*2+1].val += t;

    nodes[id].lazy = 0;
}

void update(int id, int l, int r, int u, int v, int val) {
    if (v < l || r < u) {
        return ;
    }
    if (u <= l && r <= v) {
        // Khi cài d?t, ta LUÔN Ð?M B?O giá tr? c?a nút du?c c?p nh?t Ð?NG TH?I v?i
        // giá tr? lazy propagation. Nhu v?y s? tránh sai sót.
        nodes[id].val += val;
        nodes[id].lazy += val;
        return ;
    }
    int mid = (l + r) / 2;

    down(id); // d?y giá tr? lazy propagation xu?ng các con

    update(id*2, l, mid, u, v, val);
    update(id*2+1, mid+1, r, u, v, val);

    nodes[id].val = max(nodes[id*2].val, nodes[id*2+1].val);
}

int get(int id, int l, int r, int u, int v) {
    if (v < l || r < u) {
        return -INFINITY;
    }
    if (u <= l && r <= v) {
        return nodes[id].val;
    }
    int mid = (l + r) / 2;
    down(id); // d?y giá tr? lazy propagation xu?ng các con

    return max(get(id*2, l, mid, u, v),
        get(id*2+1, mid+1, r, u, v));
    // Trong các bài toán t?ng quát, giá tr? ? nút id có th? b? thay d?i (do ta d?y lazy propagation
    // xu?ng các con). Khi dó, ta c?n c?p nh?t l?i thông tin c?a nút id d?a trên thông tin c?a các con.
}

