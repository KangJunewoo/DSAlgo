#include <stdio.h>

void swap(int* a, int* b);
// 왼쪽에 작은값, 오른쪽에 큰값 모아주고 인덱스 리턴해주는 함수.
int partition(int Dataset[], int left, int right);

// 실제 퀵소트 함수
void QuickSort(int Dataset[], int left, int right);

int main(){
  int Dataset[] = {6,4,2,3,1,5};
  int length = sizeof(Dataset)/sizeof(Dataset[0]);
  int i=0;

  // 맨처음~맨끝 퀵소트 시작
  QuickSort(Dataset, 0, length-1);

  for(i=0;i<length;i++){
    printf("%d ", Dataset[i]);
  }
  printf("\n");
  return 0;
}

void swap(int* a, int* b){
  int temp = *a;
  *a=*b;
  *b=temp;
}

int partition(int Dataset[], int left, int right){
  int first = left;
  // 피벗은 맨 왼쪽으로 잡음.
  int pivot = Dataset[first];

  left++;
  // TODO : 등호는 혹시나 있을 에러(?)를 막기 위해 적절히 들어간듯. 나중에 탐구해보자.
  while(left<=right){
    while(Dataset[left] <= pivot && left<right) left++;
    while(Dataset[right] > pivot && left<=right) right--;

    if(left<right) swap(&Dataset[left], &Dataset[right]);
    else break;
  }
  swap(&Dataset[first], &Dataset[right]);
  return right;
}

void QuickSort(int Dataset[], int left, int right){
  if(left<right){
    int i = partition(Dataset, left, right);
    QuickSort(Dataset, left, i-1);
    QuickSort(Dataset, i+1, right);
  }
}