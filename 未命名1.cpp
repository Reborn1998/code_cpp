#include<cstdio>
#include<algorithm>
#include<iostream>
using namespace std;

//加油站结构体，记录油价和到起点的距离
struct Station {
    double gasPrice, disTo;
} s[505];
//将加油站排序
bool cmp(Station a, Station b) {
    return (a.disTo != b.disTo) ? a.disTo < b.disTo : a.gasPrice < b.gasPrice;
}

int main() {
    //题目未提到故可能为浮点型
    double cmax, d, davg;
    int n;
    scanf("%lf %lf %lf %d", &cmax, &d, &davg, &n);
    for(int i = 0; i < n; i++)
        scanf("%lf %lf", &s[i].gasPrice, &s[i].disTo);
    sort(s, s + n, cmp);
    //将终点看作最后一个加油站
    s[n].gasPrice = 0.0;//油价为0，优先级最高
    s[n].disTo = d;//到起点的距离即总距离
    //起点没有加油站的情况，无法出发
    if(s[0].disTo != 0)
    {
        printf("The maximum travel distance = 0.00");
        return 0;
    }
    //可以出发
    int cur = 0;//当前处于起点的0号加油站
    double full = cmax * davg;//满油能行驶的距离
    double cost = 0.0;//总花费
    double capacity = 0.0, need;//当前油量、需要的油量
    //循环找出下一个加油站
    while(cur < n)
    {//只要没到终点n就循环
        int k = 0;//记录下一个该去的加油站
        double minPrice = 0x7fffffff;//记录能找到的最低油价
        for(int i = cur + 1; i <= n && s[i].disTo <= s[cur].disTo + full; i++)
        {//从当前加油站的下一个开始找下一个能去的加油站，即满油能去的
            if(s[i].gasPrice < minPrice)
            {//找到低于最低价的，更新
                k = i;
                minPrice = s[i].gasPrice;
                //不仅低于最低价，还低于当前加油站的油价，则不用再选
                if(s[i].gasPrice < s[cur].gasPrice)    break;
            }
        }
        //找到了下一个能去的加油站
        if(k != 0)
        {
            need = (s[k].disTo - s[cur].disTo) / davg;
            if(minPrice < s[cur].gasPrice)
            {//如果油价比当前加油站还低，则就去这个
                if(capacity < need)//如果需要加油，则加到恰好能去
                {
                    cost += (need - capacity) * s[cur].gasPrice;
                    capacity = need;
                }
                capacity -= need;//到达后剩余油量
            }
            else
            {//油价不比当前加油站低，则在当前加油站加满
                cost += (cmax - capacity) * s[cur].gasPrice;
                capacity = cmax - need;//到达后剩余油量
            }
            cur = k;//更新当前加油站号
            cout<<k<<endl;
        }
        //找不到下一个能去的加油站
        else    break;
    }
    //没到达终点，最大距离为当前加油站到起点的距离再加上加满油还能行驶的距离
    if(cur < n)    printf("The maximum travel distance = %.2f", s[cur].disTo + full);
    else           printf("%.2f", cost);
    return 0;
}
