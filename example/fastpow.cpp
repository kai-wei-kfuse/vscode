long long fastpow(long long a, long long b) {//递归
  if (b == 0) return 1;
  long long res = fastpow(a, b / 2);
  if (b % 2)
    return res * res * a;
  else
    return res * res;
}
long long binpow(long long a, long long b) {//非递归
  //if(b==0)return 1;
  long long res = 1;
  while (b > 0) {
    if (b & 1) res = res * a;//b&1:取第一位，如果是1说明需要，0说明不需要
    a = a * a;
    b >>= 1;//右移，1011 -> 101
  }
  return res;
}