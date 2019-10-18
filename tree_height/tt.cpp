#include <iostream>
#include <vector>

using namespace std;

void fillDepth(vector<int> parent, int i, int depth[])
{
	if (depth[i])
		return;
	if (parent[i] == -1)
	{
		depth[i] = 1;
		return;
	}
	if (depth[parent[i]] == 0)
		fillDepth(parent, parent[i], depth);
	depth[i] = depth[parent[i]] + 1;
}
int findHeight(vector<int> parent, int n)
{
	int depth[n];
	for (int i = 0; i < n; i++)
		depth[i] = 0;
	for (int i = 0; i < n; i++)
		fillDepth(parent, i, depth);
	int ht = depth[0];
	for (int i=1; i<n; i++)
		if (ht < depth[i])
			ht = depth[i];
	return ht;
}

int main()
{
	int n;
	cin>>n;
	vector<int> parent(n);
	for(int i=0;i<n;i++)
        cin>>parent[i];
	cout <<findHeight(parent, n);
	return 0;
}
