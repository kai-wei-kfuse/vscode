#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define TIME_SLICE 2

// ����״̬������ �ȴ� ���� ���
enum process_type{
    process_type_wait = 'W',
    process_type_run = 'R',
    process_type_block = 'B',
    process_type_finish = 'F'
};

typedef struct PCB{ 
    // ������ 
    char name;
    // ���������Դ��
    int Max[100]; 
    // ����Ҫ����Դ��
    int Need[100];
    // �ѷ������Դ�� 
    int Allocate[100]; 
    // ����������ʱ�� 
    int run_time; 
    // ����״̬
    char state;
    // ָ����һ������
    PCB *next; 
}PCB; 

// ϵͳ��Դ������
char Name[100]={0};
// ϵͳ������Դ���� 
int Available[100];
// ����������Դ���� 
int Request[100];
// ���ϵͳ���ṩ��Դ��
int Work[100];  
// ���ϵͳ�Ƿ����㹻����Դ�������������
bool Finish[100];
// ��Ű�ȫ����
char Security[100];

// ���̵������
int M = 100;
// ��Դ�������
int N = 100;
// ��־�Ƿ����
bool flag = true; 
// ��������
// ��ʼ������
void init(PCB *list);
// �������� 
void create_process(PCB *list);
// ��ʾ��Դ����ͽ���������� 
void print(PCB *list);
// ��̽�Է�����Դ
void test(PCB *list);
// ��̽�Է�����Դ����
void Retest(PCB *list);
// �������м��㷨��������Դ�����Է�
bool bank(PCB *list);
// ��ȫ���㷨
bool safe(PCB *list);
// ʱ��Ƭ��ת�����㷨 
void round_robin(PCB *list);
// ������
int main(){ 
    printf("-----------------------------------------------------------------------\n");
    printf("||                        ���м��㷨��ʵ��                           ||\n");
    printf("-----------------------------------------------------------------------\n\n");
    PCB *list = (PCB *)malloc(sizeof(PCB));
    if(list == NULL){
        printf("��̬�����ڴ�ʧ�ܣ�");
    }
    list->next = NULL;
    
    srand((int)time(NULL));
    // ��ʼ������
    init(list);
    // ��ʾ��Դ����ͽ���������� 
    printf("***********************************************************************\n");
    print(list);
    // �����м��㷨�ж�ϵͳ��ǰʱ���Ƿ�ȫ������ȫ�Ͳ��ټ���������Դ 
    if(!safe(list)) {
        exit(0);
    }
    printf("\n***********************************************************************\n");
    // ʹ��ʱ��Ƭ��ת�����н��̵��� 
    round_robin(list); 
}
// ��ʼ������
void init(PCB *list){
    // mΪ��������nΪϵͳ��Դ����
    int m,n;
    // ��ʼ��ϵͳ��Դ������������Դ�� 
    printf("ϵͳ������Դ������Ϊ��");
    scanf("%d",&n);
    // ϵͳ��Դ������������ȫ�ֱ���N�������������ʹ�� 
    N = n;
    // ��Դ����
    char name;
    // ��Դ�� 
    int number; 
    for(int i = 1;i <= n;i++){
        printf("\t��Դ%d�����ƣ�",i);
        getchar();
        scanf("%c",&name);
        Name[i] = name;
        printf("\t��Դ%c�ĳ�ʼ����Ϊ��",name); 
        scanf("%d",&number);
        Available[i] = number;
    }
    // ��ʼ���������������̵����������Դ�� 
    printf("\n��������̵�������");    
    scanf("%d",&m);
    // ������������ȫ�ֱ���M�������������ʹ�� 
    M = m;
    create_process(list);
}
// �������� 
void create_process(PCB *list){
    // ͳ���ѷ����ϵͳ��Դ
    int temp[100] = {0};
    int number = 1; 
    while(number <= M){
        // ���̽ڵ� 
        PCB *p = (PCB *)malloc(sizeof(PCB));
        if(p == NULL){
            printf("��̬�����ڴ�ʧ�ܣ�");
        }
        // ������ 
        printf("\t�������%d���̵Ľ�������",number); 
        getchar();
        scanf("%c",&p->name);
        // ��־���� 
        bool flag;
        // ��ʼ�����������������Դ����������Դ�����ѷ�����Դ��
        do{
            flag = false; 
            for(int i = 1;i <= N;i++){ 
                p->Max[i] = rand()%10;
                if(p->Max[i] > Available[i]){ 
                    flag = true;
                    // printf("��Դ�������������ϵͳ����Դ�����������������!\n");
                    break;  
                }
                p->Need[i] = p->Max[i];
                p->Allocate[i] = 0;     
            }               
        }while(flag);
        // ����������ʱ�� 
        p->run_time = 0; 
        // ����״̬
        p->state = process_type_wait;
        // ָ����һ������
        p->next = NULL;
        if(list->next == NULL){
            list->next = p;
        }else{
            PCB *move = list->next;
            while(move->next != NULL){
                move = move->next;
            }
            move->next = p;     
        }
        number++;
    }
    printf("\n");
} 
// ��ʾ��Դ����ͽ���������� 
void print(PCB *list){
    printf("\nϵͳĿǰ���õ���Դ(Available):\n");
    for(int i = 1;i <= N;i++){
        printf("%c  ",Name[i]);
    }
    printf("\n");
    for(int i = 1;i <= N;i++){
        printf("%d  ",Available[i]);
    }
    printf("\n\n");
    printf("ϵͳ��ǰ����Դ�����������������������£�\n");
    printf("          Max        Allocate        Need\n");
    printf("������  ");
    //����������ͬ�е���Դ����Max��Allocate��Need�·ֱ��Ӧ 
    for(int i = 1;i <= 3;i++){
        for(int j = 1;j <= N;j++){
            printf("%c  ",Name[j]);
        }
        printf("     "); 
    }
    printf("������ʱ��   ����״̬\n");
    
    // �������� 
    PCB *p = list->next;
    while(p != NULL){
        //���ÿ�����̵�Max��Allocation��Need 
        printf("  %c\t",p->name);
        for(int j = 1;j <= N;j++)
            printf("%d  ",p->Max[j]);
        printf("     "); 
        for(int j = 1;j <= N;j++)
            printf("%d  ",p->Allocate[j]);
        printf("     ");
        for(int j = 1;j <= N;j++)
            printf("%d  ",p->Need[j]);
        printf("        ");
        printf("  %d\t  ",p->run_time); 
        printf("%c\n",p->state); 
        p = p->next;
    }
}
// ��̽�Է�����Դ
void test(PCB *list){ 
    // ������Դ�Ľ��� 
    PCB *p = list->next;
    // ���Ľ�����Ϣ 
    for(int i = 1;i <= N;i++){
        Available[i] -= Request[i];
        p->Allocate[i] += Request[i];
        p->Need[i] -= Request[i];
    }
}
// ��̽�Է�����Դ����
void Retest(PCB *list){
    // ������Դ�Ľ��� 
    PCB *p = list->next;
    // ��test�����෴ 
    for(int i = 1;i <= N;i++){
        Available[i] += Request[i];
        p->Allocate[i] -= Request[i];
        p->Need[i] += Request[i];
    }
}
// �������м��㷨��������Դ�����Է�
bool bank(PCB *list){
    PCB *p = list->next;
    // ���������������
    for(int i = 1;i <= N;++i){
        Request[i] = rand()%(p->Need[i]+1);
    }
    // ���������������Դ����Ϊ0����ʾ����� 
    int n = 0;
    for(int i = 1;i <= N;++i){
        if(Request[i] == 0){
            n++;
        }
    }
    if(n == N){
        flag = false;
        return false;
    }
    printf("\n%c�������� ���� ",p->name);
    for(int i = 1;i <= N;i++){
        printf("��Դ%c��",Name[i]);
        printf("%d   ",Request[i]); 
    }
    printf("\n\n"); 
    // ��λҪ�����Դ�����±� 
    int num = 1;
    // �ж����м��㷨��ǰ�������Ƿ���� 
    for(int i = 1;i <= N;++i){
        // �ж������Ƿ�������������������
        if(Request[i] > p->Need[i]){ 
            printf("%c�����������Դ��������Ҫ����Դ\n",p->name);
            printf("���䲻����������䣡\n");
            return false;
        }else{
            // �ж������Ƿ���ڵ�ǰ�ɷ�����Դ�������������
            if(Request[i] > Available[i]){                         
                printf("%c�����������Դ����ϵͳ�ֿ����õ���Դ\n",p->name);
                printf("ϵͳ�����㹻��Դ���������!\n");
                return false;
            }
        }
    }
    // ǰ���������������Է�����Դ��Ѱ�Ұ�ȫ���� 
    // ���ݽ���������,�Է�����Դ
    test(list); 
    // �ж�ϵͳ�Ƿ�ȫ 
    if(!safe(list)){
        Retest(list);
        return false;
    }
    return true;
}
// ��ȫ���㷨
bool safe(PCB *list){
    // ͳ��δ��ɽ����� 
    int m = 0;
    PCB *move = list->next;
    while(move != NULL && move->state != process_type_finish){
        move = move->next;
        ++m;
    }
    // ��ʼ��Work���� 
    for(int i = 1;i <= N;i++){
        Work[i] = Available[i];
    }
    // ��ʼ��Finish���� 
    for(int i = 1;i <= M;i++){
        if(i <= m){
            Finish[i] = false;
        }else{
            Finish[i] = true;
        }
    } 
    // �ڵ�λ�ã��жϽ������� 
    int pnum = 1,apply;
    int num = 1;
    // ��ȫ���� 
    PCB *p = list->next; 
    while(p != NULL && pnum <= m){
        apply = 0;
        for(int i = 1;i <= N;i++){
            // ��ǰ����δ��ɲ��Ҹ�����ԴС�ڻ����ϵͳ��Դ�� 
            if(Finish[pnum] == false && p->Need[i] <= Work[i]){   
                apply++;
                // ֱ��ÿ����Դ��������С��ϵͳ��������Դ���ſɷ���
                if(apply == N){  
                    for(int x = 1;x <= N;x++){
                        // ���µ�ǰϵͳ�ɷ�����Դ
                        Work[x] += p->Allocate[x];
                    } 
                    // ���±������ 
                    Finish[pnum] = true;
                    // ���°�ȫ�������� 
                    Security[num++] = p->name;
                    // ��֤ÿ�β�ѯ���ӵ�һ�����̿�ʼ    
                    pnum = 0; 
                    p = list; 
                }
            }
        }
        // ��ѯ��һ���� 
        pnum++; 
        p = p->next;
    }
    for(int i = 1;i <= M;i++){
        if(Finish[i] == false){
            // ϵͳ���ڲ���ȫ״̬ 
            printf("ϵͳ����ȫ��\n");
            return false;
        }
    }
    // �����ȫ�������ȫ���� 
    printf("ϵͳ�ǰ�ȫ�ģ�\n");
    printf("����һ����ȫ����:");
    for(int i = 1;i <= m;i++){
        // �����������˳������
        printf(" %c ",Security[i]);
        if(i < m){
            printf("->");
        } 
    }
    printf("\n");
    return true;
}
// ʱ��Ƭ��ת�����㷨 
void round_robin(PCB *list){
    // ��¼��һ������λ��
    PCB *index = list->next;
    while (index != NULL && index->state != process_type_finish) {
        // �жϵ��Ⱥ��Ƿ���� 
        flag = true; 
        // ϵͳ��ȫ�����̷��䵽��Դ������ 
        if(bank(list)){
            // ����������ʱ��
            index->run_time += TIME_SLICE;
            // �жϸý����Ƿ���� 
            int num = 0;
            for(int i = 1;i <= N;++i){
                if(index->Max[i] == index->Allocate[i]){
                    num++;
                }   
            }
            // �ý�������� 
            if (num == N) {
                // �޸Ľ���״̬
                index->state = process_type_finish;
                // ���շ������Դ
                for(int i = 1;i <= N;i++){
                    Available[i] += index->Allocate[i];
                }
                printf("%c�������\n",index->name);
            }else{
                // ����δ��ɣ�����ȴ� 
                index->state = process_type_wait;
            }
            // ��ǰ��������� 
            if (index->state == process_type_finish){
                // ������ɽ��̵���������ɶ���ĩβ 
                // 1.ͷָ��ָ����Ԫ������һ�����
                list->next = index->next;
                // 2.������������������뵽����ɶ��е���β��
                PCB *p = list;
                while (p->next != NULL) {
                    p = p->next;
                }
                p->next = index;
                index->next = NULL;
            } else {
                // ��ǰ����δ��� 
                // 1.ͷָ��ָ����Ԫ������һ�����
                list->next = index->next;
                // 2.������������������뵽�ȴ����е���β��(���������ɶ���)
                PCB *p = list;
                // 2.1Ѱ�Ҳ���λ��
                while (p->next != NULL && p->next->state != process_type_finish) {
                    p = p->next;
                }
                // 2.2�жϲ���λ��
                if (p->next == NULL) {
                    // ���һ��
                    p->next = index;
                    p->next->next = NULL;
                }else{
                    // �������һ����������н��
                    index->next = p->next;
                    p->next = index;
                }
            }   
        }else{
            // �ý���������Դ����ᵼ��ϵͳ����ȫ��������Դ������ 
            // ���ý����������������ȴ����к�����ɶ����м䣬�����������е����һ�� 
            index->state = process_type_block;
            // ��ǰ����δ��ɲ���������״̬ 
            // 1.ͷָ��ָ����Ԫ������һ�����
            list->next = index->next;
            // 2.������������������뵽δ��ɶ��к��������е����һ��
            PCB *p = list;
            // 2.1Ѱ�Ҳ���λ��
            while (p->next != NULL && p->next->state != process_type_finish) {
                p = p->next;
            }
            // 2.2�жϲ���λ��
            if (p->next == NULL) {
                // ���һ��
                p->next = index;
                p->next->next = NULL;
            }else{
                // �������һ����������н��
                index->next = p->next;
                p->next = index;
            }
        }
        // չʾ��ǰ����״��
        if(list->next->state != process_type_finish){
            list->next->state = process_type_run;           
        }
        if(flag){
            print(list);            
            printf("\n***********************************************************************\n");  
        }
        index = list->next;
    }
}
