import java.util.Scanner;
import java.util.Vector;

class Person {
    String name;
    int age;

    Person(String name, int age) {
        this.name = name;
        this.age = age;
    }
}

class Employee extends Person {
    //Field：empId(String), department(String), level(int)。
    String empId;
    String department;
    int level;

    Employee(String name, int age, String empId, String department, int level) {
        super(name, age);
        this.empId = empId;
        this.department = department;
        this.level = level;
    }

    void print() {
        System.out.printf("I am a Employee\n" +
                "My name is %s,I am %d years old.\n" +
                "I am a %d level Employee.My employeeNumber is %s.I am working in %s\n", name, age, level, empId, department
        );
    }
}

class Manager extends Employee {
    Manager(String name, int age, String empId, String department, int level) {
        super(name, age, empId, department, level);
    }

    @Override
    void print() {
        System.out.printf("I am a Manager\n" +
                "My name is %s,I am %d years old.\n" +
                "I am a %d level Employee.My employeeNumber is %s.I am working in %s\nMy subordinate has:\n", name, age, level, empId, department
        );
        for (var i = 0; i < subordinate.size() - 1; i += 1) {
            System.out.printf("%s,", subordinate.get(i).name);
        }
        System.out.printf("%s.\n", subordinate.lastElement().name);
    }

    private Vector<Employee> subordinate = new Vector<Employee>();

    Vector<Employee> getSubordinates() {
        return subordinate;
    }

}

public class Main {
    public static void main(String[] args) {
        Employee e1 = new Employee("zhangsan", 20, "s101", "d01", 3);
        e1.print();
        System.out.println();

        Employee e2 = new Employee("lisi", 20, "s202", "d02", 4);
        e2.print();
        System.out.println();

        e2 = new Employee("maliu", 20, "s102", "d01", 5);

        Manager m1 = new Manager("wangwu", 30, "s100", "d01", 9);

        m1.getSubordinates().addElement(e1);
        m1.getSubordinates().addElement(e2);
        m1.print();
        System.out.println();
    }
}
