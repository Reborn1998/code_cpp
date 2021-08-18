#include<cstdio>
#include<algorithm>
#include<iostream>
using namespace std;

//����վ�ṹ�壬��¼�ͼۺ͵����ľ���
struct Station {
    double gasPrice, disTo;
} s[505];
//������վ����
bool cmp(Station a, Station b) {
    return (a.disTo != b.disTo) ? a.disTo < b.disTo : a.gasPrice < b.gasPrice;
}

int main() {
    //��Ŀδ�ᵽ�ʿ���Ϊ������
    double cmax, d, davg;
    int n;
    scanf("%lf %lf %lf %d", &cmax, &d, &davg, &n);
    for(int i = 0; i < n; i++)
        scanf("%lf %lf", &s[i].gasPrice, &s[i].disTo);
    sort(s, s + n, cmp);
    //���յ㿴�����һ������վ
    s[n].gasPrice = 0.0;//�ͼ�Ϊ0�����ȼ����
    s[n].disTo = d;//�����ľ��뼴�ܾ���
    //���û�м���վ��������޷�����
    if(s[0].disTo != 0)
    {
        printf("The maximum travel distance = 0.00");
        return 0;
    }
    //���Գ���
    int cur = 0;//��ǰ��������0�ż���վ
    double full = cmax * davg;//��������ʻ�ľ���
    double cost = 0.0;//�ܻ���
    double capacity = 0.0, need;//��ǰ��������Ҫ������
    //ѭ���ҳ���һ������վ
    while(cur < n)
    {//ֻҪû���յ�n��ѭ��
        int k = 0;//��¼��һ����ȥ�ļ���վ
        double minPrice = 0x7fffffff;//��¼���ҵ�������ͼ�
        for(int i = cur + 1; i <= n && s[i].disTo <= s[cur].disTo + full; i++)
        {//�ӵ�ǰ����վ����һ����ʼ����һ����ȥ�ļ���վ����������ȥ��
            if(s[i].gasPrice < minPrice)
            {//�ҵ�������ͼ۵ģ�����
                k = i;
                minPrice = s[i].gasPrice;
                //����������ͼۣ������ڵ�ǰ����վ���ͼۣ�������ѡ
                if(s[i].gasPrice < s[cur].gasPrice)    break;
            }
        }
        //�ҵ�����һ����ȥ�ļ���վ
        if(k != 0)
        {
            need = (s[k].disTo - s[cur].disTo) / davg;
            if(minPrice < s[cur].gasPrice)
            {//����ͼ۱ȵ�ǰ����վ���ͣ����ȥ���
                if(capacity < need)//�����Ҫ���ͣ���ӵ�ǡ����ȥ
                {
                    cost += (need - capacity) * s[cur].gasPrice;
                    capacity = need;
                }
                capacity -= need;//�����ʣ������
            }
            else
            {//�ͼ۲��ȵ�ǰ����վ�ͣ����ڵ�ǰ����վ����
                cost += (cmax - capacity) * s[cur].gasPrice;
                capacity = cmax - need;//�����ʣ������
            }
            cur = k;//���µ�ǰ����վ��
            cout<<k<<endl;
        }
        //�Ҳ�����һ����ȥ�ļ���վ
        else    break;
    }
    //û�����յ㣬������Ϊ��ǰ����վ�����ľ����ټ��ϼ����ͻ�����ʻ�ľ���
    if(cur < n)    printf("The maximum travel distance = %.2f", s[cur].disTo + full);
    else           printf("%.2f", cost);
    return 0;
}
