import java.util.Scanner;
import java.util.Vector;

/*
定义AdultCat类，用来表示成年猫咪。
定义YoungCat，用来表示小猫咪。
定义OldCat，用来表示老猫咪。
 */
abstract class Cat {
    String name;

    Cat(String name) {
        this.name = name;
    }

    abstract void move();

    abstract void sound();

    abstract void show();
}

class OldCat extends Cat {
    OldCat(String name) {
        super(name);
    }

    @Override
    void show() {
        System.out.println("I am " + name + ",I am a old cat!");
    }

    @Override
    void move() {
        System.out.println("I move slowly.");
    }

    @Override
    void sound() {
        System.out.println("miem miem!");
    }
}

class AdultCat extends Cat {
    AdultCat(String name) {
        super(name);
    }

    @Override
    void show() {
        System.out.println("I am " + name + ",I am a cat!");
    }

    @Override
    void move() {
        System.out.println("I can move quickly.");
    }

    @Override
    void sound() {
        System.out.println("mie mie!");
    }
}

class YoungCat extends Cat {
    YoungCat(String name) {
        super(name);
    }

    @Override
    void show() {
        System.out.println("I am " + name + ",I am a young cat!");
    }

    @Override
    void move() {
        System.out.println("I like jumping.");
    }

    @Override
    void sound() {
        System.out.println("mie mie!");
    }
}

public class Main {
    public static void main(String[] args) {
        Cat[] catfamily = new Cat[3];

        catfamily[0] = new OldCat("HuangLao");
        catfamily[1] = new AdultCat("LaoMei");
        catfamily[2] = new YoungCat("XiaoLi");

        for (int i = 0; i < 3; i++) {
            catfamily[i].show();
            catfamily[i].move();
            catfamily[i].sound();

            System.out.println();
        }
    }
}

