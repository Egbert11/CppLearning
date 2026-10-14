# 11.6 Function templates

> 原文：https://www.learncpp.com/cpp-tutorial/function-templates/

## 核心概念

- **固定形参类型限制了函数**：`max(int, int)` 只能用于整数（或可提升为 `int` 的类型），调用者无法传入其他类型（如 `double`）。
- **重载作为变通做法**：可以再加一个 `double` 版本的 `max`，但它的函数体与 `int` 版完全相同——而这个体对许多类型（`int`、`double`、`long`、`long double` 以及用户自定义类型）都适用。
- **重复重载的代价**：为每个想要的类型写几乎相同的重载，是维护噩梦、易出错的配方，也违反 DRY 原则；进一步的问题是原作者不可能预见到用户想要的全部类型。
- **真正缺少的东西**：一种只写一个 `max`、却能用于任意类型（包括编写时未知的类型）实参的方式。
- **模板的定义**：与普通定义一样描述函数或类的样子，但可以使用一个或多个**占位类型**（placeholder types），代表稍后才会提供的类型。
- **编译器生成的多个重载**：从一个模板，编译器可按需生成任意多个重载函数或类，每个使用不同的实际类型；你只需维护这个模板。
- **模板类比（aside）**：模板被比作镂空模板（stencil）：制作一次、反复使用，至于用哪种"颜色"（实际类型）只在使用时才选。文中还引用了词典式定义："模板是一种模型，用作创建相似对象的样板"。
- **灵活性与面向未来**：由于实际类型在使用时才决定，模板代码可以用于编写模板时尚不存在的类型（这对标准库很重要）。
- **术语**：**函数模板（function template）**是用于按各组实际类型生成重载函数的、类函数定义；原件称为**主模板（primary template）**，生成出的函数称为**实例化函数（instantiated functions）**。
- **占位类型**：正式名称为**类型模板参数（type template parameters）**，非正式称**模板类型（template types）**；它们出现在形参类型、返回类型或函数体中需要使用、但稍后才会指定的类型位置。
- **模板参数的三类（进阶）**：类型模板参数（代表一个类型）、非类型模板参数（代表一个 `constexpr` 值）、模板模板参数（代表一个模板）；其中类型模板参数最常见。
- **把 `max()` 模板化的步骤**：先把实际类型（`int`，共出现三次）替换为类型模板参数（`T`）；再加上**模板参数声明**（如 `template <typename T>`），告诉编译器这是模板、`T` 是任意类型的占位符。
- **作用域规则**：模板参数声明的作用域严格限于紧随其后的那个模板，因此每个函数模板或类模板都需要各自的声明。
- **语法规则**：关键字 `template` 在前，参数放在尖括号 `<>` 内，每个类型参数写作 `typename`（推荐）或 `class`，后跟参数名。
- **`typename` 与 `class`**：此处没有区别；`class` 更老且常见，但 `typename` 更能表达"可以代入任何类型，包括基本类型"。
- **命名约定**：对简单或显然的用途，习惯用单个以 `T` 开头的大写字母；对用途不明显或带特定要求的参数，用描述性的大写名（如 `Allocator`）或以 `T` 前缀的名字（如 `TAllocator`）。标准库使用大写形式。
- **隐式要求**：实例化模板时编译器会替换模板实参并编译结果；能否编译取决于该类型的对象如何使用，所以形参的要求本质上是隐式定义的。要了解显式要求（如 `Compare` 的要求），需查阅技术文档（例如 cppreference 对 `std::max` 的说明）。

## 最佳实践

- **Best practice**："Use a single capital letter starting with `T` (e.g. `T`, `U`, `V`, etc…) to name type template parameters that are used in trivial or obvious ways and represent "any reasonable type"."

- **Best practice**："If the type template parameter has a non-obvious usage or specific requirements that must be met, then a more descriptive name is warranted (e.g. `Allocator` or `TAllocator`)."

- **Key insight**："The compiler can use a single template to generate a family of related functions or classes, each using a different set of actual types."（编译器可用单个模板生成一族相关的函数或类，每个使用不同的实际类型集合。）
- **Key insight**：模板可用于编写模板时尚不存在的类型，因而灵活且面向未来。

本节无 Warning / Author's note 条目。

## 代码示例

- [11-06-example1.cpp](11-06-example1.cpp)：只处理 `int` 的 `max`——演示固定形参类型的限制（对应原文 Example 1）。
- [11-06-example2.cpp](11-06-example2.cpp)：再加一个函数体完全相同的 `double` 版 `max` 重载（对应原文 Example 2）。
- [11-06-example3-error.cpp](11-06-example3-error.cpp)：把 `int` 换成 `T` 但未写模板参数声明——**预期编译失败**（对应原文 Example 3）。
- [11-06-example4.cpp](11-06-example4.cpp)：完整的函数模板 `max<T>`，用 `int` 与 `double` 实参分别实例化（对应原文 Example 4/5）。
- [11-06-example5.cpp](11-06-example5.cpp)：进阶——使用标准库 `std::max` 的三参数（带 `Compare`）版本（对应原文 Example 6）。

> 说明：本节代码为按原文清单与站点标准写法**忠实重建**；抓取工具无法逐字返回完整代码块。
> 原文 Example 3 为"不写模板参数声明"的反例，已单独生成为 `-error` 文件。

## 测验

原文 Quiz #1 为简答题（无代码）：建造蓝图为什么被称为一种模板？

参考答案：一份蓝图描述了如何建造某个结构，使施工队能据此建起许多栋结构相同的建筑，而所用材料的具体细节在建造时才选定——这与模板"制作一次、按实际类型反复生成具体事物"的思想一致。
