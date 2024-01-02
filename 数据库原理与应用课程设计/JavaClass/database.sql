create table book
(
    book_id     int auto_increment
        primary key,
    book_name   varchar(50) null,
    book_type   varchar(50) null,
    book_num    int         null,
    book_price  int         null,
    book_author varchar(30) null
);

create table user
(
    reader_id       int auto_increment
        primary key,
    reader_name     varchar(30) null,
    reader_password varchar(30) null,
    reader_sex      int         null,
    reader_type     int         null,
    reader_capacity int         null
);

create table borrow
(
    id        int auto_increment
        primary key,
    reader_id int null,
    book_id   int null,
    constraint borrow_book_id_fk
        foreign key (book_id) references book (book_id),
    constraint borrow_reader_id_fk
        foreign key (reader_id) references user (reader_id)
);

