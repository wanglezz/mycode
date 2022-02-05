#include<bits/stdc++.h>
using namespace std;
const int datanum = 150;
const int testdata = 0.2*datanum;
const int traindata = 0.8*datanum;
const int in = 4;
const int out = 1;
const int Neuron = 40;
const int traintime = 50000;
const double WAlta = 0.1;
const double VAlta = 0.2;
double v[Neuron][in];
double w[out][Neuron];
double dv[Neuron][in],dw[out][Neuron];//权重v,w的修正值
double irisin[datanum][in];
double irisout[datanum][out];//总数据集
double train[traindata][in];//训练集输入
double trainout[traindata][out];//训练集输出
double testin[testdata][in];//测试集输入
double testout[testdata][out];//测试集实际输出
double Maxin[in],Minin[in];
double Maxout[out],Minout[out];
double outputdata[out];//神经网络实际输出
double pre[testdata][out];//测试集预测输出
double y[Neuron];//存储到隐含层的输出
bool Inputs()
{
    char fname[256];
    char name[20];
    cout<<"请输入存放数据的文件：";
    scanf("%s",fname);
    FILE *fp = fopen(fname,"rb");
    if(fp==NULL)
    {
        cout<<"不能打开文件！"<<endl;
        return false;
    }
    for(int i=0;i<datanum;i++)
    {
        fscanf(fp,"%lf,%lf,%lf,%lf,%s",&irisin[i][0],&irisin[i][1],&irisin[i][2],&irisin[i][3],name);
        if(!strcmp(name,"Iris-setosa"))irisout[i][0] = 0;
        else if(!strcmp(name,"Iris-versicolor"))irisout[i][0] = 1;
        else irisout[i][0] = 2;
    }
    fclose(fp);
    return true;
}
void disorder()
{
    srand(time(0));
    for(int i=0;i<datanum*100;i++)
    {
        int index1 = rand()%datanum;
        int index2 = rand()%datanum;
        for(int j=0;j<in;j++)
            swap(irisin[index1][j],irisin[index2][j]);
        for(int j=0;j<out;j++)
            swap(irisout[index1][j],irisout[index2][j]);
    }
}
void dispair()
{
    for(int i=0;i<traindata;i++)
    {
        for(int j=0;j<in;j++)
        {
            train[i][j] = irisin[i][j];
        }
        for(int j=0;j<out;j++)
        {
            trainout[i][j] = irisout[i][j];
        }
    }
    for(int i=0;i<testdata;i++)
    {
        for(int j=0;j<in;j++)
        {
            testin[i][j] = irisin[i+traindata][j];
        }
        for(int j=0;j<out;j++)
        {
            testout[i][j] = irisout[i+traindata][j];
        }
    }
}
void initbpnetwork()
{
    srand((int)time(0));
    for(int i=0;i<in;i++)
    {
        Maxin[i] = Minin[i] = train[0][i];
        for(int j=0;j<traindata;j++)
        {
            Maxin[i] = Maxin[i]>train[j][i]?Maxin[i]:train[j][i];
            Minin[i] = Minin[i]<train[j][i]?Minin[i]:train[j][i];
        }
    }
    Maxout[0] = 2;Minout[0] = 0;
    for(int i=0;i<in;i++)
    {
        for(int j=0;j<traindata;j++)
        {
            train[j][i] = (train[j][i]-Minin[i]) / (Maxin[i]-Minin[i]);
        }
    }
    for(int i=0;i<out;i++)
        for(int j=0;j<traindata;j++)
            trainout[j][i] = (trainout[j][i]-Minout[i]) / (Maxout[i]-Minout[i]);
    for(int i=0;i<Neuron;i++)
    {
        for(int j=0;j<in;j++)
        {
            v[i][j] = rand()*2.0/RAND_MAX - 1;
            dv[i][j] = 0;
        }
    }
    for(int i=0;i<out;i++)
    {
        for(int j=0;j<Neuron;j++)
        {
            w[i][j] = rand() * 2.0 / RAND_MAX - 1;
            dw[i][j] = 0;
        }
    }
}
void Comput(int var)
    {
        double sum;
        for(int i=0;i<Neuron;i++)
        {
            sum = 0;
            for(int j=0;j<in;j++)
            {
                sum += v[i][j] * train[var][j];
            }
            y[i] = 1 / (1 + exp(-1*sum));
        }
        for(int i=0;i<out;i++)
        {
            sum = 0;
            for(int j=0;j<Neuron;j++)
            {
                sum += w[i][j] * y[j];
            }
            outputdata[i] = 1 / (1 + exp(-1*sum));
        }
    };
void BackUpdate(int var)
    {
        double t;
        for(int i=0;i<Neuron;i++)
        {
            t = 0;
            for(int j=0;j<out;j++)
            {
                dw[j][i] = WAlta * (trainout[var][j]-outputdata[j])*outputdata[j]*(1-outputdata[j])*y[i];
                w[j][i] += dw[j][i];
                t += (trainout[var][j]-outputdata[j])*outputdata[j]*(1-outputdata[j])*w[j][i];
            }
            for(int j=0;j<in;j++)
            {
                dv[i][j] = VAlta*t*y[i]*(1-y[i])*train[var][j];
                v[i][j] += dv[i][j];
            }
        }
    };
void trainnetwork()
{
    int count = 1;
    do
    {
        for(int i=0;i<traindata;i++)
        {
            Comput(i);
            BackUpdate(i);
        }
        count++;
    }while(count<=traintime);
}
void testnetwork()
{
    double sum;
    for(int i=0;i<in;i++)
    {
        for(int j=0;j<testdata;j++)
        {
            testin[j][i] = (testin[j][i]-Minin[i]) / (Maxin[i]-Minin[i]);
        }
    }
    for(int k=0;k<testdata;k++)
    {
        for(int i=0;i<Neuron;i++)
        {
            sum = 0;
            for(int j=0;j<in;j++)
            {
                sum += v[i][j] * testin[k][j];
            }
            y[i] = 1 / (1 + exp(-1*sum));
        }
        sum = 0;
        for(int j=0;j<Neuron;j++)
        {
            sum += w[0][j] * y[j];
        }
        pre[k][0] = 1 / (1 + exp(-1*sum))*(Maxout[0] - Minout[0]) + Minout[0];
        cout<<"预测值："<<pre[k][0]<<"实际值："<<testout[k][0]<<endl;
    }
    double ans = 0;
    int time = 0;
    for(int i=0;i<testdata;i++)
    {
        if(fabs(testout[i][0]-pre[i][0])<0.5)time++;
    }
    ans = 1.0*time / testdata;
    cout<<ans<<endl;
}
int main ()
{
    Inputs();
    disorder();
    dispair();
    initbpnetwork();
    trainnetwork();
    testnetwork();
    return 0;
}