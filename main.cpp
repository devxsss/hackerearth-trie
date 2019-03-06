#include <iostream>
#include <stdio.h>
using namespace std;
const int alpha = 26;
struct trienode {
	struct trienode*child[alpha];
	bool lastnode;
	int weight;
};

struct trienode* getnode(void) {
	struct trienode*pnode = new trienode;
	for (int i = 0; i < alpha; i++) {
		pnode->child[i] = NULL;

	}
	pnode->lastnode = false;
	return pnode;
}

void insert(struct trienode* & root, string key, int weight) {
	struct trienode*pcrawl = root;
	for (int i = 0; i < key.length(); i++) {
		int index = key[i] - 'a';
		if (!pcrawl->child[index] ) {
			pcrawl->child[index] = getnode();
			pcrawl->child[index]->weight = weight;
		}
		else if (pcrawl->child[index] && pcrawl->child[index]->weight < weight)
		{
			pcrawl->child[index]->weight = weight;

		}
		pcrawl = pcrawl->child[index];
	}

}

int searchh(struct trienode* &root, string key) {
	struct trienode* p = root;
	int weigh;
	for (int i = 0; i < key.length(); i++) {
		int index = key[i] - 'a';

		if (!p->child[index])
			return -1;
		else
		{
			weigh = p->child[index]->weight;
			p = p->child[index];

		}
	}
	return weigh;
}
int main()
{
	struct trienode*root = getnode();
	int db, weight,pencarian;

	char str[256];
	char searc[256];
	scanf("%d %d", &db, &pencarian);
	for (int i = 0; i < db; i++) {
		scanf("%s", str);
		scanf("%d", &weight);
		insert(root, str, weight);
	}
	for (int k = 0; k < pencarian; k++) {
		scanf("%s", searc);
		int p = searchh(root, searc);
		p == -1 ? cout << "-1/n" : cout << p << "\n";
	}

	return 0;
}

