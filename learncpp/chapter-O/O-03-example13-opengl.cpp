// 来源小节：O.3 Bit manipulation with bitwise operators and bit masks
// 示例说明：OpenGL 风格地用位标志组合"要清除的缓冲区"传给 glClear。
// 原文链接：https://www.learncpp.com/cpp-tutorial/bit-manipulation-with-bitwise-operators-and-bit-masks/
//
// 依赖第三方库：需要 OpenGL 头文件 + 库（<GL/gl.h> 与 -lopengl32）。
//               编译命令：g++ -std=c++20 -Wall O-03-example13-opengl.cpp -lopengl32
//               不加 -lopengl32 会因找不到 glClear 而链接失败。
//               GL_DEPTH_BUFFER_BIT 等宏由 OpenGL 提供，其值形如：
//                 #define GL_DEPTH_BUFFER_BIT   0x00000100
//                 #define GL_STENCIL_BUFFER_BIT 0x00000400
//                 #define GL_COLOR_BUFFER_BIT   0x00004000
//
// 说明：本节代码为按原文描述重建（抓取工具无法逐字返回长代码块）。
#include <GL/gl.h> // OpenGL 头文件（本机 MinGW 提供；链接需 -lopengl32）

int main()
{
    // --- 原文示例片段 ---
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT); // clear the color and the depth buffer
    // --- 原文示例片段结束 ---

    return 0;
}
