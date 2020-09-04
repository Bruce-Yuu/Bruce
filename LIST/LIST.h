#define TRUE 0
#define FALSE 1
#define SUCCESS 0
#define FAIL 1

/*
***定义双链表节点类型
*/
struct Node
{
    int Data;
    struct Node *Prior;
    struct Node *Next;
};

typedef struct Node *LIST;

/*
***作者：Bruce Yuu
***功能：创建一个只带头节点的空双链表
***参数说明：
***返回值：成功返回SUCCESS,失败返回FAIL
***日期：2020/9/3
*/
external int Create_List(LIST L);

/*
***作者：Bruce Yuu
***功能：判断一个双链表是否为空表，如果只有一个头节点则为空
***参数说明：
***返回值：如果为空返回TRUE，不为空返回FALSE
***日期：2020/9/3
*/
external int Is_Empty_List(LIST static L);

/*
***作者：Bruce Yuu
***功能：清空双链表，只保留头节点
***参数说明：
***返回值：成功返回SUCCESS，失败返回FAIL
***日期：2020/9/3
*/
external int Clean_List(LIST L);

/*
***作者：Bruce Yuu
***功能：在双链表指定位置之后插入一个元素
***参数说明：Pos为指定位置，Element为待插入元素的值
***返回值：成功返回SUCCESS，失败返回FAIL
***日期：2020/9/3
*/
external int Add_Element(LIST L， int Pos, int Element);

/*
***作者：Bruce Yuu
***功能：删除双链表中指定位置的元素
***参数说明：Pos为指定位置
***返回值：成功返回SUCCESS，失败返回FAIL
***日期：2020/9/3
*/
external int Delete_Element(LIST L, int Pos);

/*
***作者：Bruce Yuu
***功能：查找双链表中指定元素，返回指定元素在双链表中的位置
***参数说明：Element为待查找的元素，Pos为该元素的位置
***返回值：成功返回SUCCESS，失败返回FAIL
***日期：2020/9/3
*/
external int Find(LIST L, int Element, int *Pos);

/*
***作者：Bruce Yuu
***功能：查找双链表中指定元素的前驱元素，返回所查元素在双链表中的位置
***参数说明：Element为指定的元素，Pos为待查找元素的位置
***返回值：成功返回SUCCESS，失败返回FAIL
***日期：2020/9/3
*/
external int Find_Prior_Element(LIST L, int Element, int *Pos);

/*
***作者：Bruce Yuu
***功能：查找双链表中指定元素的后继元素，返回所查元素在双链表中的位置
***参数说明：Element为指定的元素，Pos为待查找元素的位置
***返回值：成功返回SUCCESS，失败返回FAIL
***日期：2020/9/3
*/
external int Find_Next_Element(LIST L, int Element, int *Pos);

/*
***作者：Bruce Yuu
***功能：判断某一元素是否为双链表最后一个元素
***参数说明：Element为待判断元素
***返回值：若是返回TRUE，否则返回FALSE
***日期：2020/9/3
*/
external int Is_Last_Element(LIST L, int Element);