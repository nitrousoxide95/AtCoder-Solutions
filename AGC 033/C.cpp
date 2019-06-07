#include "stdafx.h"
#pragma warning(disable:4996)

#include <queue>
#include <cstdio>
#include <iostream>
#include <algorithm>

using namespace std;

const int maxn = 210000;

struct edge{
	int v,next;
};

edge g[maxn << 1];
int head[maxn], dist[maxn];
queue<int> q;

void insert(int u,int v){
	static int id;
	g[++id].v = v;
	g[id].next = head[u];
	head[u] = id;
}

void bfs(int source){
	memset(dist, 0, sizeof dist);
	dist[source] = 1;
	while (!q.empty()) q.pop();
	q.push(source);
	while (!q.empty()){
		int u = q.front();
		q.pop();
		for (int i = head[u];i;i = g[i].next){
			int v = g[i].v;
			if (dist[v] == 0){
				dist[v] = dist[u] + 1;
				q.push(v);
			}
		}
	}
}

int main()
{
	int n;
	scanf("%d", &n);
	for (int i = 1;i < n;i++){
		int x, y;
		scanf("%d%d",&x ,&y);
		insert(x, y);
		insert(y, x);
	}
	bfs(1);
	int maxid = 0;
	for (int i = 1;i <= n;i++){
		if (dist[i] > dist[maxid]) maxid = i;
	}
	bfs(maxid);
	int diameter = 0;
	for (int i = 1;i <= n;i++) diameter = max(diameter, dist[i]);
	if (diameter % 3 == 2) printf("Second\n");
	else printf("First\n");
    return 0;
}

