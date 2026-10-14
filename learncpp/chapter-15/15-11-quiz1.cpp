// ============================================================
// 来源小节：15.x Chapter 15 summary and quiz（官方编号 15.x，文件编号 15-11）
// 示例说明：本章综合测验"随机怪物生成器"的完整解答。综合运用了：
//           - 嵌套类型：把 enum Type 放在 Monster 类内（public）
//           - 构造函数与成员初始化列表
//           - constexpr 成员函数 getTypeString() 与 print()
//           - MonsterGenerator 命名空间中的 getName()/getRoar()/generate()
//           - 随机化：用类似 8.15 的 Random 工具随机选类型/名字/吼声/血量
// 原文链接：https://www.learncpp.com/cpp-tutorial/chapter-15-summary-and-quiz/
// 预期输出（随机，示例形态）：
//   Mort the zombie has 61 hit points and says *growl*.
//   （每次运行不同；血量范围 1..100）
// 备注：本节代码为按原文描述重建。原文使用 8.15 的 Random.h；此处为了
//        自包含，把该工具内联在文件顶部（与 15.7 小测验中的 Random 类一致）。
// ============================================================
#include <chrono>
#include <iostream>
#include <random>
#include <string>
#include <string_view>

// ---------- 内联自 8.15 的随机数工具（等价于 Random.h） ----------
class Random
{
private:
	static std::mt19937 generate()
	{
		std::random_device rd{};

		std::seed_seq ss {
			static_cast<std::seed_seq::result_type>(std::chrono::steady_clock::now().time_since_epoch().count()),
			rd(), rd(), rd(), rd(), rd(), rd(), rd()
		};

		return std::mt19937{ ss };
	}

	static inline std::mt19937 mt{ generate() };

public:
	static int get(int min, int max)
	{
		return std::uniform_int_distribution{ min, max }(mt);
	}
};
// ----------------------------------------------------------------

class Monster
{
public:
	enum Type
	{
		dragon,
		goblin,
		ogre,
		orc,
		skeleton,
		troll,
		vampire,
		zombie,

		maxMonsterTypes,
	};

private:
	Type m_type{};
	std::string m_name{ "???" };
	std::string m_roar{ "???" };
	int m_hitPoints{};

public:
	Monster(Type type, std::string_view name, std::string_view roar, int hitPoints)
		: m_type{ type }, m_name{ name }, m_roar{ roar }, m_hitPoints{ hitPoints }
	{
	}

	constexpr std::string_view getTypeString() const
	{
		switch (m_type)
		{
		case dragon:   return "dragon";
		case goblin:   return "goblin";
		case ogre:     return "ogre";
		case orc:      return "orc";
		case skeleton: return "skeleton";
		case troll:    return "troll";
		case vampire:  return "vampire";
		case zombie:   return "zombie";
		default:       return "???";
		}
	}

	void print() const
	{
		if (m_hitPoints <= 0)
			std::cout << m_name << " the " << getTypeString() << " is dead.\n";
		else
			std::cout << m_name << " the " << getTypeString() << " has " << m_hitPoints
			          << " hit points and says " << m_roar << ".\n";
	}
};

namespace MonsterGenerator
{
	std::string_view getName(int n)
	{
		switch (n)
		{
		case 0:  return "Blarg";
		case 1:  return "Moog";
		case 2:  return "Pksh";
		case 3:  return "Tyrn";
		case 4:  return "Mort";
		case 5:  return "Hans";
		default: return "???";
		}
	}

	std::string_view getRoar(int n)
	{
		switch (n)
		{
		case 0:  return "*ROAR*";
		case 1:  return "*peep*";
		case 2:  return "*squeal*";
		case 3:  return "*whine*";
		case 4:  return "*growl*";
		case 5:  return "*burp*";
		default: return "???";
		}
	}

	Monster generate()
	{
		return Monster{
			static_cast<Monster::Type>(Random::get(0, Monster::maxMonsterTypes - 1)), // 随机类型
			getName(Random::get(0, 5)),   // 随机名字
			getRoar(Random::get(0, 5)),   // 随机吼声
			Random::get(1, 100)           // 随机血量 1..100
		};
	}
};

int main()
{
	Monster m{ MonsterGenerator::generate() };
	m.print();

	return 0;
}
