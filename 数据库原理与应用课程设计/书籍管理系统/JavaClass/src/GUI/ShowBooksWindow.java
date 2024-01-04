package GUI;

import DataBase.BookDB;
import Entity.User;

import javax.swing.*;
import java.awt.*;
import java.sql.ResultSet;

public class ShowBooksWindow extends JFrame {
    JTextArea textArea;
    JButton cancel;
    User user;
    BookDB bookDB;

    public ShowBooksWindow(User user) {
        this.user = user;
        bookDB = new BookDB();
        setLayout(null);
        setTitle("书籍信息");
        setDefaultCloseOperation(DISPOSE_ON_CLOSE);
        setBounds(300, 300, 700, 500);
        init();
        setVisible(true);
    }

    public void init() {
        textArea = new JTextArea();
        cancel = new JButton("返回");

        textArea.setBounds(0, 20, 700, 300);
        cancel.setBounds(0, 350, 100, 30);
        textArea.setFont(new Font("宋体", Font.BOLD, 20));


        cancel.addActionListener(e -> {
            new MainWindow(user);
            ShowBooksWindow.this.dispose();
        });

        this.add(textArea);
        this.add(cancel);


        try (ResultSet rs = bookDB.getAllBooks()) {
            textArea.append("书名\t  类型\t  作者\t  价格\t  库存\n");
            while (rs.next()) {
                String ifo =""
                        + rs.getString("book_name") + "\t  "
                        + rs.getString("book_type") + "\t  "
                        + rs.getString("book_author") + "\t  "
                        + rs.getString("book_price") + "\t  "
                        + rs.getString("book_num") + "\n";
                textArea.append(ifo);
            }
        } catch (Exception e) {
            e.printStackTrace();
        }

    }

}
