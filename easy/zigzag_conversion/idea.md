已知条件：
	1.输入一个字符串，以'\0'结尾。
	2.将字符串转为r行锯齿形，再按行读出重新排序。
	3.锯齿排列的顺序为【从上到下，从左下到右上】。
	4.第一行和最后一行的字符数量是其他行的一半。
思路：
	找规律得出：同一行相邻两列的的数相差k = (2*(r-1))，
即每一行竖线上的数可表示为(R+nk)，而该竖线前的斜线上的
数可以表示为(-R+nk)，由此直接按上述公式计算下标，按行
填充新字符串，当下标越界时换行。