#include<bits/stdc++.h>
using namespace std;
//进程
struct process{
    int id;//进程id
    int arrive_time;//到达时间
    int serve_time;//服务时间
    int start_time;//开始时间
    int run_time;//运行时间
    int end_time;//结束时间
    int turn_time; //周转时间
    int weight_turn_time;//带权周转时间
    int wait_time;//等待时间
    int priority;//优先级
    char state;//状态
    //初始化
    process(){
        id = 0;
        arrive_time = 0;
        serve_time = 0;
        start_time = 0;
        end_time = 0;
        turn_time = 0;
        weight_turn_time = 0;
        wait_time = 0;
        state = 'W';
    }
    bool operator<(const process &a)const{
        return arrive_time > a.arrive_time;
    }

};
int time_ = 0;

vector<process> v;
//进程队列
priority_queue<process,vector<process>,less<process>> q;
//运行队列
vector<process>run_q;
//完成队列
vector<process>finish_q;
//就绪队列
vector<process> temp;

void init(){
    for (int i = 1; i <= 5;i++){
        run_q.push_back(process());
    }
}

//输出进程
void print_process(vector<process> v){
    cout<<"进程id\t到达\t服务\t开始\t结束\t周转\t带权周转"<<endl;
    int flag = 0;
    for (int i = 0; i < v.size();i++){
        if(v[i].id!=0){
            cout << v[i].id << "\t" << v[i].arrive_time << "\t" << v[i].serve_time << "\t" << v[i].start_time << "\t" << v[i].end_time << "\t" << v[i].turn_time << "\t" << v[i].weight_turn_time << endl;
            flag = 1;
        }
    }
    if(v.size()==0||flag==0)
        cout << "无" << endl;
}
//随机生成进程
void random_process(){
    srand(time(NULL));
    int maxn = 10;
    for (int i = 1; i <= 50;i++){
        process p;
        p.id = i;
        p.arrive_time = rand() % maxn;
        p.serve_time = rand() % maxn+1;
        p.state = 'W';
        v.push_back(p);
        q.push(p);
    }
    sort(v.begin(), v.end(), [](process a, process b) { 
        return a.arrive_time < b.arrive_time; });
    print_process(v);
}


//短进程优先
void SPN(){
    random_process();
    time_ = 0;
    init();
    while(!q.empty()||!temp.empty()||finish_q.size()!=v.size()){
        
        while(!q.empty()&&q.top().arrive_time<=time_){
            temp.push_back(q.top());
            q.pop();
        }
        sort(temp.begin(), temp.end(), [](process a, process b) { 
            return a.serve_time > b.serve_time; });
        for (int i = temp.size()-1 ; i >=0;i--){
            process p = temp[i];
            p.start_time = time_;
            p.end_time = time_ + p.serve_time;
            p.turn_time = p.end_time - p.arrive_time;
            p.weight_turn_time = p.turn_time / p.serve_time;
            p.state = 'F';
            for(int j=0;j<run_q.size();j++){
                if(run_q[j].end_time<=time_){
                    if(run_q[j].end_time!=0)
                        finish_q.push_back(run_q[j]);
                    run_q[j] = p;
                    temp.pop_back();
                    break;
                }
            }
        }
        if(temp.empty()){
            for (int i = 0; i < run_q.size();i++){
                if(run_q[i].end_time<=time_){
                    if(run_q[i].end_time!=0)
                        finish_q.push_back(run_q[i]);
                    run_q[i] = process();
                }
            }
        }
        sort(run_q.begin(), run_q.end(), [](process a, process b) { 
            return a.end_time < b.end_time; });

            cout<<"当前时间："<<time_<<endl;
            cout << "当前运行队列："<<endl;
            print_process(run_q);
            cout << "当前就绪队列："<<endl;
            print_process(temp);
            cout << "当前完成队列："<<endl;
            print_process(finish_q);
            cout << endl;

            time_++;
   }

}
//高响应比优先
void HRRN(){
    random_process();
    time_ = 0;
    init();
    while(!q.empty()||!temp.empty()||finish_q.size()!=v.size()){
        
        while(!q.empty()&&q.top().arrive_time<=time_){
            temp.push_back(q.top());
            q.pop();
        }
        sort(temp.begin(), temp.end(), [](process a, process b) { 
            return (a.serve_time+time_-a.arrive_time) / a.serve_time > (b.serve_time+time_-b.arrive_time) / b.serve_time; });
        for (int i = temp.size()-1 ; i >=0;i--){
            process p = temp[i];
            p.start_time = time_;
            p.end_time = time_ + p.serve_time;
            p.turn_time = p.end_time - p.arrive_time;
            p.weight_turn_time = p.turn_time / p.serve_time;
            p.state = 'F';
            for(int j=0;j<run_q.size();j++){
                if(run_q[j].end_time<=time_){
                    if(run_q[j].end_time!=0)
                        finish_q.push_back(run_q[j]);
                    run_q[j] = p;
                    temp.pop_back();
                    break;
                }
            }
        }
        if(temp.empty()){
            for (int i = 0; i < run_q.size();i++){
                if(run_q[i].end_time<=time_){
                    if(run_q[i].end_time!=0)
                        finish_q.push_back(run_q[i]);
                    run_q[i] = process();
                }
            }
        }
        sort(run_q.begin(), run_q.end(), [](process a, process b) { 
            return a.end_time < b.end_time; });

            cout<<"当前时间："<<time_<<endl;
            cout << "当前运行队列："<<endl;
            print_process(run_q);
            cout << "当前就绪队列："<<endl;
            print_process(temp);
            cout << "当前完成队列："<<endl;
            print_process(finish_q);
            cout << endl;

            time_++;
   }

}

//时间片轮转调度算法
void RR(){
    random_process();
    time_ = 0;
    init();
    while(!q.empty()||!temp.empty()||finish_q.size()!=v.size()){
        
        while(!q.empty()&&q.top().arrive_time<=time_){
            temp.push_back(q.top());
            q.pop();
        }
        sort(temp.begin(), temp.end(), [](process a, process b) { 
            return a.serve_time > b.serve_time; });
        for (int i = temp.size()-1 ; i >=0;i--){
            process p = temp[i];
            p.start_time = time_;
            p.end_time = time_ + p.serve_time;
            p.turn_time = p.end_time - p.arrive_time;
            p.weight_turn_time = p.turn_time / p.serve_time;
            p.state = 'F';
            for(int j=0;j<run_q.size();j++){
                if(run_q[j].end_time<=time_){
                    if(run_q[j].end_time!=0)
                        finish_q.push_back(run_q[j]);
                    run_q[j] = p;
                    temp.pop_back();
                    break;
                }
            }
        }
        if(temp.empty()){
            for (int i = 0; i < run_q.size();i++){
                if(run_q[i].end_time<=time_){
                    if(run_q[i].end_time!=0)
                        finish_q.push_back(run_q[i]);
                    run_q[i] = process();
                }
            }
        }
        sort(run_q.begin(), run_q.end(), [](process a, process b) { 
            return a.end_time < b.end_time; });

            cout<<"当前时间："<<time_<<endl;
            cout << "当前运行队列："<<endl;
            print_process(run_q);
            cout << "当前就绪队列："<<endl;
            print_process(temp);
            cout << "当前完成队列："<<endl;
            print_process(finish_q);
            cout << endl;

            time_++;
   }

}
int main(){
   SPN();
    //HRRN();
    
    return 0;
}