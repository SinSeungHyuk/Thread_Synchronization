// Thread.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include "pch.h"


using namespace std;
using std::thread;



void func1() {
    for (int i = 0; i < 10; i++) cout << "스레드 1 작동중\n";
}
void func2() {
    for (int i = 0; i < 10; i++) cout << "스레드 2 작동중\n";
}
void func3() {
    for (int i = 0; i < 10; i++) cout << "스레드 3 작동중\n";
}

void worker(vector<int>::iterator s, vector<int>::iterator end, int* result) {
    int sum = 0;
    for (auto itr = s; itr < end; ++itr) {
        sum += *itr;
    }
    *result = sum;

    // 스레드 id 구하기
    thread::id this_id = this_thread::get_id();
    printf("스레드 %x 에서 %d 부터 %d 까지 계산한 결과: %d\n",
        this_id, *s, *(end - 1), sum);
}

mutex m; // mutex 객체
void worker2(int* cnt) {
    for (int i = 0; i < 10000; i++) {
        lock_guard<mutex> mutex_guard(m);
        *cnt += 1;
    }
}

void worker3(promise<string>* p) {
    // 약속 이행. 이 결과는 future에 들어간다.
    this_thread::sleep_for(chrono::seconds(10)); // 10초동안 스레드 대기
    p->set_value("promise data");
}

void runner(shared_future<void> start) {
    start.get();
    cout << "출발\n";
}

int task(int x) { return 10 + x; }

int sum(const vector<int>& v, int start, int end) {
    int total = 0;
    for (int i = start; i < end; i++) {
        total += v[i];
    }
    return total;
}
int parallel_sum(const vector<int>& v) {
    future<int> lower_half_future =
        async(launch::async, sum, ref(v), 0, v.size() / 2);
    // upper : 501~1000 더하기
    int upper_half = sum(v, v.size() / 2, v.size());

    return lower_half_future.get() + upper_half;
}

// ============== semaphore

counting_semaphore<10> semaphore{ 5 }; // least max value : 1, counter : 1

void worker_sema(int id) {
    semaphore.acquire(); // wait (P) 연산

    // doing work
    cout << "thread " << id << " 세마포를 성공적으로 얻어냄" << endl;

    // releasing 반환
    semaphore.release(); // signal (V) 연산
    cout << "thread " << id << " 세마포에 반환함" << endl;
}

binary_semaphore b_semaphore(1);

void worker_b_sema(int id) {
    b_semaphore.acquire(); // wait (P) 연산

    // doing work
    cout << "thread " << id << " 이진 세마포 얻어냄" << endl;

    // 반환
    b_semaphore.release(); // signal (V) 연산
    cout << "thread " << id << " 세마포 반환" << endl;
}


int main()
{
    //thread t1(func1);
    //thread t2(func2);
    //thread t3(func3);

    //t1.detach();
    //t2.detach();
    //t3.detach();
    //===============================================

    //vector<int> data(10000);
    //for (int i = 1; i <= 10000; i++) data[i-1] = i;

    //// 각 스레드에서 계산된 부분 합들을 저장하는 벡터
    //vector<int> partial_sums(4);

    //vector<thread> workers;
    //for (int i = 0; i < 4; i++) {
    //    workers.push_back(thread(worker, data.begin() + (i * 2500),
    //        data.begin() + (i+1) * 2500, &partial_sums[i]));
    //}

    //for (int i = 0; i < 4; i++)  workers[i].join();

    //int total = 0;
    //for (int i = 0; i < 4; i++) total += partial_sums[i];
    //===============================================

    //int cnt = 0;
    //vector<thread> workers;
    //for (int i = 0; i < 4; i++) {
    //    workers.push_back(thread(worker2, &cnt));
    //}
    //for (int i = 0; i < 4; i++) {
    //    workers[i].join();
    //}
        //===============================================

    //promise<string> p;
    //// 미래에 string 데이터를 돌려주는 약속
    //future<string> data = p.get_future();
    //thread t(worker3, &p);

    //data.wait(); // 약속된 데이터 받을때까지 기다리기

    //while (true) {
    //    // 1초씩 기다려보기
    //    future_status status = data.wait_for(chrono::seconds(1));

    //    if (status == future_status::timeout) {
    //        cerr << ">"; // cerr : cout과 달리 버퍼를 바로 비워 디버깅에 용이
    //    }

    //    else if (status == future_status::ready) {
    //        cout << data.get();
    //        break;
    //    }
    //}
    //===============================================
    // 
    // 
    //promise<void> p;
    //shared_future<void> start = p.get_future();

    //thread t1(runner, start);
    //thread t2(runner, start);
    //thread t3(runner, start);

    //cerr << "준비..";
    //this_thread::sleep_for(chrono::seconds(1));
    //cerr << " 시작\n";

    //p.set_value();
    //
    //t1.join();
    //t2.join();
    //t3.join();
    //===============================================

    // int task(int x) { return 10 + x; }
    //packaged_task<int(int)> pack_task(task);
    //future<int> start = pack_task.get_future();

    //thread t(move(pack_task), 5);
    //cout << "결과: " << start.get();
        //===============================================

   
    //======================== 세마포

    thread t1(worker_sema, 1);
    thread t2(worker_sema, 2);
    thread t3(worker_sema, 3);

    t1.join();
    t2.join();
    t3.join();

    cout << endl << endl;
}
