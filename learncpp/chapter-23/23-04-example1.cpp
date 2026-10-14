// ============================================================
// 来源小节：23.4 Association
// 示例说明：双向 Doctor/Patient 关联。前向声明 Patient 以打破循环依赖；
//           双方各持 std::vector<std::reference_wrapper<...>>。
//           注意：由于是双向关联，Doctor::addPatient 需要在 Patient
//           定义为友元后于类外定义。
// 原文链接：https://www.learncpp.com/cpp-tutorial/association/
// 预期输出：
//   James is seeing patients: Dave
//   Scott is seeing patients: Dave Betsy
//   Dave is seeing doctors: James Scott
//   Frank has no doctors right now
//   Betsy is seeing doctors: Scott
// 备注：本节代码为按原文描述重建（原 Example 1）。
// ============================================================
#include <functional> // std::reference_wrapper
#include <iostream>
#include <string>
#include <string_view>
#include <vector>

class Patient;

class Doctor
{
private:
    std::string m_name{};
    std::vector<std::reference_wrapper<const Patient>> m_patients{};

public:
    Doctor(std::string_view name)
        : m_name{ name }
    {
    }

    void addPatient(Patient& patient);

    friend std::ostream& operator<<(std::ostream& out, const Doctor& doctor);

    const std::string& getName() const { return m_name; }
};

class Patient
{
private:
    std::string m_name{};
    std::vector<std::reference_wrapper<const Doctor>> m_doctors{};

    // We can't use addDoctor publicly, because we don't want someone
    // to add a patient to a doctor without the doctor knowing about it too.
    // The Doctor::addPatient will be a friend of this function.
    void addDoctor(const Doctor& doctor)
    {
        m_doctors.push_back(doctor);
    }

public:
    Patient(std::string_view name)
        : m_name{ name }
    {
    }

    friend std::ostream& operator<<(std::ostream& out, const Patient& patient);

    const std::string& getName() const { return m_name; }

    // We're making this function a friend, so the private addDoctor function can be called
    friend void Doctor::addPatient(Patient& patient);
};

void Doctor::addPatient(Patient& patient)
{
    // Our doctor will add this patient
    m_patients.push_back(patient);

    // and the patient will also add this doctor
    patient.addDoctor(*this);
}

std::ostream& operator<<(std::ostream& out, const Doctor& doctor)
{
    if (doctor.m_patients.empty())
    {
        out << doctor.m_name << " has no patients right now";
        return out;
    }

    out << doctor.m_name << " is seeing patients: ";
    for (const auto& patient : doctor.m_patients)
        out << patient.get().getName() << ' ';

    return out;
}

std::ostream& operator<<(std::ostream& out, const Patient& patient)
{
    if (patient.m_doctors.empty())
    {
        out << patient.getName() << " has no doctors right now";
        return out;
    }

    out << patient.m_name << " is seeing doctors: ";
    for (const auto& doctor : patient.m_doctors)
        out << doctor.get().getName() << ' ';

    return out;
}

int main()
{
    // Create a Patient outside the scope of the Doctor
    Patient dave{ "Dave" };
    Patient frank{ "Frank" };
    Patient betsy{ "Betsy" };

    Doctor james{ "James" };
    Doctor scott{ "Scott" };

    james.addPatient(dave);

    scott.addPatient(dave);
    scott.addPatient(betsy);

    std::cout << james << '\n';
    std::cout << scott << '\n';
    std::cout << dave << '\n';
    std::cout << frank << '\n';
    std::cout << betsy << '\n';

    return 0;
}
