#include <bits/stdc++.h>
using namespace std;
long long n, bz, s = 0, mid, leftt = -1, longest, trees[1000008];

int main() {
	scanf("%lld%lld", &n, &bz);
	for (int i = 1; i <= n; i++) {
		scanf("%lld", &trees[i]);
		longest = max(longest, trees[i]); //�ҵ��ľ��
	}
	longest += 1;
	while (leftt + 1 != longest) {
		mid = leftt + (longest - leftt) / 2; //���м�㿪ʼ��Ϊ��ľ���߶�
		s = 0;
		for (int i = 1; i <= n; i++)
			if (trees[i] > mid) //���ĸ߶ȴ��ڷ�ľ���߶�
				s += trees[i] - mid; //�ߵĲ����ۼ�
		if (s < bz) //ľ�Ĳ���
			longest = mid ; //������� ��С�߶�����ľ��
		else
			leftt = mid ; //���ұ��� ���Ӹ߶ȼ�Сľ��
	}
	cout << leftt ;
	return 0;
}