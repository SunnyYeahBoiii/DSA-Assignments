# Assignment 2 - Basic

## Task

Ta thấy bàn của Alice nằm tại vị trí $(p , q)$ để Bob ngồi đúng chỗ mà anh ấy muốn, ta hãy chuyển đổi $(p , q)$ thành vị trí của ô nếu như các bàn được liệt kê thành 1 dãy liên tục.

Khi đó, $(p , q)$ sẽ được chuyển thành $2 \cdot (p - 1) + q$, đặt là $t$ $(t = 2 \cdot (p - 1) + q)$. 

Ta có, bàn của Bob sẽ là bàn thứ $t - k$ hoặc $t + k$. Sau đó, ta chỉ cần kiểm tra nếu $t - k > 0$ và $t + k \le n$ và chọn bàn nhỏ nhất thì sẽ tìm được bàn của Bob.

## Point3D

Ta sẽ viết một comparator và sort lại sử dụng merge sort

## an.512.Trộn 2 mảng

Bài này để ta mô tả lại hàm merge.

## Find MEX

Ta sẽ sử dụng một mảng đếm $cnt[]$ để đếm các phần tử xuất hiện trong mảng $A$.

Lúc này, đáp án của ta là giá trị $x$ nhỏ nhất sao cho $cnt[x] = 0$.

## Point2D (template)

Ta làm y chang bài Point3D nhưng ta chỉ cần bỏ đi 1 chiều $z$.

## VU33_MaxStr

Ta sẽ xét các trường hợp như sau:
- Tổng các chữ số chia hết cho $3$, không làm gì
- Tổng các chữ số chia hết cho $3$ dư $1$, ta sẽ xóa theo thứ tự ưu tiên như sau:
	- Xóa đi $1$ chữ số nhỏ nhất chia $3$ dư $1$
	- Xóa đi $2$ chữ số nhỏ nhất chia $3$ dư $2$
- Tổng các chữ số chia hết cho $3$ dư $2$, ta sẽ xóa chữ số theo thứ tự ưu tiên như sau:
	- Xóa đi $1$ chữ số nhỏ nhất chia $3$ dư $1$
	- Xóa đi $2$ chữ số nhỏ nhất chia $3$ dư $2$

Sau đó, ta hãy sort lại toàn bộ string và in ra kết quả.

## VQ44_FLOWERS(template)

Bước đầu tiên của ta là đếm số bông hoa riêng biệt bằng cách sort hoặc bất cứ cách nào có thể.

Sau đó, chia ra 2 trường hợp là:
- Nếu số bông hoa phân biệt $\ge$ k thì in ra đúng $k$ màu phân biệt
- Nếu số bông hoa phân biệt $< k$ thì đầu tiên in ra mọi bông hoa phân biệt và xóa trên dãy ban đầu, sau đó in ra các phần tử sao cho output có đúng k số. 

## Kiểm Kê

Ta có thể sort lại và sau đó so sánh $a[i]$ và $a[i - 1]$. 

## Merge Sort - Insertion Sort - Bubble Sort - Selection Sort

4 bài này là ta mô phỏng lại thuật toán sắp xếp và sau đó in ra thay đổi trong từng bước.

# Assignment 2 - Advance

## MaxMinSum

Tóm tắt đề bài:

Tính tổng trọng số của mọi dãy con độ dài $k$ trong mảng ban đầu. Trong đó, trọng số của một dãy con là $Max - Min$.

Cách giải:
Để tính toán, ta sẽ tách riêng $Max$ và $Min$ trọng số ra và tính riêng biệt.

Với mỗi số $a_i$, ta sẽ tính có bao nhiêu dãy nhận $a_i$ đó là $Max$ và có nhiêu dãy nhận $a_i$ là $Min$. Cụ thể, nếu ta sort lại dãy ban đầu thì:
- Số dãy nhận $a_i$ là $Max$: $C_{i - 1}^{k - 1}$ 
- Số dãy nhận $a_i$ là $Min$: $C_{n - i}^{k - 1}$ 

Khi đó đáp án sẽ được cộng vào một giá trị là
$$a_i * C_{i - 1}^{k - 1} - a_i * C_{n - i}^{k - 1} $$

Kết hợp với phép đồng dư, ta có thể tính được đáp án cuối cùng.

## khangtd.Login1

Ta có thể sử dụng **map<string , string>** để lưu mật khẩu tương ứng với mỗi user.

## khangtd.Login2

Tương tự với Login1 nhưng thay vì phép gán thì ta sẽ cộng thêm mật khẩu mới vào sau value của key = username tương ứng.
## khangtd.DetectVirus + 2

Đây là bài toán cổ điển, có thể sử dụng **KMP** để giải quyết.

## Linear Search 4 

Tóm tắt đề bài:

Chia các số trong dãy thành $2$ nhóm sao cho mỗi số thuộc một nhóm hoặc không nhóm nào và mỗi nhóm phải có đúng $k$ số phân biệt.

Cách giải:

Gọi $T$ là số lượng phần tử phân biệt, ta sẽ xét các trường hợp sau:
- $T \ge 2 \cdot k$ , khi này in ra YES.
- $T < k$, khi này in ra NO.
- Ngược lại, ta sẽ xét kĩ hơn như sau:
	- Số giá trị xuất hiện nhiều hơn $1$ lần $\ge 2 \cdot K - T$, in ra YES.
	- Ngược lại, in ra NO.

## Vượt mức Pickleball 

Tóm tắt: 

Với các vị trí $i$ , $i > d$. Kiểm tra $2 \cdot MED(i - d , i - 1) \le a_i$ , trong đó $MED(i - d, i - 1)$ là trung vị trong đoạn $[i - d , i - 1]$.

Cách giải:

Ta sẽ giải bài toán này với độ phức tạp $O(N * 200)$

Cụ thể hơn, ta phải đi tìm $Median$, khi đó để ý giá trị của $a_i$ ($0 \le a_i \le 200$). Ta có thể dựa vào đây để khai thác.

Giả sử, ta có mảng đếm $cnt[]$ lưu lại số lần xuất hiện của các phần tử trong đoạn $[i - d , i - 1]$ (có thể sử dụng kĩ thuật 2 con trỏ). Ta có thể tìm $Median$ bằng cách duyệt qua mọi giá trị như sau:
- Nếu $d$ lẻ thì ta chỉ cần tìm giá trị $x$ nhỏ nhất sao cho $\sum_{i = 0}^{x} sum[i] \ge [\frac{d}{2}]$ và trả về $x$
- Nếu $d$ chẵn thì ta tìm thêm giá trị $y$ nhỏ nhất sao cho $\sum_{i = 0}^{y} sum[i] \ge [\frac{d}{2}] + 1$ và sau đó trả về $\frac{x + y}{2}$  

## Bốn ông điên 

Tóm tắt đề:

Tìm số lần swap 2 phần tử ít nhất sao cho dãy có thứ tự.

Cách giải:

Ở đây, ta sẽ làm theo thứ tự không giảm và sau đó reverse mảng ban đầu lại và làm tương tự để đưa ra kết quả.

Để tìm ra số thao tác ít nhất, ta sẽ làm như sau.

Gọi $id[i]$ là vị trí của phần tử $a[i]$ trong dãy nếu được sort theo thứ tự không giảm.

Khi đó, ta thấy việc $swap(i , id[i])$ là một thao tác để đưa dãy về trạng thái được sort. Tuy nhiên, việc làm như vậy sẽ tạo ra các vòng. Ví dụ như sau:

$N = 4$
$A = {5 , 20 , 13 , 2}$
$A_{sorted} = {2 , 5 , 13 , 20}$
$id = {2 , 4 , 3 , 1}$

Nếu liệt kê các phép swap:
- $swap(1 , 2)$
- $swap(2 , 4)$
- $swap(4 , 1)$
Thì các phép swap sẽ tạo thành một vòng đóng kín, tức trong trường hợp này ta chỉ cần thực hiện $2$ phép swap đầu thì phép swap thứ $3$ sẽ không cần thiết.

Tổng quát hóa, nếu ta tìm được một vòng $S$ có $|S|$ là kích thước của vòng thì cộng vào kết quả một lượng giá trị là $|S| - 1$.

Để giải bài này, ta có thể sử dụng **DFS**.

## Huấn luyện chuột

Tóm tắt đề:

Có $N$ chú chuột, hãy đếm số cách các chú chuột lấy thẻ sao cho các tấm thẻ tạo thành dãy không giảm.

Cách giải:

Đây là bài toán chia kẹo Euler. Cụ thể hơn 

gọi $x_i$ là số chú chuột lấy thẻ giá trị $i$. Khi đó:

$$
\begin{cases} 
x_1 + x_2 + ... + x_N = N \\ 
x_i \ge 0 
\end{cases}
$$
 Ta thấy công thức tính đáp án: 
 $$C^{N - 1}_{2 \cdot N - 1}$$
 Tuy nhiên, giới hạn đề bài cho $N$ là $N \le 10^{12}$, điều này khiến ta phải sử dụng Lucas Theorem để tính tổ hợp. Tóm lại, đáp án của ta là:
$$C^{K}_{N} \equiv \prod_{i = 0}^{m} C_{N_i}^{K_i}$$
$N = N_m N_{m-1} \dots N_1 N_0$
$K = K_m K_{m-1} \dots K_1 K_0$ 

Với $N_i$ và $K_i$ là chữ số trong biểu diễn cơ số $MOD$ của 2 số $N$ và $K$. 

