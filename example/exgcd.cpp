// C++ Version
//扩展欧几里得，通过递归找到ax+by=gcd（a,b)的解
int Exgcd(int a, int b, int &x, int &y) {
  if (!b) {
    x = 1;
    y = 0;
    return a;//从a,b到b,a%b，再继续像欧几里得算法那样往下（求最大公约数）得到最后的情况x=1,y=0
  }
  int d = Exgcd(b, a % b, x, y);//
  int tmp = x;
  x = y;
  y = tmp - (a / b) * y;
  return d;
}