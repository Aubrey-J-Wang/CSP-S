//���P7912, [CSP-J 2021 T4] С�ܵĹ��� 
//https://www.luogu.com.cn/problem/P7912
//https://www.luogu.com.cn/problem/solution/P7912 ����ƪ lcyxds 
//������˫���� 
//���Ӷȣ� O(n) 

#include <iostream>
#include <cstdio>
#include <vector>
using namespace std;

const int MAXN = 2e5+10;

struct Node{
  int prev;
  int val;
  int next;
};

int n;
int shuiguo[MAXN];
Node headList[MAXN];
Node shuiguoList[MAXN];
int cc;

void EatOne(int pos) {
  int prev = shuiguoList[pos].prev;
  int next = shuiguoList[pos].next;
  shuiguoList[prev].next = next;
  shuiguoList[next].prev = prev;
  printf("%d ", pos);
}

void Del(int pos) {
  int prev = headList[pos].prev;
  int next = headList[pos].next;
  headList[prev].next = next;
  headList[next].prev = prev;
}

void Chi() {
  int solo = headList[0].next;
  int nowcolor = shuiguo[headList[solo].val]; //��ǰ����һ��ˮ�� 
  
  while (solo!=cc+1) { //cc������ı�� 
    if (shuiguo[headList[solo].val]!=nowcolor) {
      Del(solo);
      solo = headList[solo].next;
      continue;
    }
    EatOne(headList[solo].val);
    headList[solo].val = shuiguoList[headList[solo].val].next;
    if (shuiguo[headList[solo].val]!=nowcolor) {
      Del(solo);
    }
    solo = headList[solo].next;
    nowcolor^=1;
  }
  putchar('\n');
}

int main() {
  scanf("%d", &n);
  shuiguoList[0].next = 1;
  
  for (int i = 1; i <= n; i++) {
    scanf("%d", &shuiguo[i]);
    shuiguoList[i].prev = i-1;
    shuiguoList[i].next = i+1;
  }
  
  shuiguo[0] = 2;
  shuiguo[n+1] = 2;
  headList[0].next = 1;
  
  for (int i = 1; i <= n; i++) {     //�� "��" ����˫���� 
    if (shuiguo[i]!=shuiguo[i-1]) {
      cc++;
      headList[cc].prev = cc-1;
      headList[cc].next = cc+1;
      headList[cc].val = i;
    }
  }
  
  while (shuiguoList[0].next!=n+1) {  //O(n)
    Chi();
  }
  
  return 0;
}

