package GUI;

import DataBase.BookDB;
import Entity.User;

import javax.swing.*;
import java.sql.ResultSet;

public class QueryWindow extends JFrame {
    JTextField bookName;

    JButton query;

    JButton cancel;

    BookDB bookDB;

    JTextArea info;

    User user;

    public QueryWindow(User user) {
        this.user = user;
        setLayout(null);
        setTitle("查询界面");
        setDefaultCloseOperation(DISPOSE_ON_CLOSE);
        setBounds(300, 300, 700, 500);
        init();
        setVisible(true);
    }

    void init() {
        bookName = new JTextField();
        query = new JButton("查询");
        cancel = new JButton("取消");
        bookDB = new BookDB();
        info = new JTextArea();

        bookName.setBounds(0, 50, 100, 30);
        query.setBounds(0, 100, 100, 30);
        cancel.setBounds(0, 150, 100, 30);
        info.setBounds(0, 200, 300, 100);


        query.addActionListener(e -> {
            String bookName = QueryWindow.this.bookName.getText();
            try {
                ResultSet rs = bookDB.query(bookName);
                if (rs.next()) {
                    String ifo = "书名：" + rs.getString("book_name") + "\n" +
                            "类型：" + rs.getString("book_type") + "\n" +
                            "作者：" + rs.getString("book_author") + "\n" +
                            "价格：" + rs.getString("book_price") + "\n" +
                            "库存：" + rs.getString("book_num") + "\n";
                    info.setText(ifo);
                } else {
                    info.setText("查询失败");
                }
            } catch (Exception e1) {
                e1.printStackTrace();
            }
        });

        cancel.addActionListener(e -> {
            QueryWindow.this.dispose();
            new MainWindow(user);
        });


        this.add(bookName);
        this.add(query);
        this.add(cancel);
        this.add(info);
    }
}
