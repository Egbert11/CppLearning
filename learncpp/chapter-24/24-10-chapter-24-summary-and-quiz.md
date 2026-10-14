# 24.x Chapter 24 summary and quiz

> 原文：https://www.learncpp.com/cpp-tutorial/chapter-24-summary-and-quiz/
> 官方编号为 24.x（本章总结与测验），本仓库按顺延号记作 24.10。

## 本章知识速览

- **继承 / is-a 关系**：派生类与基类构成 "is-a（是一个）" 关系；被继承的类叫父类 / 基类 / 超类，继承的类叫子类 / 派生类 / 子类。
- **成员获取**：派生类获得基类的所有成员。
- **构造顺序**：先为整个对象预留内存，调用派生类构造函数；**基类部分最先构造**（未指定时用默认构造函数），然后执行派生类的成员初始化列表，再执行派生类函数体，最后返回。
- **析构顺序**：析构按相反顺序进行——"from most-derived to most-base class"（从最派生类到最基类）。
- **访问说明符**：C++ 有 public、private、protected 三种；protected 允许类自身、友元以及派生类访问，但 public 不行。
- **继承类型**：类可以 public、private、protected 地继承，但几乎总是用 public 继承。
- **访问 / 继承对照**：public 在三种继承下分别是 public / private / protected；protected 分别是 protected / private / protected；private 成员在 private 与 protected 继承下都变为不可访问。
- **派生类能做什么**：添加函数、改变基类行为、修改继承成员的访问级别，或隐藏功能。
- **多继承**：派生类可以继承多个父类，但一般最好避免——"除非替代方案会导致更大的复杂度"。

## 测验

1. 只用肉眼（不许编译）判断下列各程序的输出，或说明它为何无法编译：
   - 1a) `Base` / `Derived` 的构造、析构函数打印自己的名字，局部 `Derived d;`。输出：`Base()` / `Derived()` / `~Derived()` / `~Base()`。见 [24-10-quiz1a.cpp](24-10-quiz1a.cpp)。
   - 1b) 同上，再加一个局部 `Base b;`。提示：局部变量按定义的相反顺序销毁。输出：`Base()` / `Derived()` / `Base()` / `~Base()` / `~Derived()` / `~Base()`。见 [24-10-quiz1b.cpp](24-10-quiz1b.cpp)。
   - 1c) `Base` 有 private 成员 `m_x`，`Derived::print()` 读取 `m_x`。判定：**无法编译**，`Derived::print()` 不能访问私有成员 `m_x`。见 [24-10-quiz1c-error.cpp](24-10-quiz1c-error.cpp)。
   - 1d) 把 `m_x` 改为 protected 后。输出：`Base()` / `Derived()` / `Derived: 5` / `~Derived()` / `~Base()`。见 [24-10-quiz1d.cpp](24-10-quiz1d.cpp)。
   - 1e) 再加 `class D2 : public Derived`（自身没有 `print()`）。输出：`Base()` / `Derived()` / `D2()` / `Derived: 5` / `~D2()` / `~Derived()` / `~Base()`。见 [24-10-quiz1e.cpp](24-10-quiz1e.cpp)。

2a. 写一个 `Apple` 类和一个 `Banana` 类，让它们派生自共同的 `Fruit` 类。`Fruit` 含两个成员：名字与颜色。示例 `main` 构造 `Apple a{ "red" }` 与 `Banana b{}`，输出：
   ```
   My apple is red.
   My banana is yellow.
   ```

2b. 在上一个程序里新增一个继承自 `Apple` 的 `GrannySmith` 类（需要用到一个 protected 的 Apple 构造函数）。输出增加第三行：
   ```
   My granny smith apple is green.
   ```
   - 解答见 [24-10-quiz2.cpp](24-10-quiz2.cpp)。

3. **挑战题**：做一个打怪游戏——玩家不断击败怪物、收集金币，直到死亡或升到 20 级。
   - 3a) 实现 `Creature`：名字、符号字符、生命、每次攻击伤害、携带金币，以及 getter 和 `reduceHealth()` / `isDead()` / `addGold()`。测试 `Creature o{ "orc", 'o', 4, 2, 10 }` 加 5 金币、扣 1 生命，输出 `The orc has 3 health and is carrying 15 gold.`。
   - 3b) 实现 `Player : Creature`：1 级、符号 `@`、10 生命、1 伤害、0 金币；添加 `levelUp()`（等级与伤害各 +1）、getLevel()、`hasWon()`（20 级时为真）。输入名字 Alex 输出 `Welcome, Alex.` / `You have 10 health and are carrying 0 gold.`。
   - 3c) 定义 `Monster : Creature`，内部枚举 `Type`：`dragon`、`orc`、`slime`、`max_types`。
   - 3d) 给 Monster 构造函数，用静态查找表 `monsterData` 按类型取属性。创建一个 orc 输出 `A orc (o) was created.`。
   - 3e) 添加 `static Monster getRandomMonster()`，随机返回一个类型。
   - 3f) 实现游戏循环：每场遭遇一个随机怪物；玩家可选 Run 或 Fight；逃跑 50% 成功，逃跑失败则怪物白打一下；战斗时玩家先手，怪物若存活则还击；击杀怪物获得其金币并升级；死亡或达到 20 级结束游戏，并报告金币与等级。建议拆成 `main()`、`fightMonster()`、`attackMonster()`、`attackPlayer()` 四个函数。
   - 3g) 额外加分：加入 Health / Strength / Poison 三种、小 / 中 / 大三种尺寸的药水；每场打赢后有 30% 概率找到一瓶，玩家可喝下或任其消失；药水喝下前类型与尺寸未知。
   - 解答见 [24-10-quiz3.cpp](24-10-quiz3.cpp)。

> 说明：本节代码为按原文描述重建。原文未给出独立的 Best practice / Warning 框；含若干 **Hint**：局部变量按定义逆序销毁；游戏逻辑建议拆成四个函数；药水可用一个 `Potion` 类加随机工厂与 `Player::drinkPotion()` 实现。
