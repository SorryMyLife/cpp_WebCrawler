//***********************************************
//*********			帮助部分			*********
//***********************************************

#include "tool.h"
void print(std::string str)
{
	std::cout << str << std::endl;
}


int c_len(char *ch)
{
	return sizeof(ch) / sizeof(ch[0]);
}
void he()
{
	print("         Crawler [options] [usage] : \n");
	print("         -O output : 将文件输出至指定路径(默认为当前路径)\n");
	print("         -u url : URLNAME : HOST 指定网络连接名称\n");
	print("         --no-del-tmp : not_delete_temp_file : 不删除程序产生的临时文件(这个功能调试程序时候用,默认删除临时文件)\n");
	print("         --get-html-url : 获取指定链接里的其他html连接(不保证能全部获取,默认不开启)\n");
	print("         --get-img-url : 获取指定链接里的图片链接(不保证能全部获取,默认不开启)\n");
	print("         -h help 列出所有可以用的选项以及说明\n");
	print("\n			默认的参数:Crawler REGEX RE_STRING URLNAME\n\n			REGEX : 由用户提供的正则进行匹配\n\n			RE_STRING : 由用户提供过滤的规则\n\n			URLNAME : 由用户提供的目标链接地址\n\n		以上参数不可缺少任何一个,否则可能会导致程序运行崩溃");
	print("\n			最少都要有两个或者两个以上的参数\n");
	print("\n         推荐参数: -O out_file -u url_name --get-html-url \n");
}
void er_p()
{
	print("请运行Crawler -h");
	exit(-1);
}
void no_p()
{
	print("不合法的参数规范!");
	exit(-1);
}
