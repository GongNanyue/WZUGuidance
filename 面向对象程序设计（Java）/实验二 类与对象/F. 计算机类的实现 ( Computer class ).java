import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        COMPUTER computer = new COMPUTER();
        computer.run();
        computer.stop();
    }
}

class COMPUTER {
    private CPU cpu;

    private RAM ram;
    private CDROM cdrom;

    public COMPUTER() {

        cpu = new CPU();
        ram = new RAM();
        cdrom = new CDROM();
        System.out.println("Constructing a COMPUTER");
    }

    public void run() {
        System.out.println("COMPUTER is running");
        cpu.run();
        ram.run();
        cdrom.run();

    }

    public void stop() {
        cdrom.stop();
        ram.stop();
        cpu.stop();
        System.out.println("COMPUTER is stopping");
    }
}


class CPU {
    public CPU() {
        System.out.println("Constructing a CPU");
    }

    public void run() {
        System.out.println("CPU is running");
    }

    public void stop() {
        System.out.println("CPU is stopping");
    }
}


class RAM {
    public RAM() {
        System.out.println("Constructing a RAM");
    }

    public void run() {
        System.out.println("RAM is running");
    }

    public void stop() {
        System.out.println("RAM is stopping");
    }
}

class CDROM {
    public CDROM() {
        System.out.println("Constructing a CDROM");
    }

    public void run() {
        System.out.println("CDROM is running");
    }

    public void stop() {
        System.out.println("CDROM is stopping");
    }
}