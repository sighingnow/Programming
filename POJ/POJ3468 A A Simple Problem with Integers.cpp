#include <cstdio>
using namespace std;

const int max_n = 800800;

struct Node {
	long long x, y;
	long long int sum;
	long long lazy;
} node[max_n];

void maketree(long long int a, long long int b, long long int k) {
	node[k].x = a;
	node[k].y = b;
	
	if(a == b) {
		scanf("%I64d", &node[k].sum);
		node[k].lazy = 0;
		return;
	}
	
	long long int mid = (a+b) >> 1;
	maketree(a, mid, k << 1);
	maketree(mid+1, b, k << 1 | 1);
	
	node[k].sum = node[k<<1].sum + node[k<<1|1].sum;
}

void push_down(long long int k, long long int a, long long int b) {
	if(node[k].lazy) {
		node[k<<1].lazy += node[k].lazy;
		node[k<<1|1].lazy += node[k].lazy;
		node[k<<1].sum += (node[k<<1].y-node[k<<1].x+1)*node[k].lazy;
		node[k<<1|1].sum += (node[k<<1|1].y-node[k<<1|1].x+1)*node[k].lazy;
		node[k].lazy = 0;
	}
}

void update(long long int a, long long int b, long long int delta, long long int k) {
	if(a <= node[k].x && b >= node[k].y) {
		node[k].lazy += delta;
		node[k].sum += (node[k].y-node[k].x+1)*delta;
		return;
	}
	push_down(k, a, b);
	if(a <= node[k<<1].y) {
		update(a, b, delta, k<<1);
	}
	if(b >= node[k<<1|1].x) {
		update(a, b, delta, k<<1|1);
	}
	node[k].sum = node[k<<1].sum + node[k<<1|1].sum;
} 
 
long long int query(long long int a, long long int b, long long int k) {
	if(a <= node[k].x && b >= node[k].y) {
		return node[k].sum;
	}
	push_down(k, a, b);
	long long int ans = 0;
	if(a <= node[k<<1].y) {
		ans += query(a, b, k << 1);
	}
	if(b >= node[k<<1|1].x) {
		ans += query(a, b, k << 1 | 1);
	}
	return ans;
}

int main(int argc, char **argv) {
	freopen("data.in", "r", stdin);
	long long int n, q;
	scanf("%I64d %I64d", &n, &q);
	maketree(1, n, 1);
	char cmd;
	int u, v, delta;
	for(long long int i = 1; i <= q; ++i) {
		scanf("\n%c", &cmd);
		switch (cmd) {
			case 'C':
				scanf("%d %d %d", &u, &v, &delta);
				update(u, v, delta, 1);
				break;
			case 'Q':
				scanf("%d %d", &u, &v);
				printf("%I64d\n", query(u, v, 1));
				break;
			default:
				break;
		}
	}
	
	return 0;
}
