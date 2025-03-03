#include <iostream>
#include <vector>
using namespace std;

const int MAX_N = 750;

// ���������� ������� ��� �������� ������
int parent[MAX_N + 1], leftChild[MAX_N + 1], rightChild[MAX_N + 1];

// ������� ��� ������ ������� v � � ��������� p
void swapNodes(int v) {
    int p = parent[v]; // �������� ������� v
    if (p == 0) return; // ���� v � ������, ������ �� ������

    int pp = parent[p]; // ������ �������� p
    bool isLeftChild = (leftChild[p] == v); // ���������, �������� �� v ����� �������� p

    // ������ ������� ������� v � � �������� p
    if (pp) {
        if (leftChild[pp] == p) leftChild[pp] = v;
        else rightChild[pp] = v;
    }

    parent[v] = pp;
    parent[p] = v;

    if (isLeftChild) {
        leftChild[p] = leftChild[v];
        if (leftChild[v]) parent[leftChild[v]] = p;
        leftChild[v] = p;
    }
    else {
        rightChild[p] = rightChild[v];
        if (rightChild[v]) parent[rightChild[v]] = p;
        rightChild[v] = p;
    }
}

int current_root(int node) {
    while (parent[node] != 0) {
        node = parent[node];
    }
    return node;
}

// ����������� ����� ������ � ������� LVR
void traverseLVR(int node, vector<int>& result) {
    if (leftChild[node]) traverseLVR(leftChild[node], result);
    result.push_back(node);
    if (rightChild[node]) traverseLVR(rightChild[node], result);
}

int main() {
    int N, Q;
    cin >> N >> Q;

    // ������������� ������
    for (int i = 1; i <= N; ++i) {
        leftChild[i] = (2 * i <= N) ? 2 * i : 0;
        rightChild[i] = (2 * i + 1 <= N) ? 2 * i + 1 : 0;
        if (leftChild[i]) parent[leftChild[i]] = i;
        if (rightChild[i]) parent[rightChild[i]] = i;
    }

    // ������ ��������
    vector<int> queries(Q);
    for (int i = 0; i < Q; ++i) {
        cin >> queries[i];
    }

    // ��������� ��������
    for (int v : queries) {
        swapNodes(v);
    }

    // ��������� ����� ������ � ������� LVR
    vector<int> result;
    traverseLVR(current_root(1), result);

    // ������� ���������
    for (size_t i = 0; i < result.size(); ++i) {
        if (i > 0) cout << " ";
        cout << result[i];
    }
    cout << endl;

    return 0;
}