class Cpu {
    int rank;
    int frequency;
    float voltage;

    public Cpu(int rank, int frequency, float voltage) {
        this.rank = rank;
        this.frequency = frequency;
        this.voltage = voltage;
        System.out.println("Constructing a CPU");
    }

    public void run() {
        System.out.println("CPU is running");
    }

    public void stop() {
        System.out.println("CPU is stopping");
    }
}