#include <cassert>
#include <algorithm>
#include <iostream>
#include <utility>
#include <vector>
using namespace std;

typedef long long LL;
typedef vector<int> VI;

struct PriceWeights
{
    int price, min_weight, max_weight;
    LL min_count, max_count;

    bool operator< (const PriceWeights &o) const { return price < o.price; }
};

struct TreeNode
{
    TreeNode(size_t i, TreeNode *l = 0, TreeNode *r = 0)
        : left(l), right(r), index(i) { }
    ~TreeNode() { delete left; delete right; }

    TreeNode * const left, * const right;
    const size_t index;
};

template<class Comp>
struct MinTree
{
    MinTree(Comp c, VI &v)
        : comp(c), values(v), nodes(create_node(0, v.size())) { };
    size_t find_min_index(size_t start, size_t length) const;
    ~MinTree() { delete nodes; }

private:
    Comp comp;
    VI &values;
    TreeNode *nodes;

    TreeNode *create_node(size_t begin, size_t end);
    size_t find_min_index( const TreeNode *node,
                           size_t node_begin, size_t node_end,
                           size_t range_begin, size_t range_end ) const;
    size_t min_index(size_t i, size_t j) const {
        return comp(values[i], values[j]) ? i : j;
    }
};

template<class Comp>
TreeNode *MinTree<Comp>::create_node(size_t begin, size_t end)
{
    if (end - begin == 1) return new TreeNode(begin);
    size_t middle = (begin + end)/2;
    TreeNode *left  = create_node(begin, middle),
             *right = create_node(middle, end);
    return new TreeNode(min_index(left->index, right->index), left, right);
}

template<class Comp>
size_t MinTree<Comp>::find_min_index( const TreeNode *node,
                                      size_t node_begin, size_t node_end,
                                      size_t range_begin, size_t range_end ) const
{
    if (range_begin <= node_begin && range_end >= node_end)
        return node->index;
    size_t middle = (node_begin + node_end)/2;
    if (range_end <= middle)
        return find_min_index(node->left, node_begin, middle, range_begin, range_end);
    if (range_begin >= middle)
        return find_min_index(node->right, middle, node_end, range_begin, range_end);
    return min_index( find_min_index(node->left, node_begin, middle, range_begin, middle),
                      find_min_index(node->right, middle, node_end, middle, range_end) );
}

template<class Comp>
size_t MinTree<Comp>::find_min_index(size_t begin, size_t length) const
{
    size_t n = values.size();
    if (length >= n) {
        return nodes->index;
    }
    size_t end = begin + length;
    if (end <= n) {
        return find_min_index(nodes, 0, n, begin, end);
    } else {
        return min_index( find_min_index(nodes, 0, n, begin, n),
                          find_min_index(nodes, 0, n, 0, end - n) );
    }
}

static void gen_sequence(VI &v, int P1, int M, int A, int B)
{
    assert(0 < P1 && P1 <= M);
    v.clear();
    v.reserve(M);
    int x = P1;
    do {
        v.push_back(x);
        x = ((LL)A*x + B)%M + 1;
    } while (x != P1);
}

static LL num_solutions(LL i, LL P, LL N)
{
    assert(0 <= i && i < N && i < P);
    return (N - (i + 1))/P + 1;
}

static void generate_price_weights( vector<PriceWeights> &pws,
                                    LL N, const VI &P, const VI &W )
{
    pws.reserve(min((LL)P.size(), N));

    LL NP = P.size();
    LL NW = W.size();
    int K = __gcd(NP, NW);
    LL L = (LL)NP/K*NW;

    LL NV = NW/K;
    vector<int> V(NV);
    for (LL k = 0; k < K; ++k)
    {
        int step = K;
        for (LL i = 0; i < NV; ++i) {
            int j = (k + NP*i)%NW;
            V[i] = W[j];
            if (NP*i%NW == K) step = i;
        }
        MinTree<less<int> > min_tree(less<int>(), V);
        MinTree<greater<int> > max_tree(greater<int>(), V);
        for (LL i = k; i < min(N, NP); i += K) {
            LL n = num_solutions(i, NP, N);
            LL min_j = min_tree.find_min_index(i/K*step%NV, n);
            LL max_j = max_tree.find_min_index(i/K*step%NV, n);
            PriceWeights pw = { P[i], V[min_j], V[max_j],
                num_solutions(i + ((min_j - i/K*step)%NV + NV)%NV*NP, L, N),
                num_solutions(i + ((max_j - i/K*step)%NV + NV)%NV*NP, L, N) };
            pws.push_back(pw);
        }
    }
}

static void merge( vector<PriceWeights> &c,
                   const vector<PriceWeights> &a,
                   const vector<PriceWeights> &b )
{
    vector<PriceWeights>::const_iterator i = a.begin(), j = b.begin();
    while (i != a.end() && j != b.end())
    {
        if (i->price < j->price) {
            c.push_back(*i++);
        } else if (j->price < i->price) {
            c.push_back(*j++);
        } else {
            PriceWeights pw = { i->price,
                min(i->min_weight, j->min_weight),
                max(i->max_weight, j->max_weight), 0, 0 };
            if (pw.min_weight == i->min_weight) pw.min_count += i->min_count;
            if (pw.min_weight == j->min_weight) pw.min_count += j->min_count;
            if (pw.max_weight == i->max_weight) pw.max_count += i->max_count;
            if (pw.max_weight == j->max_weight) pw.max_count += j->max_count;
            c.push_back(pw);
            ++i, ++j;
        }
    }
    c.insert(c.end(), i, a.end());
    c.insert(c.end(), j, b.end());
}

static void aggregate(vector<PriceWeights> &pws, vector<pair<int, int> > &pairs)
{
    sort(pairs.begin(), pairs.end());
    size_t i = 0;
    while (i < pairs.size()) {
        PriceWeights pw = { pairs[i].first, pairs[i].second, pairs[i].second, 1, 1 };
        size_t j = i + 1;
        while (j < pairs.size() && pairs[i].first == pairs[j].first) {
            int weight = pairs[j].second;
            if (weight < pw.min_weight) pw.min_weight = weight, pw.min_count  = 0;
            if (weight > pw.max_weight) pw.max_weight = weight, pw.max_count  = 0;
            if (weight == pw.min_weight) ++pw.min_count;
            if (weight == pw.max_weight) ++pw.max_count;
            ++j;
        }
        pws.push_back(pw);
        i = j;
    }
}

static pair<LL,LL> solve(LL N, int P1, int W1, int M, int K, int A, int B, int C, int D)
{
    vector<PriceWeights> pws;
    int peel = (int)min(N, (LL)max(M, K));
    {
        vector<pair<int, int> > pairs;
        for (int p = 0; p < peel; ++p)
        {
            pairs.push_back(make_pair(P1, W1));
            P1 = ((LL)A*P1 + B)%M + 1;
            W1 = ((LL)C*W1 + D)%K + 1;
        }
        aggregate(pws, pairs);
    }
    if (peel < N) {
        vector<PriceWeights> pws2;
        vector<int> P, W;
        gen_sequence(P, P1, M, A, B);
        gen_sequence(W, W1, K, C, D);
        generate_price_weights(pws2, N - peel, P, W);
        sort(pws2.begin(), pws2.end());

        vector<PriceWeights> pws_merged;
        merge(pws_merged, pws, pws2);
        pws.swap(pws_merged);
    }

    pair<LL,LL> answer(0, 0);
    int last_weight = -1;
    for (vector<PriceWeights>::const_iterator it = pws.begin();
         it != pws.end(); ++it)
    {
        if (last_weight == -1 || it->min_weight < last_weight) {
            last_weight = it->min_weight;
            answer.second += it->min_count;
        }
    }
    last_weight = -1;
    for (vector<PriceWeights>::const_reverse_iterator it = pws.rbegin();
         it != pws.rend(); ++it)
    {
        if (last_weight == -1 || it->max_weight > last_weight) {
            last_weight = it->max_weight;
            answer.first+= it->max_count;
        }
    }
    return answer;
}

int main()
{
    int T = 0;
    cin >> T;
    for (int t = 1; t <= T; ++t) {
        LL N;
        int P1, W1, M, K, A, B, C, D;
        if (!(cin >> N >> P1 >> W1 >> M >> K >> A >> B >> C >> D)) {
            std::cerr << "Failed to read case #" << t << "!\n";
            return 1;
        } else {
            pair<LL,LL> answer = solve(N, P1, W1, M, K, A, B, C, D);
            std::cout << "Case #" << t << ": "
                      << answer.first << ' ' << answer.second << '\n';
        }
    }
}
