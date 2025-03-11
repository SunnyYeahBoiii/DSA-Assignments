## VQ44_FLOWERS

Bước đầu tiên là kiểm tra có bao nhiêu bông hoa phân biệt
Sau đó, chia ra 2 trường hợp là:
- Nếu số bông hoa phân biệt $\ge$ k thì in ra đúng $k$ màu phân biệt
- Nếu số bông hoa phân biệt $< k$ thì đầu tiên in ra mọi bông hoa phân biệt và xóa trên dãy ban đầu, sau đó in ra các phần tử sao cho output có đúng k số. 
## Point2D

Ta có thể tự viết một hàm Comparator để so sánh cho bài.

## VS_14_GIFTS

Vì bài toán là chọn $2$ món quà sao cho giá trị là lớn nhất nên ta sẽ tiếp cận theo hướng cố định món quà đầu tiên và tìm món quá thứ $2$ sao cho lớn nhất có thể.

Cụ thể hơn, nếu ta cố định món quà $1$ có giá trị $x$ thì món quà thứ $2$ bắt buộc phải $\le k - x$. Vì vậy bài toán của ta là tìm món quà lớn nhất sao cho món quà đó có giá trị $\le k - x$, sử dụng tìm kiếm nhị phân để giải.

## Password Strength

Ta chỉ cần làm theo đề bài yêu cầu, cụ thể hơn:
- Đếm số kí tự đặc biệt
- Đếm số lượng chữ số 
- Đếm số chữ cái in hoa 
- Đếm số chữ cái in thường
Và sau đó làm việc với các tham số được định nghĩa trong bài 

## Ceasar Cipher
Ta chỉ cần làm theo đề bài yêu cầu, duyệt qua mọi kí tự của xâu $S$ và gán $S_i = (S_i + k) \% 26$.

## Reversing Encryption
Ta chỉ cần làm theo đề bài yêu cầu, duyệt qua mọi ước của $N$ theo thứ tự từ bé đến lớn, với mỗi số thực hiện lệnh

$$Reverse(S.begin() , S.begin() + i)$$
Với $i$ là ước hiện tại của $N$.

## Messages

Ta sẽ duyệt qua mọi độ dài $i$ và kiểm tra $i$ kí tự cuối của xâu $S_b$ có tương đương với $i$ kí tự đầu của xâu $S_e$ hay không. Nếu có hãy lưu lại và sau đó xử lí kết quả với $i$ lớn nhất.

## Binary Search 1

Ta có thể chuyển đoạn Pseudo-Code dưới đề bài thành C++ và sau đó sử dụng một biến, gọi là $Cnt$, để đếm số lần duyệt trong hàm tìm kiếm nhị phân.

## Binary Search 2

Ta có thể tái sử dụng code bài Binary Search 1 và thay thế mảng số nguyên $A$ và số nguyên $x$ thành mảng xâu $A$ và xâu $x$. Sở dĩ ta có thể làm vậy là vì trong C++ đã có sẵn comparator cho string.

## Linear Search 1
Đầu tiên, tìm vị trí đầu tiên mà giá trị $x$ xuất hiện trong mảng $A$, gọi là $pos$.

Chia ra $2$ trường hợp:
- Không tồn tại giá trị $x$ trong mảng, in ra -1.
- Tồn tại giá trị $x$ trong mảng, in ra:
	+ $pos$
	+ $pos + 1$ 
	+ $n - pos$
	+ $n - pos + 1$

## Linear Search 2
Liệt kê các vị trí có giá trị bằng $x$ ra mảng $pos$.

Đầu tiên, in ra kích thước của $pos$.
Tiếp theo, với mỗi giá trị $x$, in ra $x$ và $x + 1$ trên $1$ dòng

## Linear Search 3

Ta sẽ dùng mảng đếm để duy trì $MEX$.

Với mỗi vị trí $i$, ta sẽ thêm $A_i$ và mảng đếm và tăng dần biến $MEX$ dựa vào mảng đếm của ta.

## Linear Search 5

Bài toán của ta là chia mảng thành $2$ dãy tuy nhiên ta chỉ nên tập trung vào phần tử nhỏ nhất và lớn nhất vì nó định nghĩa trọng số của 2 tập $S_1$ và $S_2$.

Cụ thể hơn, ta sẽ tìm phần tử lớn nhất và nhỏ nhất trong dãy hiện tại, lấy làm trọng số tập $S_1$, sau đó xóa $2$ phần tử đó trên mảng gốc. Và làm tương tự để tính trọng số tập $S_2$ với mảng đã xóa $2$ phần tử được chọn trong $S_1$.

## VW05p_Enrichement

Phát biểu lại bài toán, tìm bảng con $3 \times 3$ có tổng các phần tử nhỏ nhất. 

Vì vậy, ta sẽ duyệt qua mọi ô $(i , j)$ sao cho $i + 2 \le n , j + 2 \le m$ sau đó duyệt qua các ô trong hình chữ nhật $(i , j) \rightarrow (i + 2 , j + 2)$ và tính tổng sau đó lấy $min$ với kết quả.