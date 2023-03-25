#include <bits/stdc++.h>
using namespace std;
long long n, bz, s = 0, mid, leftt = -1, longest, trees[1000008];

int main() {
	scanf("%lld%lld", &n, &bz);
	for (int i = 1; i <= n; i++) {
		scanf("%lld", &trees[i]);
		longest = max(longest, trees[i]); //找到最长木材
	}
	longest += 1;
	while (leftt + 1 != longest) {
		mid = leftt + (longest - leftt) / 2; //从中间点开始作为伐木机高度
		s = 0;
		for (int i = 1; i <= n; i++)
			if (trees[i] > mid) //树的高度大于伐木机高度
				s += trees[i] - mid; //高的部分累加
		if (s < bz) //木材不足
			longest = mid ; //在左边搜 减小高度增加木材
		else
			leftt = mid ; //在右边搜 增加高度减小木材
	}
	cout << leftt ;
	return 0;
}