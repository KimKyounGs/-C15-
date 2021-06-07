//// 이 문제의 키워드는 이진 탐색을 사용하여 key 값의 갯수를 구할 때 " 'lower_bound, upper_bound'를 떠올려 낼 수 있는가?" 이다. 나도 처음에는 저 방법을 답지를 보고난 후에 알게 되었다. 
//// 확실히 답지를 보고난 후 드는 생각이 'lower_bound, upper_bound'를 쓰면 더 편리하게 답을 구할 수 있겠다고 생각했다. 그렇다고 내가 한 것이 별로인가? 나는 그렇게 생각하지 않는다!!
//// 참고로 계수정렬 또한 생각했지만 문제 조건인 시간 복잡도 O(logN)에 부합되지 않았기 때문에 쓰지 않았다.
// 내가 한 것
#include <bits/stdc++.h>

using namespace std;

int N, x, cnt = 0;
vector <int> Sequence;

int binarySearch (vector<int>& arr, int target, int start, int end) {
        while (start <= end) {
                int mid = (start + end) / 2;
                if (arr[mid] == target) {
                        cnt ++;
                        binarySearch(Sequence, target, mid + 1, end);
                        binarySearch(Sequence, target, start ,  mid - 1);
                        return 1;
                }
                else if (arr[mid] < target) start = mid + 1;
                else end = mid - 1;
        }
        return 0;
}

int main() {
        ios::sync_with_stdio(false);
 	cin.tie(NULL);

        cin >> N >> x;
        for (int i = 0; i < N; i ++) {
                int n;
                cin >> n;
                Sequence.push_back(n);
        }

        int result = binarySearch(Sequence, x, 0, N-1);

        if (result == 1) {
                cout << cnt << '\n';
        }
        else {
                cout << -1 << '\n';
        }
}


// 답
  
#include <bits/stdc++.h>

using namespace std;

// 값이 [left_value, right_value]인 데이터의 개수를 반환하는 함수
int countByRange(vector<int>& v, int leftValue, int rightValue) {
    vector<int>::iterator rightIndex = upper_bound(v.begin(), v.end(), rightValue);
    vector<int>::iterator leftIndex = lower_bound(v.begin(), v.end(), leftValue);
    return rightIndex - leftIndex;
}

int n, x;
vector<int> v;

int main() {
    // 데이터의 개수 N, 찾고자 하는 값 x 입력받기
    cin >> n >> x;

    // 전체 데이터 입력 받기
    for (int i = 0; i < n; i++) {
        int temp;
        cin >> temp;
        v.push_back(temp);
    }

    // 값이 [x, x] 범위에 있는 데이터의 개수 계산
    int cnt = countByRange(v, x, x);

    // 값이 x인 원소가 존재하지 않는다면
    if (cnt == 0) {
        cout << -1 << '\n';
    }
    //  값이 x인 원소가 존재한다면
    else {
        cout << cnt << '\n';
    }
}