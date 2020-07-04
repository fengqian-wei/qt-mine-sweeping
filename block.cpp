#include "block.h"

//说明：

block::block(int row ,int col,int boomNum )
{
    //动态创建二维数组，用于保存块信息
    p = new int *[row];
    for(int i = 0;i<row;i++)
        p[i] = new int [col];
    //初始化数组，全部赋值为零
    for(int i =0;i<row;i++)
        for(int j = 0;j<col;j++)
            p[i][j] = 0;
    //产生随机数炸弹，将对应块赋值为99
    srand((unsigned)time(0));
    for(int i =1;i<=boomNum;i++)
    {
         int num = rand()%(row*col)-1;
         int rowBlock = num / col;
         int colBlock = num % col;
         if( p[rowBlock][colBlock] == 99)
         {
          i--;
          continue;
         }
         else
         p[rowBlock][colBlock] = 99;

    }
    //为除炸弹块外赋值，表明周围八位的炸弹数
    for(int i =0;i<row;i++)
        for(int j = 0;j<col;j++)
        {
            if(p[i][j]!=99)
            {
            char blockBoomNum = 0;
            for(int blockRow = i -1;blockRow<=i +1 ;blockRow++)
            {
                for(int blockCol = j -1;blockCol<=j + 1;blockCol++)
                {
                    //处理特殊情况，比如第一排、第一列等
                    if(blockRow<0||blockCol<0||blockRow>=row||blockCol>=col)
                    continue;
                    //开始检测周围雷数
                    if(p[blockRow][blockCol]==99)
                      blockBoomNum ++;
                }
            }
            p[i][j]=blockBoomNum;
            }

        }
    //初始化完成
    //初始化私有成员
    this->row = row;
    this->col = col;
    this->boomNum = boomNum;
    this->timeNum = 0;
    this->redFlagNum = boomNum;
}

block::~block()
{
   for(int i =0;i<row;i++)
   {
    delete[]  p[i];
   }
   delete [] p;
}
int block::getcol()
{
    return this->col;
}
int block::getrow()
{
    return this->row;
}
int block::getboomNum()
{
    return boomNum;
}
int block::gettimeNum()
{
    return timeNum;
}
int block::getredFlagNum()
{
    return redFlagNum;
}
void block::minusredFlagNum()
{
    redFlagNum = redFlagNum -1;
}
void block::addtimeNum()
{
    timeNum = timeNum + 1;
}
void block::addredFlagNum()
{
     redFlagNum = redFlagNum + 1;
}
