// ============================================================
// 来源小节：19.1 Dynamic memory allocation with new and delete
// 示例说明：在编译期把容量定死的"祈祷够用"式分配，说明固定大小的四个问题之一。
// 原文链接：https://www.learncpp.com/cpp-tutorial/dynamic-memory-allocation-with-new-and-delete/
// 预期输出：482185 bytes reserved（各类型大小依实现而定，此处按 4/4/16 字节估算）
// 备注：本节代码为按原文描述重建——原文未给出 Record/Monster/Polygon 的定义，
//       这里补上最小占位定义以便编译；末尾的 sizeof 求和是原文没有的，
//       用于避免"未使用变量"警告。
// ============================================================
#include <iostream>

struct Record { int id{}; };        // 占位定义
struct Monster { int hp{}; };       // 占位定义
struct Polygon { double x{}; double y{}; }; // 占位定义

int main()
{
    char name[25]; // let's hope their name is less than 25 chars!
    Record record[500]; // let's hope there are less than 500 records!
    Monster monster[40]; // 40 monsters maximum
    Polygon rendering[30000]; // this 3d rendering better not have more than 30,000 polygons!

    // 原文只有上面几行声明；这里打印合计字节数，避免"未使用变量"警告。
    std::cout << (sizeof(name) + sizeof(record) + sizeof(monster) + sizeof(rendering)) << " bytes reserved\n";

    return 0;
}
