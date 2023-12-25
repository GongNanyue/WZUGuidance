class Cpu {

    Cpu(int rank,int frequency,double voltage){

        this.rank = rank;

        this.frequency = frequency;

        this.voltage = voltage;

        System.out.println("Constructing a CPU");

    }



    void run(){

        System.out.println("CPU is running");

    }



    void stop(){

        System.out.println("CPU is stopping");

    }



    int rank;

    int frequency;

    double voltage;

}
