// 来源小节：2.11 Header files
// 示例说明：头文件 add.h —— 把前置声明（函数原型）集中放在这里，供其他文件 #include。
//           原文此处为了简单起见省略了 header guard（2.12 会补上）。
// 原文链接：https://www.learncpp.com/cpp-tutorial/header-files/

// This is the content of the .h file, which is where the declarations go
int add(int x, int y); // function prototype for add.h -- don't forget the semicolon!
