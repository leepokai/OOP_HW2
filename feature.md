1. 使用紅黑樹實作降低時間複雜度
2. 加入 該本書的 有哪些屬性
3. 查詢該本書有被那些人借過 ，因此借書的人在借書的時候應該要說自己的 username 是誰
5. 我們以時間來做 排序然後再以 title 做排序
6. 然後我需要兩個 library 一個以 year 做排序一個以 title 做排序
7. 基本上我可以做 2 個 library，然後透過 title 為排序的 search 到 title 那本書然後找到對應的 year，達成 O(logn) 操作
8. 可以remove 掉圖書館的一本書


用什麼達成
3. 使用 AVL 來建立資料結構


額外 feature
1. 有書本對應的不同屬性
2. 所有操作皆可以 O(logn) 滿足
4. 紀錄所有讀過這本書的人以及借閱次數
5. 可以 remove 掉圖書館的這本書


HW2
Library management system
•Create a C++ program to manage a library using class
•The program should allow users to perform the following operations:
• Add a new book (-10 points)
• Search for a book by published year (-10 points)
• Check out a book (-10 points)
• Return a book (-10 points)
• List all books (-10 points)
• Exit (-10 points)
Add a new book
•Operation 1 – Add a new book to the library
•Users should be able to input book details such as published year,
author, and the number of available copies
•Each information should be stored in a data structure
Search for a book by published year
•Operation 2 – Search for a book by published year
•Users should be able to search for a book by published year
•The program should display the details of the book if it exists in the
library
•The results must be sorted in lexicographical order by the book's title
from smallest to largest
Check out a book
•Operation 3 – Check out a book.
•Allow users to borrow a book
•If the book is available, decrease the number of available copies
•If the book is not available, display a message indicating that the book
is checked out
Check out a book
Return a book
•Operation 4 – Return a book
•Users should be able to return a book they have borrowed
•Increase the number of available copies for the returned book
List all books
•Operation 5 - List all books
•Display a list of all the books in the library,
including their titles, authors, and the
number of available copies
•The results must be sorted in lexicographical
order by the book's title from smallest to
largest
Exit
•Operation 6 – Exit
•Exit the library system
Optional Enhancement
•You are allow to add additional book information, operation or even
visualize the system to enhanced the user experience
• Please describe the additional features clearly in your demo video and
especially in your report
•Example:
• Additional book information, such as genre, publisher, and overview
• Additional operation
• Search for a book by other book information
• Show the book overview
Limitations
•You can not use STL map, set, multimap and multiset to store book
information
•You must use class to implement your library system
• Please don’t use any other programming language or .exe files
• Please implement the sorting algorithm by yourself, you can’t use
<algorithm> library
Report
•The report should be clear and organized
•The report should describe how you fulfill the requirements
•Your report must include:
• What data structure do you store the book’s information? Provide a
explanation
• What algorithm is used to sort the books? Provide a explanation
• What algorithm is used to search for books? Provide a explanation
• Screenshots of all the required operations
•The file name should be named HW2_學號_學生名.pdf
Demo video
•You need to record all operations of your library system
•The video should be clear and demonstrate all you working operations
•The video should be no more than 5 minutes
•Editing is allowed (but faking your results is not allowed)
•The file name should be named HW2_學號_學生名
README File
• The README file should be clear and detailed
• The README file should describe how to use your library system
• Your README file must include the input format
• The file name should be named
OOPDS_HW2_學號_學生名.txt/.md
Scores and Submission
• The content will affect your grade
• Basic score: 75
• You might get a higher score (up to 100) if you successfully enhance your system
with other operations
• Delay / Copy = 0
• You can add a README file in the zip if you want
• Compress all your files into HW2_學號_學生名.zip (-20 points)
• Report (-10 points)
• Demo video (-10 points)
• Source code (-10 points)
• Uploaded onto E3 platform before 06/08 (Sun.) 11:55 pm