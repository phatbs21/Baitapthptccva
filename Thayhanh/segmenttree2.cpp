struct SegmentTree
{
	vector<int> tree, lazy, sumB;
	// với nút i quản lý đoạn (l, r) sumB[i] = bl + b(l+1) + .. + b(r-1) + br
	int n; // độ dài của dãy do cây Segment Tree quản lý

	SegmentTree()
	{
		n = 0;
	}

	// hàm khởi tạo nút i quản lý đoạn (l, r), tính sumB[i]
	void init(int i, int l, int r, int b[])
	{
		if (l > r)
			return;
		if (l == r)
		{ // trường hợp nút lá
			sumB[i] = b[l];
			return;
		}

		int m = (l + r) >> 1;
		// gọi đệ quy để khởi tạo hai nhánh con
		init(2 * i, l, m, b);
		init(2 * i + 1, m + 1, r, b);
		sumB[i] = sumB[2 * i] + sumB[2 * i + 1];
	}

	// khởi tạo cây Segment Tree quản lý dãy độ dài _n với dãy b là b1 b2 ... b(_n)
	SegmentTree(int _n, int b[])
	{
		n = _n;
		tree.assign(4 * n + 7, 0);
		lazy.assign(4 * n + 7, 0);
		sumB.assign(4 * n + 7, 0);
		init(1, 1, n, b);
	}

	// đẩy thông tin lazy update từ nút i xuống hai nút con
	void pushDown(int i)
	{
		for (int j = 2 * i; j <= 2 * i + 1; j++)
		{
			tree[j] += lazy[i] * sumB[j];
			lazy[j] += lazy[i];
		}
		lazy[i] = 0;
	}

	// xét nút i quản lý đoạn (l, r); đang trong truy vấn tăng đoạn (u, v) thêm c
	void update(int i, int l, int r, int u, int v, int c)
	{
		// trường hợp đoạn (l, r) và (u, v) không tồn tại hoặc không giao nhau
		if (l > v || r < u || l > r || v < u)
			return;

		// trường hợp đoạn (l, r) nằm hoàn toàn trong đoạn (u, v)
		if (u <= l && r <= v)
		{
			tree[i] += c * sumB[i];
			lazy[i] += c;
			return;
		}

		pushDown(i);
		int m = (l + r) >> 1;
		// gọi đệ quy để cập nhật hai nhánh con
		update(2 * i, l, m, u, v, c);
		update(2 * i + 1, m + 1, r, u, v, c);
		tree[i] = tree[2 * i] + tree[2 * i + 1];
	}

	// đang xét nút i quản lý đoạn (l, r), cần tính tổng các số từ u đến v
	int getSum(int i, int l, int r, int u, int v)
	{
		// trường hợp hai đoạn (l, r) và (u, v) không giao nhau
		if (l > v || r < u || l > r || v < u)
			return 0;

		// trường hợp cả đoạn (l, r) nằm trong đoạn (u, v), nghĩa là cả đoạn cần tăng
		if (u <= l && r <= v)
			return tree[i];

		pushDown(i, l, r);
		int m = (l + r) >> 1;
		int L = getSum(2 * i, l, m, u, v);
		int R = getSum(2 * i + 1, m + 1, r, u, v);
		return L + R;
	}

	void update(int l, int r, int c)
	{
		update(1, 1, n, l, r, c);
	}

	int getSum(int l, int r)
	{
		return getSum(1, 1, n, l, r);
	}
};
