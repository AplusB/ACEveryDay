#include<cstdio>
#include<iostream>
#include<algorithm>
using namespace std;
const int MAX_N = 50000 + 10;
const int INF = ~0U >> 1;
struct Node {
	Node*ch[2], *p;
	int size, val, mx;
	int add;
	bool rev;
	Node() {
		size = 0;
		val = mx = -INF;
		add = 0;
	}
	bool d() {
		return this == p->ch[1];
	}
	void setc(Node*c, int d) {
		ch[d] = c;
		c->p = this;
	}
	void addIt(int ad) {
		add += ad;
		mx += ad;
		val += ad;
	}
	void revIt() {
		rev ^= 1;
	}
	void relax();
	void upd() {
		size = ch[0]->size + ch[1]->size + 1;
		mx = max(val, max(ch[0]->mx, ch[1]->mx));
	}
} Tnull, *null = &Tnull;
Node mem[MAX_N], *C = mem;

void Node::relax() {
	if (add != 0) {
		for (int i = 0; i < 2; ++i) {
			if (ch[i] != null)
				ch[i]->addIt(add);
		}
		add = 0;
	}
	if (rev) {
		swap(ch[0], ch[1]);
		for (int i = 0; i < 2; ++i) {
			if (ch[i] != null)
				ch[i]->revIt();
		}
		rev = 0;
	}
}

Node*make(int v) {
	C->ch[0] = C->ch[1] = null;
	C->size = 1;
	C->val = v;
	C->mx = v;
	C->add = 0;
	C->rev = 0;
	return C++;
}

Node*build(int l, int r) {
	if (l >= r)
		return null;
	int m = (l + r) >> 1;
	Node*t = make(0);
	t->setc(build(l, m), 0);
	t->setc(build(m + 1, r), 1);
	t->upd();
	return t;
}

Node*root;

Node*rot(Node*t) {
	Node*p = t->p;
	p->relax();
	t->relax();
	int d = t->d();
	p->p->setc(t, p->d());
	p->setc(t->ch[!d], d);
	t->setc(p, !d);
	p->upd();
	if (p == root)
		root = t;
}

void splay(Node*t, Node*f = null) {
	while (t->p != f) {
		if (t->p->p == f)
			rot(t);
		else
			t->d() == t->p->d() ? (rot(t->p), rot(t)) : (rot(t), rot(t));
	}
	t->upd();
}

Node* select(int k) {
	for (Node*t = root;;) {
		t->relax();
		int c = t->ch[0]->size;
		if (k == c)
			return t;
		if (k > c)
			k -= c + 1, t = t->ch[1];
		else
			t = t->ch[0];
	}
}

Node*&get(int l, int r) { //[l,r)
	Node*L = select(l - 1);
	Node*R = select(r);
	splay(L);
	splay(R, L);
	return R->ch[0];
}

int n, m;

int main() {
	cin >> n >> m;
	root = build(0, n + 2);
	root->p = null;
	for (int i = 0; i < m; ++i) {
		int k, l, r, v;
		scanf("%d%d%d", &k, &l, &r);
		Node*&t = get(l, r + 1);
		if (k == 1) {
			scanf("%d", &v);
			t->addIt(v);
			splay(t);
		} else if (k == 2) {
			t->revIt();
			splay(t);
		} else {
			printf("%d\n", t->mx);
		}
	}
}
