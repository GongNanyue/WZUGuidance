package Entity;

public class User {
    /**
     * 这个类是用于封装读者个人的信息，对应了数据库中的表tb_reader
     * 解释：
     * 			类中的属性:       	   tb_reader表的字段:
     * 			readerId  		->     reader_id
     * 			raderName 		->     reader_name
     * 			readerSex 		->     reader_sex
     * 			readerPassword  ->     reader_password
     * 		    Capacity         ->     reader_Capacity
     */
    public int readerId;
    public String readerName;
    public String readerPassword;
    public int readerSex;
    public int readerType;
    public int Capacity;

    public User() {
    }

    public User(int readerId, String readerName, String readerPassword, int readerSex, int readerType, int capacity) {
        this.readerId = readerId;
        this.readerName = readerName;
        this.readerPassword = readerPassword;
        this.readerSex = readerSex;
        this.readerType = readerType;
        Capacity = capacity;
    }

    public void setreaderId(int readerId) {

        this.readerId = readerId;
    }

}
