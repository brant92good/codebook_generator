// 陣列版雙向串列. 用前必須先 init 串好(0 與 n+1 是 sentinel, 資料放 1..n),
// 否則 cut/insert 解參考 NULL 直接 segfault. cut(p): 把 p 從串列拔出並回傳;
// insert(p,q): 把 q 插到 p 右邊. sentinel 本身不可被 cut.
struct node{
    struct node *nxt, *prv;
    long long v;
}pos[100002];

void init(int n){ // 0 -> 1 -> ... -> n -> n+1
    for(int i=0;i<=n+1;i++){
        pos[i].nxt = (i<=n ? &pos[i+1] : NULL);
        pos[i].prv = (i>=1 ? &pos[i-1] : NULL);
    }
}

inline node* cut(node *p) // cut the node
{
    p->nxt->prv = p->prv;
    p->prv->nxt = p->nxt;
    p->nxt = p->prv = NULL;
    return p;
}

inline node* insert(node *p, node *q) // insert node q to right side of node p
{
    q->nxt = p->nxt;
    p->nxt->prv = q;
    q->prv = p;
    p->nxt = q;
    return q;
}
